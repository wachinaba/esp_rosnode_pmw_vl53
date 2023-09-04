#include "Arduino.h"

#define TCAADDR 0x70

#include <string>

#include <Wire.h>
#include <SparkFun_VL53L5CX_Library.h>  //http://librarymanager/All#SparkFun_VL53L5CX

#include <ros.h>
#include <multizone_lidar_msgs/MultizoneRange.h>

/*
SparkFun_VL53L5CX imager1;
SparkFun_VL53L5CX imager2;
VL53L5CX_ResultsData measurement_data; // Result data class structure, 1356 byes of RAM

ros::NodeHandle nh;
multizone_lidar_msgs::MultizoneRange range_array1;
ros::Publisher range_array1_pub("multizone_range1", &range_array1);

multizone_lidar_msgs::MultizoneRange range_array2;
ros::Publisher range_array2_pub("multizone_range2", &range_array2);

int image_width = 8;
int image_resolution = image_width * image_width;

float horizontal_fov = 45.0 / 180.0 * M_PI;
float vertical_fov = horizontal_fov;

float horizontal_increment = horizontal_fov / image_width;
float vertical_increment = vertical_fov / image_width;

std::string frame_id = "lidar_frame";

void tcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

void setup_imager(SparkFun_VL53L5CX& imager) {
  imager.begin();
  imager.setResolution(image_resolution); //Set resolution to 8x8

  image_resolution = imager.getResolution(); //Query sensor for current resolution - either 4x4 or 8x8
  image_width = sqrt(image_resolution); //Calculate printing width

  //Using 4x4, min frequency is 1Hz and max is 60Hz
  //Using 8x8, min frequency is 1Hz and max is 15Hz
  bool response = imager.setRangingFrequency(15);
  if (response == true)
  {
    int frequency = imager.getRangingFrequency();
    if (frequency > 0)
    {
      Serial.print("Ranging frequency set to ");
      Serial.print(frequency);
      Serial.println(" Hz.");
    }
    else
      Serial.println(F("Error recovering ranging frequency."));
  }
  else
  {
    Serial.println(F("Cannot set ranging frequency requested. Freezing..."));
    while (1) ;
  }

  imager.startRanging();
}

void set_data(VL53L5CX_ResultsData& measurement_data, multizone_lidar_msgs::MultizoneRange& range_array) {
  for(int i=0; i<image_resolution; i++) {
    float distance = measurement_data.distance_mm[i] / 1000.0;
    range_array.ranges[i] = distance;
  }
}


void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("SparkFun VL53L5CX Imager Example");

  Wire.begin(); //This resets I2C bus to 100kHz
  Wire.setClock(1000000); //Sensor has max I2C freq of 1MHz

  tcaselect(0);
  setup_imager(imager1);

  tcaselect(1);
  setup_imager(imager2);

  //Set up ROS
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertise(range_array1_pub);
  nh.advertise(range_array2_pub);

  range_array1.ranges = (float*)malloc(sizeof(float) * image_resolution);
  range_array1.ranges_length = image_resolution;
  range_array1.header.frame_id = frame_id.c_str();
  range_array1.horizontal_fov = horizontal_fov;
  range_array1.vertical_fov = vertical_fov;
  range_array1.horizontal_samples = image_width;
  range_array1.vertical_samples = image_width;
  range_array1.min_range = 0.1;
  range_array1.max_range = 4.0;

  range_array2.ranges = (float*)malloc(sizeof(float) * image_resolution);
  range_array2.ranges_length = image_resolution;
  range_array2.header.frame_id = frame_id.c_str();
  range_array2.horizontal_fov = horizontal_fov;
  range_array2.vertical_fov = vertical_fov;
  range_array2.horizontal_samples = image_width;
  range_array2.vertical_samples = image_width;
  range_array2.min_range = 0.1;
  range_array2.max_range = 4.0;

}

void loop()
{
  //Poll sensor for new data
  tcaselect(0);
  if (imager1.isDataReady() == true)
  {
    if (imager1.getRangingData(&measurement_data)) //Read distance data into array
    {
      set_data(measurement_data, range_array1);
      range_array1.header.stamp = nh.now();
      range_array1_pub.publish(&range_array1);
      //nh.logerror("Published point cloud");
    }
  }

  tcaselect(1);
  if (imager2.isDataReady() == true)
  {
    if (imager2.getRangingData(&measurement_data)) //Read distance data into array
    {
      set_data(measurement_data, range_array2);
      range_array2.header.stamp = nh.now();
      range_array2_pub.publish(&range_array2);
      //nh.logerror("Published point cloud");
    }
  }

  nh.spinOnce();
  delay(1); //Small delay between polling
}
*/

#include "Arduino.h"

#include "PMW3901.h"

#include <ros.h>
#include <optical_flow_msgs/OpticalFlowDelta.h>

// Using digital pin 26 as chip select, but it can be any pin
PMW3901 flow(26);
ros::NodeHandle nh;
optical_flow_msgs::OpticalFlowDelta flow_msg;
ros::Publisher flow_pub("optical_flow_delta", &flow_msg);

void setup()
{
  Serial.begin(115200);
  delay(1000);

  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertise(flow_pub);

  if (!flow.begin())
  {
    Serial.println("Initialization of the flow sensor failed");
    while (1)
    {
    }
  }

  flow.setLed(true);
}

int16_t deltaX, deltaY;
uint8_t squal;

void loop()
{
  // Get motion count since last call
  flow.readMotionCount(&deltaX, &deltaY, &squal);

  /*
  Serial.print("X: ");
  Serial.print(deltaX);
  Serial.print(", Y: ");
  Serial.print(deltaY);
  Serial.print(", SQUAL: ");
  Serial.print(squal);
  Serial.print("\n");
  */

  flow_msg.header.stamp = nh.now();
  flow_msg.header.frame_id = "flow_frame";
  flow_msg.integration_time_us = 0;
  flow_msg.delta_px = deltaX;
  flow_msg.delta_py = deltaY;
  flow_msg.surface_quality = squal;

  flow_pub.publish(&flow_msg);
  nh.spinOnce();

  delay(100);
}
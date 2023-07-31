#include "Arduino.h"

#include "ros.h"
#include "mavros_msgs/OpticalFlowRad.h"

#include "PMW3901.h"

// Using digital pin 26 as chip select, but it can be any pin
PMW3901 flow(26);
ros::NodeHandle nh;
mavros_msgs::OpticalFlowRad flow_msg;
ros::Publisher flow_pub("optical_flow_rad", &flow_msg);

void setup() {
  Serial.begin(115200);

  if (!flow.begin()) {
    Serial.println("Initialization of the flow sensor failed");
    while(1) { }
  }

  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertise(flow_pub);
}

int16_t deltaX,deltaY;
uint8_t squal;

void loop() {
  // Get motion count since last call
  flow.readMotionCount(&deltaX, &deltaY, &squal);

  Serial.print("X: ");
  Serial.print(deltaX);
  Serial.print(", Y: ");
  Serial.print(deltaY);
  Serial.print(", SQUAL: ");
  Serial.print(squal);
  Serial.print("\n");

  flow_msg.header.stamp = nh.now();
  flow_msg.header.frame_id = "flow";
  flow_msg.integration_time_us = 0;
  flow_msg.integrated_x = deltaX;
  flow_msg.integrated_y = deltaY;
  flow_msg.integrated_xgyro = 0;
  flow_msg.integrated_ygyro = 0;
  flow_msg.integrated_zgyro = 0;
  flow_msg.temperature = 0;
  flow_msg.quality = squal;
  flow_msg.time_delta_distance_us = 0;
  flow_msg.distance = 0;

  flow_pub.publish(&flow_msg);
  nh.spinOnce();

  delay(100);
}

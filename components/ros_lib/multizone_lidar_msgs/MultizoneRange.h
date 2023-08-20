#ifndef _ROS_multizone_lidar_msgs_MultizoneRange_h
#define _ROS_multizone_lidar_msgs_MultizoneRange_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace multizone_lidar_msgs
{

  class MultizoneRange : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _horizontal_fov_type;
      _horizontal_fov_type horizontal_fov;
      typedef float _vertical_fov_type;
      _vertical_fov_type vertical_fov;
      typedef uint16_t _horizontal_samples_type;
      _horizontal_samples_type horizontal_samples;
      typedef uint16_t _vertical_samples_type;
      _vertical_samples_type vertical_samples;
      typedef float _min_range_type;
      _min_range_type min_range;
      typedef float _max_range_type;
      _max_range_type max_range;
      uint32_t ranges_length;
      typedef float _ranges_type;
      _ranges_type st_ranges;
      _ranges_type * ranges;

    MultizoneRange():
      header(),
      horizontal_fov(0),
      vertical_fov(0),
      horizontal_samples(0),
      vertical_samples(0),
      min_range(0),
      max_range(0),
      ranges_length(0), st_ranges(), ranges(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_horizontal_fov;
      u_horizontal_fov.real = this->horizontal_fov;
      *(outbuffer + offset + 0) = (u_horizontal_fov.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_horizontal_fov.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_horizontal_fov.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_horizontal_fov.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->horizontal_fov);
      union {
        float real;
        uint32_t base;
      } u_vertical_fov;
      u_vertical_fov.real = this->vertical_fov;
      *(outbuffer + offset + 0) = (u_vertical_fov.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vertical_fov.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vertical_fov.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vertical_fov.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertical_fov);
      *(outbuffer + offset + 0) = (this->horizontal_samples >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->horizontal_samples >> (8 * 1)) & 0xFF;
      offset += sizeof(this->horizontal_samples);
      *(outbuffer + offset + 0) = (this->vertical_samples >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertical_samples >> (8 * 1)) & 0xFF;
      offset += sizeof(this->vertical_samples);
      union {
        float real;
        uint32_t base;
      } u_min_range;
      u_min_range.real = this->min_range;
      *(outbuffer + offset + 0) = (u_min_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_range);
      union {
        float real;
        uint32_t base;
      } u_max_range;
      u_max_range.real = this->max_range;
      *(outbuffer + offset + 0) = (u_max_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_range);
      *(outbuffer + offset + 0) = (this->ranges_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ranges_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ranges_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ranges_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ranges_length);
      for( uint32_t i = 0; i < ranges_length; i++){
      union {
        float real;
        uint32_t base;
      } u_rangesi;
      u_rangesi.real = this->ranges[i];
      *(outbuffer + offset + 0) = (u_rangesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rangesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rangesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rangesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ranges[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_horizontal_fov;
      u_horizontal_fov.base = 0;
      u_horizontal_fov.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_horizontal_fov.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_horizontal_fov.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_horizontal_fov.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->horizontal_fov = u_horizontal_fov.real;
      offset += sizeof(this->horizontal_fov);
      union {
        float real;
        uint32_t base;
      } u_vertical_fov;
      u_vertical_fov.base = 0;
      u_vertical_fov.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vertical_fov.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vertical_fov.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vertical_fov.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vertical_fov = u_vertical_fov.real;
      offset += sizeof(this->vertical_fov);
      this->horizontal_samples =  ((uint16_t) (*(inbuffer + offset)));
      this->horizontal_samples |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->horizontal_samples);
      this->vertical_samples =  ((uint16_t) (*(inbuffer + offset)));
      this->vertical_samples |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->vertical_samples);
      union {
        float real;
        uint32_t base;
      } u_min_range;
      u_min_range.base = 0;
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_range = u_min_range.real;
      offset += sizeof(this->min_range);
      union {
        float real;
        uint32_t base;
      } u_max_range;
      u_max_range.base = 0;
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_range = u_max_range.real;
      offset += sizeof(this->max_range);
      uint32_t ranges_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ranges_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ranges_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ranges_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ranges_length);
      if(ranges_lengthT > ranges_length)
        this->ranges = (float*)realloc(this->ranges, ranges_lengthT * sizeof(float));
      ranges_length = ranges_lengthT;
      for( uint32_t i = 0; i < ranges_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_ranges;
      u_st_ranges.base = 0;
      u_st_ranges.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ranges.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ranges.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ranges.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ranges = u_st_ranges.real;
      offset += sizeof(this->st_ranges);
        memcpy( &(this->ranges[i]), &(this->st_ranges), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "multizone_lidar_msgs/MultizoneRange"; };
    virtual const char * getMD5() override { return "78785ff7f6a9cf044505c7f18ffc9a5e"; };

  };

}
#endif

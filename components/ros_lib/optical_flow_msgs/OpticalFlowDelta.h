#ifndef _ROS_optical_flow_msgs_OpticalFlowDelta_h
#define _ROS_optical_flow_msgs_OpticalFlowDelta_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace optical_flow_msgs
{

  class OpticalFlowDelta : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _integration_time_us_type;
      _integration_time_us_type integration_time_us;
      typedef float _delta_px_type;
      _delta_px_type delta_px;
      typedef float _delta_py_type;
      _delta_py_type delta_py;
      typedef uint8_t _surface_quality_type;
      _surface_quality_type surface_quality;

    OpticalFlowDelta():
      header(),
      integration_time_us(0),
      delta_px(0),
      delta_py(0),
      surface_quality(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->integration_time_us >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->integration_time_us >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->integration_time_us >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->integration_time_us >> (8 * 3)) & 0xFF;
      offset += sizeof(this->integration_time_us);
      union {
        float real;
        uint32_t base;
      } u_delta_px;
      u_delta_px.real = this->delta_px;
      *(outbuffer + offset + 0) = (u_delta_px.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delta_px.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delta_px.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delta_px.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delta_px);
      union {
        float real;
        uint32_t base;
      } u_delta_py;
      u_delta_py.real = this->delta_py;
      *(outbuffer + offset + 0) = (u_delta_py.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delta_py.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delta_py.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delta_py.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delta_py);
      *(outbuffer + offset + 0) = (this->surface_quality >> (8 * 0)) & 0xFF;
      offset += sizeof(this->surface_quality);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->integration_time_us =  ((uint32_t) (*(inbuffer + offset)));
      this->integration_time_us |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->integration_time_us |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->integration_time_us |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->integration_time_us);
      union {
        float real;
        uint32_t base;
      } u_delta_px;
      u_delta_px.base = 0;
      u_delta_px.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delta_px.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delta_px.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delta_px.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delta_px = u_delta_px.real;
      offset += sizeof(this->delta_px);
      union {
        float real;
        uint32_t base;
      } u_delta_py;
      u_delta_py.base = 0;
      u_delta_py.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delta_py.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delta_py.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delta_py.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delta_py = u_delta_py.real;
      offset += sizeof(this->delta_py);
      this->surface_quality =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->surface_quality);
     return offset;
    }

    virtual const char * getType() override { return "optical_flow_msgs/OpticalFlowDelta"; };
    virtual const char * getMD5() override { return "df08d94a64fbc01850df7dfb013eb400"; };

  };

}
#endif

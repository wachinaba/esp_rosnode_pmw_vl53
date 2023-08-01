set(COMPONENT_REQUIRES PMW3901 VL53L5CX ros_lib)
idf_component_register(SRCS "main.cpp"
                    INCLUDE_DIRS ".")

#include "rtc_types.h"

using namespace std;


tuple<float, float, float, float> make_point(float x, float y, float z){
    return make_tuple(x, y, z, 1.0);
}

std::tuple<float, float, float, float> make_vector(float x, float y, float z){
    return make_tuple(x, y, z, 0.0);
}
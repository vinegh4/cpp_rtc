#include "rtc_types.h"

#include <stdlib.h>

using namespace std;

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
 
// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

bool float_equal(float a, float b) {
  if (abs(a - b) < EPSILON)
    return true;

  return false;
}

rtc_tuple make_rtc_tuple(float a, float b, float c, float d) {
  return make_tuple(a, b, c, d);
}

rtc_tuple make_point(float x, float y, float z) {
  return make_rtc_tuple(x, y, z, 1.0);
}

rtc_tuple make_vector(float x, float y, float z) {
  return make_rtc_tuple(x, y, z, 0.0);
}

rtc_tuple tuples_add(rtc_tuple a, rtc_tuple b) {
  rtc_tuple res = make_rtc_tuple(get<0>(a) + get<0>(b), get<1>(a) + get<1>(b), 
      get<2>(a) + get<2>(b), get<3>(a) + get<3>(b));
  return res;
}

rtc_tuple tuples_sub(rtc_tuple a, rtc_tuple b) {
  rtc_tuple res = make_rtc_tuple(get<0>(a) - get<0>(b), get<1>(a) - get<1>(b),
      get<2>(a) - get<2>(b), get<3>(a) - get<3>(b));
  return res;
}

rtc_tuple tuple_negate(rtc_tuple a) {
  return make_rtc_tuple(get<0>(a) * -1.0, get<1>(a) * -1.0, get<2>(a) * -1.0, get<3>(a) * -1.0);
}

rtc_tuple tuple_mult(rtc_tuple a, float b) {
  return make_rtc_tuple(get<0>(a)*b, get<1>(a)*b, get<2>(a)*b, get<3>(a)*b);
}

rtc_tuple tuple_div(rtc_tuple a, float b) {
  return make_rtc_tuple(get<0>(a)/b, get<1>(a)/b, get<2>(a)/b, get<3>(a)/b);
}

float tuple_mag(rtc_tuple a) {
  return sqrt(powf(get<0>(a), 2) + powf(get<1>(a), 2) + powf(get<2>(a), 2) + powf(get<3>(a), 2));
}

rtc_tuple tuple_norm(rtc_tuple a) {
  float mag = tuple_mag(a);
  return make_rtc_tuple(get<0>(a)/mag, get<1>(a)/mag, get<2>(a)/mag, get<3>(a)/mag);
}

float tuples_dot(rtc_tuple a, rtc_tuple b) {
  return (get<0>(a) * get<0>(b) + get<1>(a) * get<1>(b) + get<2>(a) * get<2>(b) + get<3>(a) * get<3>(b));
}

rtc_tuple vectors_cross(rtc_tuple a, rtc_tuple b) {
  assertm(get<3>(a) == 0.0, "ERROR!: a cross product cannot be computed over points");
  assertm(get<3>(b) == 0.0, "ERROR!: a cross product cannot be computed over points");
  return make_vector(get<1>(a)*get<2>(b) - get<2>(a)*get<1>(b),
      get<2>(a)*get<0>(b) - get<0>(a)*get<2>(b),
      get<0>(a)*get<1>(b) - get<1>(a)*get<0>(b));
}


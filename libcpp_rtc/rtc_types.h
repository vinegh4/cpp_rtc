#include <tuple>

#define EPSILON 0.0001

using namespace std;

typedef tuple<float, float, float, float> rtc_tuple;

rtc_tuple make_rtc_tuple(float a, float b, float c, float d);
rtc_tuple make_point(float x, float y, float z);
rtc_tuple make_vector(float x, float y, float z);
rtc_tuple tuples_add(rtc_tuple a, rtc_tuple b);
rtc_tuple tuples_sub(rtc_tuple a, rtc_tuple b);
rtc_tuple tuple_negate(rtc_tuple a);
rtc_tuple tuple_mult(rtc_tuple a, float b);
rtc_tuple tuple_div(rtc_tuple a, float b);
float tuple_mag(rtc_tuple a);
rtc_tuple tuple_norm(rtc_tuple a);
float tuples_dot(rtc_tuple a, rtc_tuple b);

rtc_tuple vectors_cross(rtc_tuple a, rtc_tuple b);

bool float_equal(float a, float b);

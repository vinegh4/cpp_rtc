#include "rtc_types.h"
#include <gtest/gtest.h>
#include <tuple>

using namespace std;

TEST(TestMakePoint, BasicAssertions) {
  rtc_tuple a = make_rtc_tuple(4.0, -4.0, 3.0, 1.0);
  rtc_tuple b = make_point(4.0, -4.0, 3.0);
  EXPECT_EQ(a, b);
}

TEST(TestMakeVector, BasicAssertions) {
  rtc_tuple a = make_rtc_tuple(4.0, -4.0, 3.0, 0.0);
  rtc_tuple b = make_vector(4.0, -4.0, 3.0);
  EXPECT_EQ(a, b);
}

TEST(TestFloatEqual, BasicAssertions) {
  float a = 3.00005;
  float b = 3.00000;
  float c = 3.1;

  bool a_eq_b = float_equal(a, b);
  bool a_eq_c = float_equal(b, c);

  EXPECT_TRUE(a_eq_b);
  EXPECT_FALSE(a_eq_c);
}

TEST(TestTuplesAdd, BasicAssertions) {
  rtc_tuple a = make_rtc_tuple(3.0, -2.0, 5.0, 1.0);
  rtc_tuple b = make_rtc_tuple(-2.0, 3.0, 1.0, 0.0);
  rtc_tuple sum = tuples_add(a, b);
  rtc_tuple c = make_rtc_tuple(1.0, 1.0, 6.0, 1.0);
  EXPECT_EQ(c, sum);
}

TEST(TestTuplesSub, BasicAssertions) {
  rtc_tuple a = make_rtc_tuple(3.0, -2.0, 5.0, 1.0);
  rtc_tuple b = make_rtc_tuple(-2.0, 3.0, 1.0, 0.0);
  rtc_tuple sum = tuples_sub(a, b);
  rtc_tuple c = make_rtc_tuple(5.0, -5.0, 4.0, 1.0);
  EXPECT_EQ(c, sum);
}

TEST(TestSubPoints, BasicAssertions) {
  rtc_tuple a = make_point(3.0, 2.0, 1.0);
  rtc_tuple b = make_point(5.0, 6.0, 7.0);
  rtc_tuple sum = tuples_sub(a, b);
  rtc_tuple c = make_vector(-2.0, -4.0, -6.0);
  EXPECT_EQ(sum, c);
}

TEST(TestSubVectorFromPoint, BasicAssertions) {
  rtc_tuple a = make_point(3.0, 2.0, 1.0);
  rtc_tuple b = make_vector(5.0, 6.0, 7.0);
  rtc_tuple sum = tuples_sub(a, b);
  rtc_tuple c = make_point(-2.0, -4.0, -6.0);
  EXPECT_EQ(sum, c);
}

TEST(TestNegateTuple, BasicAssertions) {
  rtc_tuple a = make_rtc_tuple(1.0, -2.0, 3.0, -4.0);
  rtc_tuple b = make_rtc_tuple(-1.0, 2.0, -3.0, 4.0);
  EXPECT_EQ(tuple_negate(a), b);
}

TEST(TestTupleMult, BasicAssertions) {
  rtc_tuple a = make_rtc_tuple(1.0, -2.0, 3.0, -4.0);
  rtc_tuple b = make_rtc_tuple(3.5, -7.0, 10.5, -14.0);
  EXPECT_EQ(tuple_mult(a, 3.5), b);
}

TEST(TestTupleDiv, BasicAssertions) {
  rtc_tuple a = make_rtc_tuple(1.0, -2.0, 3.0, -4.0);
  rtc_tuple b = make_rtc_tuple(0.5, -1.0, 1.5, -2.0);
  EXPECT_EQ(tuple_div(a, 2.0), b);
}

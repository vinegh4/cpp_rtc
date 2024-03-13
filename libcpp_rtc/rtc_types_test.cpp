#include "rtc_types.h"
#include <gtest/gtest.h>

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
  EXPECT_EQ(tuple_div(a, 2.0), b); }

TEST(TestTupleMag, BasicAssertions) {
  rtc_tuple a = make_vector(0.0, 1.0, 0.0);
  rtc_tuple b = make_vector(0.0, 0.0, 1.0);
  rtc_tuple c = make_vector(1.0, 0.0, 0.0);
  rtc_tuple d = make_vector(1.0, 2.0, 3.0);
  rtc_tuple e = make_vector(-1.0, -2.0, -3.0);
  EXPECT_FLOAT_EQ(tuple_mag(a), 1.0);
  EXPECT_FLOAT_EQ(tuple_mag(b), 1.0);
  EXPECT_FLOAT_EQ(tuple_mag(c), 1.0);
  EXPECT_FLOAT_EQ(tuple_mag(d), sqrt(14.0));
  EXPECT_FLOAT_EQ(tuple_mag(e), sqrt(14.0));
}

TEST(TestTupleNorm, BasicAssertions) {
  rtc_tuple a = make_vector(4.0, 0.0, 0.0);
  rtc_tuple a_norm_test = make_vector(1.0, 0.0, 0.0);
  rtc_tuple a_norm = tuple_norm(a);
  rtc_tuple b = make_vector(1.0, 2.0, 3.0);
  rtc_tuple b_norm = tuple_norm(b);
  rtc_tuple b_norm_test = make_vector(0.26726, 0.53452, 0.80178);
  EXPECT_NEAR(get<0>(a_norm), get<0>(a_norm_test), 0.00001);
  EXPECT_NEAR(get<1>(a_norm), get<1>(a_norm_test), 0.00001);
  EXPECT_NEAR(get<2>(a_norm), get<2>(a_norm_test), 0.00001);
  EXPECT_NEAR(get<3>(a_norm), get<3>(a_norm_test), 0.00001);
  EXPECT_NEAR(get<0>(b_norm), get<0>(b_norm_test), 0.00001);
  EXPECT_NEAR(get<1>(b_norm), get<1>(b_norm_test), 0.00001);
  EXPECT_NEAR(get<2>(b_norm), get<2>(b_norm_test), 0.00001);
  EXPECT_NEAR(get<3>(b_norm), get<3>(b_norm_test), 0.00001);
  EXPECT_FLOAT_EQ(tuple_mag(b_norm), 1.0);
}

TEST(TestTuplesDot, BasicAssertions) {
  rtc_tuple a = make_vector(1.0, 2.0, 3.0);
  rtc_tuple b = make_vector(2.0, 3.0, 4.0);
  EXPECT_FLOAT_EQ(tuples_dot(a, b), 20.0);
}

TEST(TestVectorsCross, BasicAssertions) {
  rtc_tuple a = make_vector(1.0, 2.0, 3.0);
  rtc_tuple b = make_vector(2.0, 3.0, 4.0);
  rtc_tuple a_cross_b = vectors_cross(a, b);
  rtc_tuple b_cross_a = vectors_cross(b, a);
  rtc_tuple a_cross_b_test = make_vector(-1.0, 2.0, -1.0);
  rtc_tuple b_cross_a_test = make_vector(1.0, -2.0, 1.0);
  EXPECT_FLOAT_EQ(get<0>(a_cross_b), get<0>(a_cross_b_test));
  EXPECT_FLOAT_EQ(get<1>(a_cross_b), get<1>(a_cross_b_test));
  EXPECT_FLOAT_EQ(get<2>(a_cross_b), get<2>(a_cross_b_test));
  EXPECT_FLOAT_EQ(get<3>(a_cross_b), get<3>(a_cross_b_test));
  EXPECT_FLOAT_EQ(get<0>(b_cross_a), get<0>(b_cross_a_test));
  EXPECT_FLOAT_EQ(get<1>(b_cross_a), get<1>(b_cross_a_test));
  EXPECT_FLOAT_EQ(get<2>(b_cross_a), get<2>(b_cross_a_test));
  EXPECT_FLOAT_EQ(get<3>(b_cross_a), get<3>(b_cross_a_test));
}
  

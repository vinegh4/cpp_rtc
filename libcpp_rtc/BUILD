cc_library(
    name = "libcpp_rtc",
    srcs = ["rtc_types.cpp"],
    hdrs = ["rtc_types.h"]
)

cc_test(
    name = "libcpp_rtc_test",
    size = "small",
    srcs = ["rtc_types_test.cpp"],
    deps = ["@com_google_googletest//:gtest_main", "libcpp_rtc"], 
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "render-gl",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    includes = ["."],
    copts = ["-std=c++14"],
    deps = ["//src/core"],
    visibility = ["//visibility:public"]
)
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "core",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    includes = ["."],
    copts = ["-std=c++14"],
    deps = ["//third_party:glm"],
    visibility = ["//visibility:public"]
)
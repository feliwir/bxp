# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "bxp",
    srcs = ["main.cpp"],
    copts = ["-std=c++14"],
    deps = ["//src/core",
            "//src/render-gl",
            "//third_party:glfw"],
)
load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

cmake_external(
   name = "glfw",
   # Values to be passed as -Dkey=value on the CMake command line;
   # here are serving to provide some CMake script configuration options
   cache_entries = {
   },

   lib_name ="libglfw3",
   lib_source = "@glfw//:all",
   linkopts = select({
      "@bazel_tools//src/conditions:linux_x86_64" : [
         "-pthread",
         "-ldl",
         "-lGLU",
         "-lGL",
         "-lrt",
         "-lXcursor",
         "-lXrandr",
         "-lXxf86vm",
         "-lXi",
         "-lXinerama",
         "-lX11"]
   }),

   cmake_options = ["-G Ninja"],
   make_commands = ["ninja","ninja install"],
   visibility = ["//visibility:public"]
)


cmake_external(
   name = "glm",
   cache_entries = {
      "GLM_TEST_ENABLE" : "off",
   },

   headers_only = True,
   lib_source = "@glm//:all",
   visibility = ["//visibility:public"]
)
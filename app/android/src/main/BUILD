load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_android_library")
load("@rules_maven//:defs.bzl", "artifact")
load("//:versions.bzl", "versions", "targetSdkVersion")

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "native-glue",
    srcs = glob(["cpp/*.cpp"]),
)

android_library(
    name = "android-native-glue",
    exports = [":native-glue"]
)

android_library(
    name = "external_deps",
    exports = [
        artifact("androidx.collection:collection:" + versions["androidx"]),
        artifact("androidx.annotation:annotation:" + versions["androidx"]),
        artifact("androidx.drawerlayout:drawerlayout:" + versions["androidx"]),
        artifact("androidx.appcompat:appcompat:" + versions["androidx"]),
        artifact("androidx.core:core:" + versions["androidx"]),
        artifact("androidx.fragment:fragment:" + versions["androidx"]),
        artifact("androidx.legacy:legacy-support-v4:" + versions["androidx"]),
        artifact("androidx.lifecycle:lifecycle-viewmodel:" + versions["androidx-lifecycle"]),
        artifact("androidx.lifecycle:lifecycle-common:" + versions["androidx-lifecycle"]),
        artifact("androidx.lifecycle:lifecycle-runtime:" + versions["androidx-lifecycle"]),
    ],
)

kt_android_library(
    name = "lib",
    srcs = glob(["java/org/bxp/*.kt"]),
    custom_package = "org.bxp",
    resource_files = glob(["res/**"]) ,
    manifest = "AndroidManifest.xml",
    deps = [":android-native-glue",
            ":external_deps",
            ]
)

android_binary(
    name = "bxp",
    deps = [":lib"],
    manifest = "AndroidManifest.xml",
    resource_files = glob(["res/**"]),
    multidex = "native",
    manifest_values = {
      "minSdkVersion": "21",
      "applicationId": "org.bxp",
    }
)
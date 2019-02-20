workspace(name = "bxp")

# Generic rules we need
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
    name = "bazel_skylib",
    remote = "https://github.com/bazelbuild/bazel-skylib.git",
    tag = "0.7.0",  # change this to use a different release
)

# Android dependencies
android_sdk_repository(
    name = "androidsdk", # Required. Name *must* be "androidsdk".
    api_level=28,
)

android_ndk_repository(
    name = "androidndk", # Required. Name *must* be "androidndk".
    api_level=28,
)

git_repository(
    name = "io_bazel_rules_kotlin",
    remote = "https://github.com/bazelbuild/rules_kotlin.git",
    branch = "master"
)

load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kotlin_repositories", "kt_register_toolchains")
kotlin_repositories()
kt_register_toolchains()

RULES_MAVEN_COMMIT = "0.0.4"

http_archive(
    name = "rules_maven",
    strip_prefix = "rules_maven-%s" % RULES_MAVEN_COMMIT,
    url = "https://github.com/jin/rules_maven/archive/%s.zip" % RULES_MAVEN_COMMIT,
)

load("@rules_maven//:defs.bzl", "maven_install")
load("//:versions.bzl", "versions")

maven_install(
    artifacts = [
        "com.google.android.material:material:" + versions["material"],
        "androidx.appcompat:appcompat:" + versions["androidx"],
        "androidx.core:core:" + versions["androidx"],
        "androidx.collection:collection:" + versions["androidx"],
        "androidx.fragment:fragment:" + versions["androidx"],
        "androidx.lifecycle:lifecycle-viewmodel:" + versions["androidx-lifecycle"],
        "androidx.lifecycle:lifecycle-common:" + versions["androidx-lifecycle"],
        "androidx.lifecycle:lifecycle-runtime:" + versions["androidx-lifecycle"],
        "androidx.legacy:legacy-support-v4:" + versions["androidx"],

        # For biometric auth
        "android.arch.work:work-runtime:1.0.0-alpha01",
        "androidx.appcompat:appcompat:1.0.0-alpha1",
        "com.android.support:design:28.0.0-alpha1",
        #"com.an.biometric:biometric-auth:" + versions["biometry"], 
    ],
    repositories = [
        "https://jcenter.bintray.com/",
        "https://maven.google.com",
    ],
)

# External cmake dependencies
# Group the sources of the library so that CMake rule have access to it
all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

# Rule repository
http_archive(
   name = "rules_foreign_cc",
   strip_prefix = "rules_foreign_cc-master",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/master.zip",
)

load("@rules_foreign_cc//:workspace_definitions.bzl", "rules_foreign_cc_dependencies")
rules_foreign_cc_dependencies()

http_archive(
    name = "glfw",
    build_file_content = all_content,
    strip_prefix = "glfw-3.2.1",
    url = "https://github.com/glfw/glfw/archive/3.2.1.tar.gz"
)

http_archive(
    name = "glm",
    build_file_content = all_content,
    strip_prefix = "glm-0.9.9.3",
    url = "https://github.com/g-truc/glm/archive/0.9.9.3.tar.gz"
)
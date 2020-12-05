cc_binary(
    name = "grpc_3pi_sample",
    srcs = ["main.cc"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "@com_google_googleapis//google/bigtable/v2:bigtable_cc_grpc",
        "@com_google_googleapis//google/bigtable/v2:bigtable_cc_proto",
    ],
    linkopts = ["-l:libstdc++.a"],
    features = ["fully_static_link"],
)

load("@io_bazel_rules_docker//cc:image.bzl", "cc_image")

cc_image(
    name = "grpc_3pi_sample_image",
    binary = ":grpc_3pi_sample",
)
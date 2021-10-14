cc_binary(
    name = "grpc_3pi_sample",
    srcs = ["main.cc"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "@com_google_googleapis//google/bigtable/v2:bigtable_cc_grpc",
        "@com_google_googleapis//google/bigtable/v2:bigtable_cc_proto",
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
    ],
    features = ["fully_static_link"],
)
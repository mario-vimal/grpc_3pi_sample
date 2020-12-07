cc_binary(
    name = "main",
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
    name = "image",
    binary = ":main",
)

load(
    "@io_bazel_rules_docker//container:container.bzl",
    "container_pull",
    "container_push",
)

container_push(
   name = "push",
   image = ":image",
   format = "Docker",
   registry = "gcr.io",
   repository = "everythingisawesome8-6d551/grpc-app",
   tag = "v1",
)
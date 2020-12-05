workspace(name = "googleapis_grpc")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# http_archive(
#     name = "com_google_googleapis",
#     sha256 = "5e785c25b1d57973e7481b4da226d7c73056ea22c7545bf6d14dbebf6e99b073",
#     strip_prefix = "googleapis-59f97e6044a1275f83427ab7962a154c00d915b5",
#     urls = [
#         "https://github.com/googleapis/googleapis/archive/59f97e6044a1275f83427ab7962a154c00d915b5.tar.gz",
#     ],
# )

git_repository(
    name = "com_google_googleapis",
    remote = "https://github.com/googleapis/googleapis.git",
    branch = "master",
)

# http_archive(
#     name = "com_github_grpc_grpc",
#     sha256 = "0f330e4734f49d2bfdb9ad195b021720b5dd2e2a534cdf21c7ddc7f7eb42e170",
#     strip_prefix = "grpc-1.33.1",
#     urls = ["https://github.com/grpc/grpc/archive/v1.33.1.zip"],
# )

git_repository(
    name = "com_github_grpc_grpc",
    remote = "https://github.com/renkelvin/grpc.git",
    branch = "sample",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()

load("@com_google_googleapis//:repository_rules.bzl", "switched_rules_by_language")

switched_rules_by_language(
    name = "com_google_googleapis_imports",
    cc = True,
    grpc = True,
)

# Docker

http_archive(
    name = "io_bazel_rules_docker",
    sha256 = "1698624e878b0607052ae6131aa216d45ebb63871ec497f26c67455b34119c80",
    strip_prefix = "rules_docker-0.15.0",
    urls = ["https://github.com/bazelbuild/rules_docker/releases/download/v0.15.0/rules_docker-v0.15.0.tar.gz"],
)

load(
    "@io_bazel_rules_docker//repositories:repositories.bzl",
    container_repositories = "repositories",
)
container_repositories()

load(
    "@io_bazel_rules_docker//cc:image.bzl",
    _cc_image_repos = "repositories",
)

_cc_image_repos()

load(
    "@io_bazel_rules_docker//container:container.bzl",
    "container_pull",
)

container_pull(
  name = "java_base",
  registry = "gcr.io",
  repository = "distroless/java",
  # 'tag' is also supported, but digest is encouraged for reproducibility.
  digest = "sha256:deadbeef",
)
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
    remote = "https://github.com/grpc/grpc.git",
    branch = "master",
)

# local_repository(
#     name = "com_github_grpc_grpc",
#     path = "/Users/chuanr/Code/renkelvin/grpc",
# )

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

http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/98eb410c93ad059f9bba1bf43f5bb916fc92a5ea.zip"],
  strip_prefix = "abseil-cpp-98eb410c93ad059f9bba1bf43f5bb916fc92a5ea",
)
#include <iostream>
#include <string>

#include "grpcpp/grpcpp.h"
#include "google/bigtable/v2/bigtable.grpc.pb.h"

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

int main(int argc, char** argv) {
  absl::ParseCommandLine(argc, argv);
  std::string TABLE_NAME = "projects/wf-pools-testing/instances/instance/tables/table";
  auto creds = grpc::GoogleDefaultCredentials();
  auto server_name = "bigtable.googleapis.com";
  auto channel = grpc::CreateChannel(server_name, creds);
  std::unique_ptr<google::bigtable::v2::Bigtable::Stub>
      stub(google::bigtable::v2::Bigtable::NewStub(channel));
  google::bigtable::v2::MutateRowRequest req;
  req.set_table_name(TABLE_NAME);
  req.set_row_key("row_key_1");
  auto setCell = req.add_mutations()->mutable_set_cell();
  setCell->set_family_name("cf1");
  setCell->set_column_qualifier("column_qualifier_1");
  setCell->set_value("value_1");
  ClientContext context;
  google::bigtable::v2::MutateRowResponse resp;
  auto status = stub->MutateRow(&context, req, &resp);
  if (!status.ok()) {
    std::cerr << "Error in MutateRow() request: " << status.error_message()
              << " [" << status.error_code() << "] " << status.error_details()
              << std::endl;
  } else {
    std::cout << "Stored successfully!" << std::endl;
  }
  return 0;
}
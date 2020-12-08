#include <iostream>
#include <string>

#include "grpcpp/grpcpp.h"
#include "google/bigtable/v2/bigtable.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

#define TABLE_NAME "projects/everythingisawesome8-6d551/instances/grpc-3pi-test/tables/grpc-table"
#define ROW_KEY "row_key_1"
#define FAMILY_NAME "cf1"
#define COLUMN_QUALIFIER "column_qualifier"
#define VALUE "value"

int main(int argc, char** argv) {
  auto creds = grpc::GoogleDefaultCredentials();
  auto server_name = "bigtable.googleapis.com";
  auto channel = grpc::CreateChannel(server_name, creds);
  std::unique_ptr<google::bigtable::v2::Bigtable::Stub>
      stub(google::bigtable::v2::Bigtable::NewStub(channel));
  google::bigtable::v2::MutateRowRequest req;
  req.set_table_name(TABLE_NAME);
  req.set_row_key(ROW_KEY);
  auto setCell = req.add_mutations()->mutable_set_cell();
  setCell->set_family_name(FAMILY_NAME);
  setCell->set_column_qualifier(COLUMN_QUALIFIER);
  setCell->set_value(VALUE);
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
  while (true)
  {
    /* code */
  }
  return 0;
}
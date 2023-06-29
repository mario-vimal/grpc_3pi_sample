#include <iostream>
#include <string>

#include "grpc/grpc.h"
#include "grpc++/grpc++.h"
#include "grpc/grpc_security.h"
#include "google/storage/v2/storage.grpc.pb.cc"
#include "google/bigtable/v2/bigtable.grpc.pb.h"

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

int main(int argc, char **argv)
{
  absl::ParseCommandLine(argc, argv);
  std::string TABLE_NAME = "projects/wf-pools-testing/instances/instance/tables/table";
  const char *url_options_string = "";
  const char *url_scopes_string = "https://www.googleapis.com/auth/cloud-platform";
  std::cout << "creating external acc creds! \n";
  grpc::ExternalAccountCredentials(url_options_string, {"scope1"});
  auto creds = grpc_external_account_credentials_create(url_options_string, url_scopes_string);
  std::cout << "external acc creds created! \n";
  auto downscoped_creds = grpc::DownscopedCredentials(creds, url_options_string);
  // auto channel = grpc::CreateChannel("storage.googleapis.com", grpc::InsecureChannelCredentials());
  // std::unique_ptr<google::storage::v2::Storage::Stub> stub(google::storage::v2::Storage::NewStub(channel));
  // google::storage::v2::ListBucketsRequest req;
  // ClientContext context;
  // context.set_credentials(downscoped_creds);
  // google::storage::v2::ListBucketsResponse res;
  // auto status = stub->ListBuckets(&context, req, &res);
  // if(!status.ok()) {
  //   std::cout<<status.error_message()<<"\n"<<status.error_details()<<"\n";
  // }

  auto server_name = "bigtable.googleapis.com";
  auto channel = grpc::CreateChannel(server_name, downscoped_creds);
  // auto channel = grpc::CreateChannel(server_name, grpc::CompositeChannelCredentials(grpc::GoogleDefaultCredentials(), downscoped_creds));
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
  // context.set_credentials(downscoped_creds);
  google::bigtable::v2::MutateRowResponse resp;
  auto status = stub->MutateRow(&context, req, &resp);
  if (!status.ok())
  {
    std::cerr << "Error in MutateRow() request: " << status.error_message()
              << " [" << status.error_code() << "] " << status.error_details()
              << std::endl;
  }
  else
  {
    std::cout << "Stored successfully!" << std::endl;
  }
  return 0;
}
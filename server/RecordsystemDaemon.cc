#include "RecordsystemDaemon.h"

#include <echoservice.pb.h>
#include <google/protobuf/rpc/rpc_server.h>
#include <google/protobuf/rpc/rpc_client.h>

class EchoService: public service::EchoService {
public:
	inline EchoService() {}
	virtual ~EchoService() {}

	virtual const ::google::protobuf::rpc::Error Echo(const ::service::EchoRequest* args, ::service::NullResponse* reply) {
		printf("%s: %s", args->GetTypeName().c_str(), args->msg().c_str());
		return ::google::protobuf::rpc::Error::Nil();
	}
};

int main(int argc, char **argv) {
	::google::protobuf::rpc::Server server;
	server.AddService(new EchoService(), true);
	server.BindAndServe(1234);

	return 0;
}
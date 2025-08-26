package main

import(
	"log"
	"context"

	pb "github.com/nelson-araujo/na-sand/go/grpc/client-server-example/proto"
)

func (svr *Server) ClientStatusResponse(ctx context.Context, in *pb.ClientStatusRequestMessage, opts ...grpc.CallOption) (*pb.ClientStatusResponseMessage, error){
	log.Printf("ClientStatusResponse function was invoked with %v\n", in)	
	
	return &pb.ClientStatusResponse{
  	// Client fields
  	client_name = "client-101"
  	client_iana_timezone = "America/Los_Angeles"
  	client_uptime_minutes = 102
  	client_cpu_use = 103
  	client_memory_use = 104
  	client_disk_use = 105
  	client_net_use = 106
  	client_status_messages = "107"

  	// Device fields
  	device_name = "device-200"
  	device_iana_timezone = "America/Los_Angeles"
  	device_uptime_minutes = 202
  	device_cpu_use = 203
  	device_memory_use = 204
  	device_disk_use = 205
  	device_net_use = 206
	device_status_messages = "207"
	}, nil
}

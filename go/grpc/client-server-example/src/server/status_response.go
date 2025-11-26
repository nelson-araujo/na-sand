package main

import (
	"context"
	"log"

	pb "github.com/nelson-araujo/na-sand/go/grpc/client-server-example/proto"
	"google.golang.org/grpc"
)

func (svr *Server) StatusResponse(ctx context.Context, in *pb.StatusRequestMessage, opts ...grpc.CallOption) (*pb.StatusResponseMessage, error) {
	log.Printf("ClientStatusResponse function was invoked with %v\n", in)

	return &pb.StatusResponseMessage{
		//MsgDatetimeUtc = ""
		//
		//// Client fields
		//ClientName = "100"
		//ClientIanaTimezone = "101"
		//ClientUptimeMinutes = 102
		//ClientCpuUse = 103
		//Client_MemoryUse = 104
		//ClientDiskUse = 105
		//ClientNetUse = 106
		//ClientStatusMessages = "107"
		//
		//// Device fields
		//DeviceName = "200"
		//DeviceIanaTimezone = "201"
		//DeviceUptimeMinutes = 202
		//DeviceCpuUse = 203
		//DeviceMemoryUse = 204
		//DeviceDiskUse = 205
		//DeviceNetUse = 206
		//DeviceStatusMessages = "207"

		//// Client fields
		//client_name = "client-101"
		//client_iana_timezone = "America/Los_Angeles"
		//client_uptime_minutes = 102
		//client_cpu_use = 103
		//client_memory_use = 104
		//client_disk_use = 105
		//client_net_use = 106
		//client_status_messages = "107"
		//
		//// Device fields
		//device_name = "device-200"
		//device_iana_timezone = "America/Los_Angeles"
		//device_uptime_minutes = 202
		//device_cpu_use = 203
		//device_memory_use = 204
		//device_disk_use = 205
		//device_net_use = 204
		//device_status_messages = "207"
	}, nil
}

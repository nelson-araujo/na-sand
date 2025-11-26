package main

import (
	"log"

	pb "github.com/nelson-araujo/na-sand/go/grpc/client-server-example/proto"
)

func doStatusResponse(grpcClient pb.StatusResponseServiceClient) {
	log.Println("[DEV ] doStatusResponse was invoked")

	//response, err := grpcClient.StatusResponse(context.Background())
}

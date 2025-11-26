package main

import (
	"log"
	"net"

	pb "github.com/nelson-araujo/na-sand/go/grpc/client-server-example/proto"

	"google.golang.org/grpc"
)

var svr_addr = "127.0.0.1:50051"

type Server struct {
	pb.StatusServiceServer
}

func main() {

	lis, err := net.Listen("tcp", svr_addr)
	if err != nil {
		log.Fatalf("Failed to start listening on %v\n", err)
	}

	log.Printf("Listening on %s\n", svr_addr)
	log.Println("Press CTRL+c to close")

	svr := grpc.NewServer()
	pb.RegisterStatusServiceServer(svr, &Server{})

	if err = svr.Serve(lis); err != nil {
		log.Fatalf("Failed to server: %v\n", err)
	}

}

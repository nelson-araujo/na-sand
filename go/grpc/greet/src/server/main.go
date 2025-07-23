package main

import (
	"fmt"
	"google.golang.org/grpc"
	"log"
	"net"

	pb "nelsonaraujo.com/na-sand/go/grpc/greet/proto"
)

type Server struct {
	pb.GreetServiceServer
}

func main() {

	svr_hostname := "localhost"
	svr_port := "50051"
	var svr_addr string = svr_hostname + ":" + svr_port

	// Setup listener
	lis, err := net.Listen("tcp", svr_addr)
	if err != nil {
		log.Fatal("Failed to start listening on ", err)
	}

	log.Println("Listening on ", svr_addr)

	fmt.Println("svr_addr: ", svr_addr)

	svr := grpc.NewServer()
	if err = svr.Serve(lis); err != nil {
		log.Fatalf("Failed to server: %v\n", err)
	}

}

package main

import(
	"log"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure" // run grpc insecure
)

var svr_addr = "localhost:50051"

func main(){
	log.Printf("Connecting to %v\n", svr_addr)	

	// TODO: Create proper credentials to use SSL
	conn, err := grpc.Dial(svr_addr, grpc.WithTransportCredentials(insecure.NewCredentials()))

		if err != nil {
		log.Fatalf("Failed to connect: %v\n", err)
	}

	// Close the connection at the end of the function
	defer conn.Close()

}

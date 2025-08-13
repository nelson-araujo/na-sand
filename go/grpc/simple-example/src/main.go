package main

import (
	"fmt"

	pb "github.com/nelson-araujo/na-sand/go/grpc/simple-example/proto"
)

func doSimple() *pb.Simple {
	return &pb.Simple{
		Id: 42,
		IsSimple: true,
		Name: "My Name",
		SampleLists: []int32{1,2,3,4,5,6},
	}

}

func main(){
	fmt.Println ("Running...")
	fmt.Println(doSimple())
}

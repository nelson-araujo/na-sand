MODULE = nelsonaraujo.com/na-sand/go/grpc/greet
FILE = dummy.proto

default:
	protoc --go_out=../ --go_opt=module=$(MODULE) --go-grpc_out=../ --go-grpc_opt=module=$(MODULE) $(FILE)

clean: 
	rm *.pb.go

help:
	@echo "make: compile ${FILE}"
	@echo "make clean: delete all .pb.go files"

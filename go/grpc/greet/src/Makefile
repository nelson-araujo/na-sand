BIN_DIR = ../bin
PROTO_DIR = ./proto

MODULE = nelsonaraujo.com/na-sand/go/grpc/greet
PROTO_FILE = $(PROTO_DIR)/greet.proto
SERVER_FILE = server/main.go
CLIENT_FILE = client/main.go

.PHONY: default proto server client all clear-all

default:
	@echo "make all: compile all files"
	@echo "make proto: compile the proto file"
	@echo "make server: compile the server only"
	@echo "make client: compile the client only"
	@echo "make clear-all: Delete all compiled files"

proto:
	protoc --go_out=$(PROTO_DIR) --go_opt=module=$(MODULE) --go-grpc_out=$(PROTO_DIR) --go-grpc_opt=module=$(MODULE) $(PROTO_FILE)

server:
	go build -o $(BIN_DIR)/server $(SERVER_FILE) 

client:
	go build -o $(BIN_DIR)/client $(CLIENT_FILE)

all:
	protoc --go_out=$(PROTO_DIR) --go_opt=module=$(MODULE) --go-grpc_out=$(PROTO_DIR) --go-grpc_opt=module=$(MODULE) $(PROTO_FILE)
	go build -o $(BIN_DIR)/server $(SERVER_FILE) 
	go build -o $(BIN_DIR)/client $(CLIENT_FILE)

clear-all:
	rm $(PROTO_DIR)/*.go
	rm $(BIN_DIR)/*

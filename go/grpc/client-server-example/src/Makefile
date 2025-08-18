# directories
BIN_DIR = ../bin
PROTO_DIR = ./proto

# File locations
MODULE = github.com/nelson-araujo/na-sand/go/grpc/client-server-example
PROTO_FILE = $(PROTO_DIR)/client-server-example.proto
SERVER_FILE = server/server.go
CLIENT_FILE = client/client.go

# Terminal text modifiers
BOLD := $(shell tput bold)
NORMAL := $(shell tput sgr0)

# Identify the actions that don't generate files to monitor
.PHONY: default proto server client all clear-all

# Default action that will list all the available flags
default:
	@printf "$(BOLD)Available Flags$(NORMAL)\n"
	@echo "make all:\t Compile all files"
	@echo "make proto:\t Compile the proto file"
	@echo "make server:\t Compile the server only"
	@echo "make client:\t Compile the client only"
	@echo "make clear-all:\t Delete all gRPC compiled files and all files in '$(BIN_DIR)'"

# Generate the proto files
proto:
	protoc --go_out=$(PROTO_DIR) --go_opt=module=$(MODULE) --go-grpc_out=$(PROTO_DIR) --go-grpc_opt=module=$(MODULE) $(PROTO_FILE)

# Compile the server application
server:
	go build -o $(BIN_DIR)/server $(SERVER_FILE)

# Compile the client application
client:
	go build -o $(BIN_DIR)/client $(CLIENT_FILE)

# Compile all
all: proto server client
	#protoc --go_out=$(PROTO_DIR) --go_opt=module=$(MODULE) --go-grpc_out=$(PROTO_DIR) --go-grpc_opt=module=$(MODULE) $(PROTO_FILE)
	#go build -o $(BIN_DIR)/server $(SERVER_FILE)
	#go build -o $(BIN_DIR)/client $(CLIENT_FILE)
	@echo "Generated the proto files along with the server and client binaries"

# Delete the generated proto files and delete all files in the bin directory
clear-all:
	rm $(PROTO_DIR)/*.go
	rm $(BIN_DIR)/*

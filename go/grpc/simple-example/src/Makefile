# directories
BIN_DIR = ../bin
PROTO_DIR = ./proto

# File locations
MODULE = github.com/nelson-araujo/na-sand/go/grpc/simple-example
PROTO_FILE = $(PROTO_DIR)/simple-example.proto
APP_FILE = main.go

# Terminal text modifiers
BOLD := $(shell tput bold)
NORMAL := $(shell tput sgr0)

# Identify the actions that don't generate files to monitor
.PHONY: default proto server client all clear-all

# Default action that will list all the available flags
default:
	@printf "$(BOLD)Available Flags$(NORMAL)\n"
	@echo "make all:\t Generate and compile all files"
	@echo "make proto:\t Generate the proto file(s)"
	@echo "make app:\t Compile application binaries"
	@echo "make clear-all:\t Delete all gRPC compiled files and all files in '$(BIN_DIR)'"

# Generate the proto files
proto:
	protoc --go_out=$(PROTO_DIR) --go_opt=module=$(MODULE) --go-grpc_out=$(PROTO_DIR) --go-grpc_opt=module=$(MODULE) $(PROTO_FILE)

# Compile the application
app:
	go build -o $(BIN_DIR)

# Compile all
all: proto app 
	@echo "Generated the proto file(s) and all binaries"

# Delete the generated proto files and delete all files in the bin directory
clear-all:
	rm $(PROTO_DIR)/*.go
	rm $(BIN_DIR)/*

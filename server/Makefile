proto-build:
	protoc \
	    -I $(shell git rev-parse --show-toplevel)/protos \
	    --go_out=$(shell git rev-parse --show-toplevel)/protos --go_opt=paths=source_relative \
	    --go-grpc_out=$(shell git rev-parse --show-toplevel)/protos --go-grpc_opt=paths=source_relative \
	    $(shell git rev-parse --show-toplevel)/protos/route_guide.proto

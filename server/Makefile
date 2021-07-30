BINARY=server

# Proto sources
PROTOC=protoc
PROTO=$(shell find $(shell git rev-parse --show-toplevel) -type f -name '*.proto')
PBGO=$(PROTO:.proto=.pb.go)
PROTODIR=$(shell git rev-parse --show-toplevel)/protos
PROTO_GOMOD_FILE=${PROTODIR}/go.mod

.PHONY: clean install proto gomod protobuf_go_plugin grpc_go_plugin

build: proto gomod
	go build ${LDFLAGS} -o ${BINARY} main.go

proto: $(PBGO)

%.pb.go: %.proto | $(PROTOBUF_GO_PLUGIN) $(GRPC_GO_PLUGIN) $(DEST_DIR)
	${PROTOC} --proto_path=${PROTODIR} \
	--go_out=${PROTODIR} --go_opt=paths=source_relative \
	--go-grpc_out=${PROTODIR} --go-grpc_opt=paths=source_relative \
	$<

install: protobuf_go_plugin grpc_go_plugin

protobuf_go_plugin:
	go install google.golang.org/protobuf/cmd/protoc-gen-go@v1.26

grpc_go_plugin:
	go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@v1.1

gomod: ${PROTO_GOMOD_FILE}

${PROTO_GOMOD_FILE}:
	cd ${PROTODIR} && go mod init && go mod tidy


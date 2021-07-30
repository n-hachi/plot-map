module github.com/n-hachi/plot-map/server

go 1.16

require (
	github.com/n-hachi/plot-map/protos v0.0.0-00010101000000-000000000000
	google.golang.org/grpc v1.39.0
)

replace github.com/n-hachi/plot-map/protos => ./../protos

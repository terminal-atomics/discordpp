#!/bin/bash

if ! sudo apt-get update || ! sudo apt-get install -y libc++-dev libcurl4-openssl-dev; then
	echo "Could not install with APT"
	./tools/compile-libcurl.sh > log_output
	./tools/install-json.sh >> log_output
	./tools/install-websocketpp.sh >> log_output
else
	echo "Updated with APT"
fi
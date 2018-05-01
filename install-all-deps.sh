#!/bin/bash

if ! sudo apt-get update || ! sudo apt-get install -y libc++-dev libcurl4-openssl-dev; then
	echo "Could not install with APT"
	./tools/compile-libcurl.sh
	./tools/install-json.sh
	./tools/install-websocketpp.sh
else
	echo "Updated with APT"
fi
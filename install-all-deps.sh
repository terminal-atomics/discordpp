#!/bin/bash

./tools/install-json.sh >> log_output
./tools/install-websocketpp.sh >> log_output

if ! sudo apt-get update || ! sudo apt-get install -y libc++-dev libssl-dev libboost-all-dev; then
	echo "Could not install with APT"
else
	echo "Updated with APT"
fi
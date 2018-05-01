#!/bin/bash

echo "Downloading websocketpp tarball..."
wget https://github.com/zaphoyd/websocketpp/archive/0.7.0.tar.gz
echo "Untar the tarball..."
tar xzvf 0.7.0.tar.gz
echo "Removing the tarball."
rm -fv 0.7.0.tar.gz
echo "Copying files..."
cp -rv websocketpp-0.7.0/websocketpp include/
echo "Removing the folder..."
rm -rfv websocketpp-0.7.0/


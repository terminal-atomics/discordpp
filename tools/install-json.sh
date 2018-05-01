#!/bin/bash

cd include/
mkdir nlohmann
cd nlohmann/
echo "Downloading json"
wget https://github.com/nlohmann/json/releases/download/v3.1.2/json.hpp
cd ../../
echo "Done !"
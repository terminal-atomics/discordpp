#!/bin/bash
FOLDER=$PWD
echo "Installation at : "
echo $FOLDER
sleep 1
echo
echo "Downloading libcurl..."
wget https://curl.haxx.se/download/curl-7.59.0.tar.gz
echo "Untar libcurl..."
tar xzvf curl-7.59.0.tar.gz
echo "Deletion of the libcurl tarball..."
rm -fv curl-7.59.0.tar.gz
echo "Entering libcurl folder."
cd curl-7.59.0/
echo "Configuring compilation"
./configure --prefix=$FOLDER --disable-shared
echo "Compiling..."
make -j4
echo "Installing..."
make install
cd ..
echo "Deletion of libcurl folder."
rm -rfv curl-7.59.0/
echo "Deletion of unnecessary lib files"
rm -rfv lib/pkgconfig/
rm -fv lib/libcurl.la
rm -rfv share/
echo "Done !"

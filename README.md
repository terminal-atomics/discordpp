# discordpp

An efficient library that interfaces with the Discord API.

## Version

Alpha 0.1.0 WIP

The library should not be used at its current stage of development.

## Building

### Static library

First execute `bash tools/compile-libcurl.sh`, make sure to have `libssl-dev`
You will have to link the lib/libcurl.a -lz, -lpthread and $(pkg-config--libs openssl) in your final program if you use.

### Dynamic library

Just link with the .so

## License

MIT (SEE LICENSE)
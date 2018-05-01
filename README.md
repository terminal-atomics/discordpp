# discordpp

An efficient library that interfaces with the Discord API.

## Version

Alpha 0.1.0 WIP

The library should not be used at its current stage of development.

## Building

Build with flag `$(pkg-config --cflags openssl)`
Link your final program with `-Wl,-Bstatic -lboost_thread -lboost_system -Wl,-Bdynamic -lpthread $(pkg-config --libs openssl)`.

## License

MIT (SEE LICENSE)
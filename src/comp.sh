g++ -c main.cpp -o ../build/main.o -I../include --std=c++11 $(pkg-config --cflags openssl)
g++ -c libs/urler.cpp -o ../build/urler.o -I../include --std=c++11 -Werror $(pkg-config --cflags openssl)
g++ -c libs/discord_http.cpp -o ../build/discord_http.o -I../include --std=c++11 -Werror $(pkg-config --cflags openssl)
g++ ../build/main.o ../build/urler.o ../build/discord_http.o -o ../build/discordpp -Wl,-Bstatic -lboost_thread -lboost_system -Wl,-Bdynamic -lpthread $(pkg-config --libs openssl)

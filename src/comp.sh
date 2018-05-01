g++ -c main.cpp -o main.o -I../include --std=c++11 $(pkg-config --cflags openssl)
g++ -c urler.cpp -o urler.o -I../include --std=c++11 -Werror $(pkg-config --cflags openssl)
g++ -c discord_http.cpp -o discord_http.o -I../include --std=c++11 -Werror $(pkg-config --cflags openssl)
g++ main.o urler.o discord_http.o -o l -Wl,-Bstatic -lboost_thread -lboost_system -Wl,-Bdynamic -lpthread $(pkg-config --libs openssl)

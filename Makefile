CC = g++
RM = rm
AR = ar
CP = cp
MKDIR = mkdir

CC_FLAGS = -W -Wextra -std=c++11
LD_FLAGS =

LINKABLE = ./bin/discordpp-0_1_0.a

INCLUDES = -I./include

# THESE SHOULD NOT BE EDITED
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, $(SOURCES))

.PHONY: clean

.SUFFIXES:

all: dirs $(LINKABLE)

dirs: bin/ build/

bin/:
	$(MKDIR) $@

build/:
	$(MKDIR) $@

$(LINKABLE): $(OBJECTS)
	$(AR) -rv $@ $^

build/%.o: src/%.cpp
	$(CC) -c $< $(INCLUDES) -o $@ $(CC_FLAGS)

clean:
	$(RM) -rf build/*.o
	$(RM) -rf bin/*

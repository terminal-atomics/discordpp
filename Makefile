CC = g++
RM = rm
AR = ar
CP = cp
MKDIR = mkdir

CC_FLAGS = -W -Wextra -std=c++11 -fPIC
LD_FLAGS = -fPIC
DEFINES =

LINKABLE = ./bin/discordpp-0_1_0.a
DLINKABLE = ./bin/discordpp-0_1_0.so

# Next line will add a .a to the final library
STATIC_LIBS_PATH =

# Add libraries as -lcurl etc.
STATIC_LIBS =

INCLUDES = -I./include

# THESE SHOULD NOT BE EDITED
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, $(SOURCES))
STATIC_LIBS_CMD = -Wl,-bstatic $(shell pkg-config --libs $(STATIC_LIBS))
INCLUDES += $(shell pkg-config --cflags $(STATIC_LIBS))

.PHONY: clean

.SUFFIXES:

all: dirs static dynamic

static: dirs $(LINKABLE)

dynamic: dirs $(DLINKABLE)

dirs: bin/ build/

bin/:
	$(MKDIR) $@

build/:
	$(MKDIR) $@

$(DLINKABLE): $(OBJECTS)
	$(CC) $(LD_FLAGS) -shared $^ -o $@ $(STATIC_LIBS_PATH) $(STATIC_LIBS_CMD)

$(LINKABLE): $(OBJECTS)
	$(AR) -q $@ $^ $(STATIC_LIBS_PATH)

build/%.o: src/%.cpp
	$(CC) -c $< $(INCLUDES) -o $@ $(CC_FLAGS) $(DEFINES)

clean:
	$(RM) -rf build/*.o
	$(RM) -rf bin/*

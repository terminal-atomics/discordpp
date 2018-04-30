CC = g++
RM = rm
AR = ar
CP = cp
CC_FLAGS = -W -Wextra -std=c++11
LD_FLAGS =
DEFINES =



LINKABLE = ./release/discordpp-0_1_0.a
STATIC_LIBS_PATH =
INCLUDES = -I./include

# THESE SHOULD NOT BE EDITED
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, objects/%.o, $(SOURCES))

.PHONY: clean

.SUFFIXES:

all: $(LINKABLE)

$(LINKABLE): $(OBJECTS)
	$(AR) -q $(LINKABLE) $^ $(STATIC_LIBS_PATH)

objects/%.o: src/%.cpp
	$(CC) -c $< $(INCLUDES) -o $@ $(CC_FLAGS) $(DEFINES)

clean:
	$(RM) -rf objects/*.o
	$(RM) $(LINKABLE)

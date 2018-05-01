# <-- Discord++ Makfile -->
# Copyright TerminalAtomics (c)

# CONFIGURATION
DELETE = rm -f 

# DON'T CHANGE
SRC_DIR = ./src
LIB_DIR = ./src/libs
OBJ_DIR = ./build/obj
INC_DIR = ./include
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
LIB_FILES = $(wildcard $(LIB_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES)) $(patsubst $(LIB_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(LIB_FILES))
GPP_CMD = g++
LDFLAGS = -Wl,-Bstatic -lboost_thread -lboost_system -Wl,-Bdynamic -lpthread -lssl -lcrypto
CPPFLAGS = -I ./include --std=c++11 -Werror -lssl -lcrypto
CXXFLAGS = 
OUTPUT = ./build/discordpp

all: $(OUTPUT)

clean:
	$(DELETE) build/obj/*

run: all
	$(OUTPUT)

$(OUTPUT): $(OBJ_FILES)
	$(GPP_CMD) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(GPP_CMD) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.cpp
	$(GPP_CMD) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
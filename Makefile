# which compiler to use
CXX := g++
# binary name
OUTPUT := game

# where SFML is located at
SFML_DIR := /opt/homebrew/Cellar/sfml/2.6.1/

# compiler and linker flags
CXX_FLAGS := -std=c++20 -g
INCLUDES := -I.src/ -I .src/imgui -I .src/imgui-SFML -I$(SFML_DIR)/include
LD_FLAGS := -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -framework OpenGL -L$(SFML_DIR)/lib

# source files
SRC_FILES := $(wildcard src/*.cpp src/imgui/*.cpp src/imgui-SFML/*.cpp)
OBJ_FILES := $(SRC_FILES:.cpp=.o)

build: $(OUTPUT)

$(OUTPUT):$(OBJ_FILES) Makefile
	$(CXX) $(OBJ_FILES) $(LD_FLAGS) -o ./bin/$@

# specifies how the files are compiled from cpp files
.cpp.o:
	$(CXX) -c $(CXX_FLAGS) $(INCLUDES) $< -o $@

# will remove all intermediate build files
clean:
	rm -f $(OBJ_FILES) ./bin/$(OUTPUT)

run:
	cd ./bin && ./game
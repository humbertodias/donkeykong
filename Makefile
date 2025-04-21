PKG_CFLAGS := $(shell pkg-config --cflags sdl12_compat SDL_image SDL_ttf SDL_mixer)
PKG_LIBS   := $(shell pkg-config --libs sdl12_compat SDL_image SDL_ttf SDL_mixer)

CXX      := g++
CXXFLAGS := -g -w $(PKG_CFLAGS)
SRC_DIR  := src
OBJ_DIR  := build
TARGET   := CApp

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(PKG_LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) CApp *~

format:
	find src -name "*.cpp" -o -name "*.h" | xargs clang-format -i

docker:
	docker build -t sdl12-builder .
	docker run --rm -it -v $(shell pwd):/src -w /src sdl12-builder make

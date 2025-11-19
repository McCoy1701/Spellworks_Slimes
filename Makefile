# ====================================================================
# PROJECT CONFIGURATION
# ====================================================================

# Compiler and Tools
CC = gcc
ECC = emcc

# Directories
SRC_DIR   = src
OBJ_DIR   = obj
INC_DIR   = include
BIN_DIR   = bin

# Object Directories (Separated for different build types)
OBJ_DIR_NATIVE = obj/native
OBJ_DIR_EM     = obj/em

#Flags
CINC = -I$(INC_DIR)/
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lm
EFLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -s USE_SDL_MIXER=2 -s USE_SDL_TTF=2

C_FLAGS = -Wall -Wextra $(CINC)
NATIVE_C_FLAGS = $(C_FLAGS) -ggdb -lArchimedes

# ====================================================================
# ARCHIMEDES LIBRARY OBJECTS (Core C Files)
# ====================================================================

SPELLWORKS_SRCS = stage.c

NATIVE_LIB_OBJS = $(patsubst %.c, $(OBJ_DIR_NATIVE)/%.o, $(SPELLWORKS_SRCS))

MAIN_OBJ = $(OBJ_DIR_NATIVE)/main.o

NATIVE_EXE_OBJS = $(NATIVE_LIB_OBJS) $(MAIN_OBJ)

# ====================================================================
# PHONY TARGETS
# ====================================================================

.PHONY: all shared editor EM EMARCH test clean install uninstall ainstall auninstall updateHeader bear bearclean
all: $(BIN_DIR)/native

# Emscripten Targets
EM: $(INDEX_DIR)/index.html
EMARCH: $(BIN_DIR)/libArchimedes.a

# ====================================================================
# DIRECTORY & UTILITY RULES
# ====================================================================

# Ensure the directories exist before attempting to write files to them
$(BIN_DIR) $(OBJ_DIR_NATIVE) $(OBJ_DIR_SHARED) $(OBJ_DIR_EDITOR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_NATIVE) $(OBJ_DIR_SHARED) $(BIN_DIR)
	@clear

bear:
	bear -- make
bearclean:
	rm compile_commands.json

install: $(BIN_DIR)/libArchimedes.so
	sudo cp $< /usr/lib/
	sudo cp $(INC_DIR)/Archimedes.h /usr/include/

uninstall:
	sudo rm /usr/lib/libArchimedes.so
	sudo rm /usr/include/Archimedes.h

ainstall: $(BIN_DIR)/libArchimedes.a
	sudo cp $< /usr/lib/
	sudo cp $(INC_DIR)/Archimedes.h /usr/include/

auninstall:
	sudo rm /usr/lib/libArchimedes.a
	sudo rm /usr/include/Archimedes.h

updateHeader:
	sudo cp $(INC_DIR)/Archimedes.h /usr/include/Archimedes.h

# ====================================================================
# COMPILATION RULES
# ====================================================================

$(OBJ_DIR_NATIVE)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR_NATIVE)
	$(CC) -c $< -o $@ $(NATIVE_C_FLAGS)

$(OBJ_DIR_NATIVE)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR_NATIVE)
	$(CC) -c $< -o $@ $(NATIVE_C_FLAGS)


# ====================================================================
# COMPILATION RULES (Emscripten - ECC)
# ====================================================================

.PHONY: EM
EM: always $(INDEX_DIR)/index

$(OBJ_DIR)/em_main.o: $(TEM_DIR)/main.c
	$(ECC) -c $< $(CINC) $(EFLAGS) -o $@

$(INDEX_DIR)/index: $(OBJ_DIR)/em_main.o $(BIN_DIR)/libArchimedes.a
	mkdir -p $(INDEX_DIR)
	$(ECC) $^ -s WASM=1 $(EFLAGS) --shell-file htmlTemplate/template.html --preload-file resources/ -o $@.html

# ====================================================================
# LINKING RULES
# ====================================================================

# Target: Native Executable
$(BIN_DIR)/native: $(NATIVE_EXE_OBJS) | $(BIN_DIR)
	$(CC) $^ -o $@ $(NATIVE_C_FLAGS) $(LDLIBS)


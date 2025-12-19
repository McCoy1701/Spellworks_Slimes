# ====================================================================
# PROJECT CONFIGURATION
# ====================================================================

# Compiler and Tools
CC = gcc
ECC = emcc

# Directories
SRC_DIR    = src
OBJ_DIR    = obj
INC_DIR    = include
BIN_DIR    = bin
LIB_DIR    = lib
INDEX_DIR  = index
STAGES_DIR = src/stages
ENTITY_LOGIC_DIR = src/entity_logic
ENTITY_DIR = src/entities

# Object Directories (Separated for different build types)
OBJ_DIR_NATIVE = obj/native
OBJ_DIR_STAGES = obj/native/stages
OBJ_DIR_ENTITY_LOGIC = obj/native/entity_logic
OBJ_DIR_ENTITIES = obj/native/entities
OBJ_DIR_EM     = obj/em

#Flags
CINC = -I$(INC_DIR)/
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lm
EFLAGS = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' -s USE_SDL_MIXER=2 -s USE_SDL_TTF=2 -sALLOW_MEMORY_GROWTH

C_FLAGS = -Wall -Wextra $(CINC)
NATIVE_C_FLAGS = $(C_FLAGS) -ggdb -lArchimedes -lDaedalus
EMSCRIP_C_FLAGS = $(C_FLAGS) $(EFLAGS)

# ====================================================================
# SPELLWORKS SLIMES LIBRARY OBJECTS (Core C Files)
# ====================================================================

ENTITIES_SRCS = player_entity.c \
								bullet_entity.c \
								base_enemy_entity.c \

ENTITY_LOGIC_SRCS = player.c \
										bullet.c \
		    						base_enemy.c \


STAGES_SRCS = stage_0.c \

SPELLWORKS_SRCS = entity.c \
									entity_factory.c \
									image.c \
									iso.c \
									main_menu.c \
									map.c \
									utils.c \

NATIVE_LIB_OBJS = $(patsubst %.c, $(OBJ_DIR_NATIVE)/%.o, $(SPELLWORKS_SRCS))
ENTITIES_LIB_OBJS = $(patsubst %.c, $(OBJ_DIR_ENTITIES)/%.o, $(ENTITIES_SRCS))
ENTITY_LOGIC_LIB_OBJS = $(patsubst %.c, $(OBJ_DIR_ENTITY_LOGIC)/%.o, $(ENTITY_LOGIC_SRCS))
STAGES_LIB_OBJS = $(patsubst %.c, $(OBJ_DIR_STAGES)/%.o, $(STAGES_SRCS))
EMCC_LIB_OBJS = $(patsubst %.c, $(OBJ_DIR_EM)/%.o, $(SPELLWORKS_SRCS))

MAIN_OBJ = $(OBJ_DIR_NATIVE)/main.o
EM_MAIN_OBJ = $(OBJ_DIR_EM)/main.o

NATIVE_EXE_OBJS = $(ENTITIES_LIB_OBJS) $(ENTITY_LOGIC_LIB_OBJS) $(STAGES_LIB_OBJS) $(NATIVE_LIB_OBJS) $(MAIN_OBJ)
EMCC_EXE_OBJS = $(EMCC_LIB_OBJS) $(EM_MAIN_OBJ)

# ====================================================================
# PHONY TARGETS
# ====================================================================

.PHONY: all EM clean bear bearclean
all: $(BIN_DIR)/native

# Emscripten Targets
EM: $(INDEX_DIR)/index

# ====================================================================
# DIRECTORY & UTILITY RULES
# ====================================================================

# Ensure the directories exist before attempting to write files to them
$(BIN_DIR) $(OBJ_DIR_NATIVE) $(OBJ_DIR_EM) $(OBJ_DIR_EDITOR) $(INDEX_DIR) $(OBJ_DIR_ENTITIES) $(OBJ_DIR_ENTITY_LOGIC) $(OBJ_DIR_STAGES):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_NATIVE) $(OBJ_DIR_EM) $(BIN_DIR) $(INDEX_DIR)
	@clear

bear:
	bear -- make

bearclean:
	rm compile_commands.json

# ====================================================================
# COMPILATION RULES
# ====================================================================

$(OBJ_DIR_ENTITY_LOGIC)/%.o: $(ENTITY_LOGIC_DIR)/%.c | $(OBJ_DIR_ENTITY_LOGIC)
	$(CC) -c $< -o $@ $(NATIVE_C_FLAGS)

$(OBJ_DIR_STAGES)/%.o: $(STAGES_DIR)/%.c | $(OBJ_DIR_STAGES)
	$(CC) -c $< -o $@ $(NATIVE_C_FLAGS)

$(OBJ_DIR_ENTITIES)/%.o: $(ENTITY_DIR)/%.c | $(OBJ_DIR_ENTITIES)
	$(CC) -c $< -o $@ $(NATIVE_C_FLAGS)

$(OBJ_DIR_NATIVE)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR_NATIVE)
	$(CC) -c $< -o $@ $(NATIVE_C_FLAGS)

$(OBJ_DIR_NATIVE)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR_NATIVE)
	$(CC) -c $< -o $@ $(NATIVE_C_FLAGS)


# ====================================================================
# COMPILATION RULES (Emscripten - ECC)
# ====================================================================

$(OBJ_DIR_EM)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR_EM)
	$(ECC) -c $< -o $@ $(EMSCRIP_C_FLAGS)

$(OBJ_DIR_EM)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR_EM)
	$(ECC) -c $< -o $@ $(EMSCRIP_C_FLAGS)

# ====================================================================
# LINKING RULES
# ====================================================================

# Target: Native Executable
$(BIN_DIR)/native: $(NATIVE_EXE_OBJS) | $(BIN_DIR)
	$(CC) $^ -o $@ $(NATIVE_C_FLAGS) $(LDLIBS)

$(INDEX_DIR)/index: $(EMCC_EXE_OBJS) $(LIB_DIR)/libArchimedes.a | $(INDEX_DIR)
	$(ECC) $^ -s WASM=1 $(EFLAGS) --shell-file htmlTemplate/template.html --preload-file resources/ -o $@.html


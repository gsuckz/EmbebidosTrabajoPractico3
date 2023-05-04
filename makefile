SRC_DIR = ./src
OUT_DIR = ./build
INC_DIR = ./inc
OBJ_DIR = $(OUT_DIR)/obj
BIN_DIR = $(OUT_DIR)/bin
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(OBJ_DIR)
	gcc -c $< -o $@ -I ./src 

$(OUT_DIR):
		mkdir $(OUT_DIR)

$(OBJ_DIR) : $(OUT_DIR)
		mkdir $(OBJ_DIR)		
$(BIN_DIR): $(OUT_DIR)
	mkdir $(BIN_DIR)

$(INC_DIR) : 
		mkdir $(INC_DIR)		

clean: $(OUT_DIR)
	rm -r $(OUT_DIR)

all: $(OBJ_FILES) $(BIN_DIR)
	gcc -o $(BIN_DIR)/app.elf $(OBJ_FILES)
	
doc: 
	doxygen Doxyfile

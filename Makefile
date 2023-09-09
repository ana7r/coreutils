CC      := gcc
BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
SRCS    := $(wildcard $(SRC)/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
CFLAGS  := -I$(INCLUDE)
LDLIBS  := -lm
LDFLAGS := $(LDLIBS)

EXECS:= $(patsubst $(OBJ)/%.o,$(BIN)/%,$(OBJS))

.PHONY: all run clean

all: $(OBJS) $(EXECS)

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN)/%:$(OBJ)/%.o | $(BIN)
	$(CC) $^ $(LDFLAGS) -o $@

$(BIN) $(OBJ):
	mkdir -p $@

run: $(EXE)
	$<

clean:
	rm -rf $(OBJ) $(BIN)


CC= gcc

SRC= $(wildcard *.c)

WARN= -Wall -Wextra
DEBG= -g -fsanitize=address
OPT= -DNDEBUG -O3 -march=native -flto
BIN= molly

$(BIN): $(SRC)
	$(CC) $(WARN) $(DEBG) $(SRC) -o $@

build: $(SRC)
	$(CC) $(WARN) $(OPT) $(SRC) -o $(BIN)

format:
	clang-format -i $(SRC)

clean:
	@rm -f $(BIN)

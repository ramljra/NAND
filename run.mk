CC=gcc
CFLAGS=-Iinclude

SRC=src/main.c src/nand.c src/ftl.c src/nvme.c
OUT=ssd_sim

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)

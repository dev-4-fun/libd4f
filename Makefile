SHELL = /bin/sh

INCLUDE_DIR=./include
LIB_DIR=./lib

SOURCE_DIR=./src
OBJECT_DIR=./obj

TEST_DIR=./tests

CC = clang
CFLAGS = -std=c89 -Wall -Wextra -Werror -Wpedantic -g -I$(INCLUDE_DIR)

SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
LIB_OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(OBJECT_DIR)/%.o, $(SOURCES))
LIB = d4f

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TESTS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TEST_SOURCES))

all: build test

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(LIB): $(LIB_OBJECTS)
	ar rcs $(LIB_DIR)/lib$@.a $?

$(TEST_DIR)/bin/%: $(TEST_DIR)/%.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L$(LIB_DIR) -l$(LIB) 

build: dirs test_dirs $(LIB) $(TESTS)

test: test_dirs $(TESTS)
	@for test in $(TESTS); do \
		$$test; \
	done;

clean:
	rm -rf $(OBJECT_DIR)/*
	rm -rf $(LIB_DIR)/*
	rm -rf $(TEST_DIR)/bin/*

dirs:
	mkdir -p $(OBJECT_DIR)
	mkdir -p $(LIB_DIR)

test_dirs:
	mkdir -p $(TEST_DIR)/bin

SHELL = /bin/sh

SOURCE_DIR=./src
INCLUDE_DIR=./include
LIB_DIR=./lib
TEST_DIR=./tests
OBJECT_DIR=./obj

CC = clang
CFLAGS = -std=c89 -Wall -Wextra -Werror -g -I$(INCLUDE_DIR)
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
LIB_OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(OBJECT_DIR)/%.o, $(SOURCES))
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TESTS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TEST_SOURCES))
LIB = d4f

all: build test

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(LIB): $(LIB_OBJECTS)
	ar rcs $(LIB_DIR)/lib$@.a $?

build: dirs test_dirs $(LIB) $(TESTS)

test: test_dirs $(TESTS)
	@for test in $(TESTS); do \
		$$test; \
	done;

$(TEST_DIR)/bin/%: $(TEST_DIR)/%.c $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L$(LIB_DIR) -l$(LIB) 

clean:
	rm -rf $(OBJECT_DIR)/*
	rm -rf $(LIB_DIR)/*
	rm -rf $(TEST_DIR)/bin/*

dirs:
	mkdir -p $(OBJECT_DIR)
	mkdir -p $(LIB_DIR)

test_dirs:
	mkdir -p $(TEST_DIR)/bin
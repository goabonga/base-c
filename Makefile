# SPDX-License-Identifier: MIT
# Copyright (c) 2026 Chris <goabonga@pm.me>

CC      ?= cc
CFLAGS  ?= -O2
CFLAGS  += -std=c11 -Wall -Wextra -Wpedantic -Werror -Iinclude
PREFIX  ?= /usr/local
SANITIZE ?= address,undefined
BUILD   := build

LIB_OBJ := $(BUILD)/base.o

.PHONY: all test clean install

all: $(BUILD)/base-c

$(BUILD)/base-c: $(BUILD)/main.o $(LIB_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD)/%.o: src/%.c include/base.h | $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD):
	mkdir -p $@

# Unit tests, built with the address and undefined behaviour sanitizers.
# Disable them with `make test SANITIZE=` where the platform rejects them.
test: $(BUILD)/test_base
	$(BUILD)/test_base

$(BUILD)/test_base: tests/test_base.c src/base.c include/base.h | $(BUILD)
	$(CC) $(CFLAGS) -g $(if $(SANITIZE),-fsanitize=$(SANITIZE) -fno-sanitize-recover=all) \
		$(LDFLAGS) -o $@ tests/test_base.c src/base.c

install: all
	install -Dm755 $(BUILD)/base-c $(DESTDIR)$(PREFIX)/bin/base-c

clean:
	rm -rf $(BUILD)

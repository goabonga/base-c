# SPDX-License-Identifier: MIT
# Copyright (c) 2026 Chris <goabonga@pm.me>

CC      ?= cc
CFLAGS  ?= -O2
CFLAGS  += -std=c11 -Wall -Wextra -Wpedantic -Werror -Iinclude
PREFIX  ?= /usr/local
BUILD   := build

LIB_OBJ := $(BUILD)/base.o

.PHONY: all clean install

all: $(BUILD)/base-c

$(BUILD)/base-c: $(BUILD)/main.o $(LIB_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD)/%.o: src/%.c include/base.h | $(BUILD)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD):
	mkdir -p $@

install: all
	install -Dm755 $(BUILD)/base-c $(DESTDIR)$(PREFIX)/bin/base-c

clean:
	rm -rf $(BUILD)

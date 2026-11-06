/* SPDX-License-Identifier: MIT */
/* Copyright (c) 2026 Chris <goabonga@pm.me> */

#ifndef BASE_H
#define BASE_H

#include <stddef.h>

#define BASE_VERSION "0.1.0"

/*
 * Writes "Hello, <name>!" into buf (NUL-terminated, truncated to size).
 * A NULL or empty name greets "world". Returns the length the full
 * message needs, excluding the NUL, like snprintf; -1 if buf is NULL
 * with a non-zero size.
 */
int base_greet(char *buf, size_t size, const char *name);

#endif /* BASE_H */

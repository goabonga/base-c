/* SPDX-License-Identifier: MIT */
/* Copyright (c) 2026 Chris <goabonga@pm.me> */

#include "base.h"

#include <stdio.h>

int base_greet(char *buf, size_t size, const char *name)
{
	if (buf == NULL && size != 0)
		return -1;
	if (name == NULL || name[0] == '\0')
		name = "world";
	return snprintf(buf, size, "Hello, %s!", name);
}

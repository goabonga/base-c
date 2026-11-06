/* SPDX-License-Identifier: MIT */
/* Copyright (c) 2026 Chris <goabonga@pm.me> */

#include "base.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char buf[256];

	if (argc > 1 && strcmp(argv[1], "--version") == 0) {
		puts(BASE_VERSION);
		return 0;
	}
	base_greet(buf, sizeof(buf), argc > 1 ? argv[1] : NULL);
	puts(buf);
	return 0;
}

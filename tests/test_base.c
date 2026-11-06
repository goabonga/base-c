/* SPDX-License-Identifier: MIT */
/* Copyright (c) 2026 Chris <goabonga@pm.me> */

#include "base.h"

#include <stdio.h>
#include <string.h>

static int failures;

#define CHECK(cond)                                                            \
	do {                                                                   \
		if (!(cond)) {                                                 \
			fprintf(stderr, "%s:%d: check failed: %s\n", __FILE__, \
				__LINE__, #cond);                              \
			failures++;                                            \
		}                                                              \
	} while (0)

static void test_named(void)
{
	char buf[64];

	CHECK(base_greet(buf, sizeof(buf), "Chris") == 13);
	CHECK(strcmp(buf, "Hello, Chris!") == 0);
}

static void test_default_name(void)
{
	char buf[64];

	CHECK(base_greet(buf, sizeof(buf), NULL) == 13);
	CHECK(strcmp(buf, "Hello, world!") == 0);
	CHECK(base_greet(buf, sizeof(buf), "") == 13);
	CHECK(strcmp(buf, "Hello, world!") == 0);
}

static void test_truncation(void)
{
	char buf[6];

	CHECK(base_greet(buf, sizeof(buf), "Chris") == 13);
	CHECK(strcmp(buf, "Hello") == 0);
}

static void test_size_only(void)
{
	CHECK(base_greet(NULL, 0, "Chris") == 13);
}

static void test_null_buffer(void)
{
	CHECK(base_greet(NULL, 8, "Chris") == -1);
}

int main(void)
{
	test_named();
	test_default_name();
	test_truncation();
	test_size_only();
	test_null_buffer();
	if (failures) {
		fprintf(stderr, "%d check(s) failed\n", failures);
		return 1;
	}
	puts("all tests passed");
	return 0;
}

/*
 * Shared library for setting stdout to line buffered
 * Use by set LD_PRELOAD
 *
 * Copyright (C) 2018 Thommy Jakobsson thommyj@gmail.com
 * Licensed under gplv2
 */
#include <stdio.h>
#include <unistd.h>

static void line_buffer_me_main(void) __attribute__((constructor));
static void line_buffer_me_main(void)
{
 	int setvbuf_ret; 

	setvbuf_ret = setvbuf(stdout, NULL, _IOLBF, 0);
	if (setvbuf_ret != 0) {
		fprintf(stderr, "line_buffer_me: setvbuf returned %d\n", setvbuf_ret);
		_exit(1);
	}
}

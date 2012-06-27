
/* This file is part of minemu
 *
 * Copyright 2010-2011 Erik Bosman <erik@minemu.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <ctype.h>
#include "hexdump.h"

static inline long max(long a, long b) { return a>b ? a:b; }
static inline long min(long a, long b) { return a<b ? a:b; }

static const char *desc_color = "\033[0;34m", *reset = "\033[m";

/* Prints up to 16 characters in hexdump style with optional colors
 * if `ascii' is non-zero, an additional ascii representation is printed
 */
void hexdump_line(FILE* fp, const void *data, ssize_t len,
                  int offset, int ascii,
                  const char *description,
                  const unsigned char *indices,
                  const char *colors[])
{
	int i, cur = -1;
	char c;

	if ( description != NULL )
		fprintf(fp, "           %s%s%s\n", desc_color, description, reset);

	for (i=0; i<16; i++)
	{
		if (i == 0)
		{
			if (offset)
				fprintf(fp, "%08lx  ", (long)data);
			else
				fprintf(fp, "          ");
		}
		else if (i % 8 == 0)
			fprintf(fp, " ");

		if (i < len)
		{
			if ( indices && colors && (cur != indices[i]) )
				fprintf(fp, "%s", colors[cur = indices[i]]);

			fprintf(fp, " %02x", ((unsigned char *)data)[i]);
		}
		else
			fprintf(fp, "   ");
	}

	if (indices && colors)
		fprintf(fp, "\033[m");

	if (ascii && len > 0)
	{
		cur = -1;
		fprintf(fp, "   |");

		for (i=0; i<16; i++)
		{
			if (i == len)
				break;

			if ( indices && colors && (cur != indices[i]) )
				fprintf(fp, "%s", colors[cur = indices[i]]);

			c = ((unsigned char *)data)[i];
			fprintf(fp, "%c", isprint(c)?c:'.');
		}

		if (indices && colors)
			fprintf(fp, "\033[m");

		fprintf(fp, "|");
	}

	fprintf(fp, "\n");
}

void hexdump(FILE* fp, const void *data, ssize_t len,
             int offset, int ascii,
             const char *description[],
             const unsigned char *indices,
             const char *colors[])
{
	ssize_t row;

	for (row=0; row*16<len; row++)
		hexdump_line(fp, (char*)data+row*16, min(16, len-row*16),
		             offset, ascii,
		             description ? description[row] : NULL,
		             indices+row*16, colors);
}


// figure out who's copyright to put here later

/* $Id$ */

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include "sectionname.h"
#include "stdio_private.h"

ATTRIBUTE_CLIB_SECTION
int
vsscanf(const char *s, const char *fmt, va_list ap)
{
	FILE f;
	int i;

	f.flags = __SRD | __SSTR;
	/*
	 * It is OK to discard the "const" qualifier here.  f.buf is
	 * non-const as in the generic case, this buffer is obtained
	 * by malloc().  In the scanf case however, the buffer is
	 * really only be read (by getc()), and as this our FILE f we
	 * be discarded upon exiting sscanf(), nobody will ever get
	 * a chance to get write access to it again.
	 */
	f.buf = (char *)s;
	i = vfscanf(&f, fmt, ap);

	return i;
}

/* vi: set sw=4 ts=4: */
/*
 * busybox library eXtended function
 *
 * Copyright (C) 2001 Larry Doolittle, <ldoolitt@recycle.lbl.gov>
 *
 * Licensed under GPLv2 or later, see file LICENSE in this tarball for details.
 */

#include <string.h>
#include "libbb.h"

/* Find out if the last character of a string matches the one given Don't
 * underrun the buffer if the string length is 0.  Also avoids a possible
 * space-hogging inline of strlen() per usage.
 */
char * last_char_is(const char *s, int c)
{
	char *sret = (char *)s;
	if (sret) {
		sret = strrchr(sret, c);
		if(sret != NULL && *(sret+1) != 0)
			sret = NULL;
	}
	return sret;
}

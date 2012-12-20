/* @(#)s_scalbn.c 5.1 93/09/24 */
/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice 
 * is preserved.
 * ====================================================
 */

/* 
 * scalbn (double x, int n)
 * scalbn(x,n) returns x* 2**n  computed by  exponent  
 * manipulation rather than by actually performing an 
 * exponentiation or a multiplication.
 */

/* LINTLIBRARY */

#include <float.h>
#include <math.h>

double
scalbn (double x, int n)
{
	return ldexp(x, n);
}

#if	LDBL_MANT_DIG == 53
#ifdef	lint
/* PROTOLIB1 */
long double scalbnl(long double, int);
#else	/* lint */
__weak_alias(scalbnl, scalbn);
#endif	/* lint */
#endif	/* LDBL_MANT_DIG == 53 */

/* HSTMATCH module=EBOOT.BIN start=0x0000a430 end=0x0000a550 symbol=FUN_0000a430 lang=c99 cc=gcc171x-O2 rodata=0x002ba3cc */
/* Library source: newlib libm kf_cos.c function __kernel_cosf (fdlibm-derived; Sun Microsystems notice kept below), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. The static const coefficients are macros here: the retail object holds only the literal pool, in first-use order, without the unreferenced static copies GCC 3.3 emits for static const declarations. */
/* ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef union { float value; __uint32_t word; } ieee_float_shape_type;
#define GET_FLOAT_WORD(i,d) do { ieee_float_shape_type gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD(d,i) do { ieee_float_shape_type sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)

#define one ((float)1.0000000000e+00) /* 0x3f800000 */
#define C1 ((float)4.1666667908e-02) /* 0x3d2aaaab */
#define C2 ((float)-1.3888889225e-03) /* 0xbab60b61 */
#define C3 ((float)2.4801587642e-05) /* 0x37d00d01 */
#define C4 ((float)-2.7557314297e-07) /* 0xb493f27c */
#define C5 ((float)2.0875723372e-09) /* 0x310f74f6 */
#define C6 ((float)-1.1359647598e-11) /* 0xad47d74e */

float FUN_0000a430(float x, float y)
{
	float a,hz,z,r,qx;
	__int32_t ix;
	GET_FLOAT_WORD(ix,x);
	ix &= 0x7fffffff;			/* ix = |x|'s high word*/
	if(ix<0x32000000) {			/* if x < 2**27 */
	    if(((int)x)==0) return one;		/* generate inexact */
	}
	z  = x*x;
	r  = z*(C1+z*(C2+z*(C3+z*(C4+z*(C5+z*C6)))));
	if(ix < 0x3e99999a) 			/* if |x| < 0.3 */
	    return one - ((float)0.5*z - (z*r - x*y));
	else {
	    if(ix > 0x3f480000) {		/* x > 0.78125 */
		qx = (float)0.28125;
	    } else {
	        SET_FLOAT_WORD(qx,ix-0x01000000);	/* x/4 */
	    }
	    hz = (float)0.5*z-qx;
	    a  = one-qx;
	    return a - (hz - (z*r-x*y));
	}
}

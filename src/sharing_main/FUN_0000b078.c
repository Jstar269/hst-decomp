/* HSTMATCH module=hstp_trans_main.prx start=0x0000b078 end=0x0000b184 symbol=FUN_0000b078 lang=c99 cc=gcc171x-O2 */
/* Clone of src/eboot/FUN_0000b060.c (hstclone.py tag a2c3s): addresses substituted; exact match verified; names and types await human review. */
/* Library source: newlib libm s_cos.c function cos (fdlibm-derived; Sun Microsystems, Inc. 1993, freely redistributable with this notice), adapted by hand from the newlib source; exact match verified; names and types await human review. */
typedef int __int32_t; typedef unsigned int __uint32_t;
typedef union { double value; struct { __uint32_t lsw; __uint32_t msw; } parts; } ieee_double_shape_type;
#define GET_HIGH_WORD(i,d) do { ieee_double_shape_type gh_u; gh_u.value = (d); (i) = gh_u.parts.msw; } while (0)
extern int FUN_00006e20(double x, double *y); /* __ieee754_rem_pio2 */
extern double FUN_0000913c(double x, double y); /* __kernel_cos */
extern double FUN_0000a17c(double x, double y, int iy); /* __kernel_sin */
double FUN_0000b078(double x)
{
	double y[2],z=0.0;
	__int32_t n,ix;
	GET_HIGH_WORD(ix,x);
	ix &= 0x7fffffff;
	if(ix <= 0x3fe921fb) return FUN_0000913c(x,z);
	else if (ix>=0x7ff00000) return x-x;
	else {
	    n = FUN_00006e20(x,y);
	    switch(n&3) {
		case 0: return  FUN_0000913c(y[0],y[1]);
		case 1: return -FUN_0000a17c(y[0],y[1],1);
		case 2: return -FUN_0000913c(y[0],y[1]);
		default:
		        return  FUN_0000a17c(y[0],y[1],1);
	    }
	}
}

/* HSTMATCH module=EBOOT.BIN start=0x0000f040 end=0x0000f13c symbol=FUN_0000f040 lang=c99 cc=gcc171-O2 */
/* Library source: newlib libc stdio fflush.c function fflush (BSD-derived; Regents of the University of California, BSD licence), adapted by hand from the newlib source; exact match verified; names and types await human review. */
#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SWR 0x0008
#define __SERR 0x0040
#define EOF (-1)
struct __sbuf { unsigned char *_base; int _size; };
typedef struct __sFILE {
  unsigned char *_p; int _r; int _w; short _flags; short _file; struct __sbuf _bf; int _lbfsize;
  void *_cookie; int (*_read)(void *, char *, int); int (*_write)(void *, const char *, int);
} FILE;
struct _reent { char pad[56]; int __sdidinit; };
extern struct _reent *FUN_0000fe3c(void);           /* __getreent */
extern void FUN_0000f330(struct _reent *);          /* __sinit */
extern int FUN_0000fd34(struct _reent *, int (*)(FILE *)); /* _fwalk */
extern struct _reent *DAT_002cf6b8;                 /* _global_impure_ptr */
#define _REENT (FUN_0000fe3c())
#define CHECK_INIT(fp) do { if (!_REENT->__sdidinit) FUN_0000f330(_REENT); } while (0)

int FUN_0000f040(register FILE *fp)
{
  register unsigned char *p;
  register int n, t;

  if (fp == 0)
    return FUN_0000fd34(DAT_002cf6b8, FUN_0000f040);

  CHECK_INIT (fp);

  t = fp->_flags;
  if ((t & __SWR) == 0 || (p = fp->_bf._base) == 0)
    return 0;
  n = fp->_p - p;		/* write this much */

  fp->_p = p;
  fp->_w = t & (__SLBF | __SNBF) ? 0 : fp->_bf._size;

  while (n > 0)
    {
      t = (*fp->_write) (fp->_cookie, (char *) p, n);
      if (t <= 0)
	{
	  fp->_flags |= __SERR;
	  return EOF;
	}
      p += t;
      n -= t;
    }
  return 0;
}

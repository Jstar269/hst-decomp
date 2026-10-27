/* HSTMATCH module=EBOOT.BIN start=0x0000fd34 end=0x0000fe3c symbol=FUN_0000fd34 lang=c99 cc=gcc171-O2 */
/* Library source: newlib libc stdio fwalk.c function _fwalk, the older form that walks the given list and then the global list (BSD-derived; Regents of the University of California, BSD licence), adapted by hand; exact match verified; names and types await human review. */
typedef struct __sFILE { char pad0[12]; short _flags; char pad1[92 - 14]; } FILE;
struct _glue { struct _glue *_next; int _niobs; FILE *_iobs; };
struct _reent { char pad[604]; struct _glue __sglue; };
extern struct _reent *DAT_002cf6b8;   /* _global_impure_ptr */
#define _GLOBAL_REENT DAT_002cf6b8

int FUN_0000fd34(struct _reent *ptr, register int (*function) (FILE *))
{
  register FILE *fp;
  register int n, ret = 0;
  register struct _glue *g;

  /* Must traverse given list for std streams.  */
  if (ptr != _GLOBAL_REENT)
    {
      for (g = &ptr->__sglue; g != 0; g = g->_next)
        for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
          if (fp->_flags != 0)
            ret |= (*function) (fp);
    }

  /* Must traverse global list for all other streams.  */
  for (g = &_GLOBAL_REENT->__sglue; g != 0; g = g->_next)
    for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
      if (fp->_flags != 0)
        ret |= (*function) (fp);

  return ret;
}

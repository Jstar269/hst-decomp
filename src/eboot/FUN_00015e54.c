/* HSTMATCH module=EBOOT.BIN start=0x00015e54 end=0x00015ea0 symbol=FUN_00015e54 lang=c99 cc=gcc171-O2 */
/* Library source: newlib libc stdlib strtod.c function strtof (David M. Gay, AT&T 1991 licence), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. */
extern void *FUN_0000fe3c(void); extern double FUN_00014dc0(void *r, const char *s, char **e);
float FUN_00015e54(const char *s, char **e) { return (float)FUN_00014dc0(FUN_0000fe3c(), s, e); }

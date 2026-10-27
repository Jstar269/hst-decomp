/* HSTMATCH module=EBOOT.BIN start=0x000133f4 end=0x0001342c symbol=FUN_000133f4 lang=c99 cc=gcc171-O2 */
/* Library source: newlib libc stdlib rand.c function srand (newlib, Red Hat / Cygnus licence), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. */
struct R { char pad[0xa8]; unsigned long long next; };
extern struct R *FUN_0000fe3c(void);
void FUN_000133f4(unsigned seed) { FUN_0000fe3c()->next = seed; }

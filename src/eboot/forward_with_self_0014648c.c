/* HSTMATCH module=EBOOT.BIN start=0x0014648c end=0x001464ac symbol=FUN_0014648c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* A `char *` local for self is what makes mwcc copy `move v0,a0` BEFORE it overwrites a0 with the first
   call argument; using `self` directly computes the three addresses from a0 and costs the copy (7 words). */
extern char DAT_002dbb3c;
extern void FUN_000143b0(int,void *,void *,void *,int);

void FUN_0014648c(int self,int a1)
{
    char *p = (char *)self;
    FUN_000143b0(a1, &DAT_002dbb3c, p + 0xd68, p + 0xd28, *(int *)(p + 0xd24));
}

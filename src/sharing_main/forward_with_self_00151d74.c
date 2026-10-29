/* HSTMATCH module=hstp_trans_main.prx start=0x00151d74 end=0x00151d94 symbol=FUN_00151d74 lang=c99 */
/* Clone of src/eboot/forward_with_self_0014648c.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* A `char *` local for self is what makes mwcc copy `move v0,a0` BEFORE it overwrites a0 with the first
   call argument; using `self` directly computes the three addresses from a0 and costs the copy (7 words). */
extern char DAT_00382d9c;
extern void FUN_000143b0(int,void *,void *,void *,int);

void FUN_00151d74(int self,int a1)
{
    char *p = (char *)self;
    FUN_000143b0(a1, &DAT_00382d9c, p + 0xd68, p + 0xd28, *(int *)(p + 0xd24));
}

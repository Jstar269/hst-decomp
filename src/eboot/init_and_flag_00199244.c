/* HSTMATCH module=EBOOT.BIN start=0x00199244 end=0x00199280 symbol=FUN_00199244 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_002b7cd8(void *);
extern unsigned char DAT_00341771;
struct S { char pad[112]; int *f70; char pad2[8]; int f7c; };

void FUN_00199244(struct S *s)
{
    s->f7c = 1;
    *(int *)((char *)s->f70 + 48) = 8;
    FUN_002b7cd8((char *)s + 60);
    DAT_00341771 = 1;
}

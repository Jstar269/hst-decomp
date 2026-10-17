/* HSTMATCH module=hstp_trans_main.prx start=0x0006e218 end=0x0006e23c symbol=FUN_0006e218 */
/* Clone of src/eboot/FUN_000db4c0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
typedef struct { int pad; int sub; } WithSub;
extern void FUN_00069f44(int *sub, int v);

void FUN_0006e218(void *self, WithSub *w)
{
    if (w) FUN_00069f44(&w->sub, -1);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x000df480 end=0x000df4a4 symbol=FUN_000df480 */
/* Clone of src/eboot/FUN_000db4c0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
typedef struct { int pad; int sub; } WithSub;
extern void FUN_000dd87c(int *sub, int v);

void FUN_000df480(void *self, WithSub *w)
{
    if (w) FUN_000dd87c(&w->sub, -1);
}

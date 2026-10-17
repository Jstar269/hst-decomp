/* HSTMATCH module=EBOOT.BIN start=0x0006cc30 end=0x0006cc54 symbol=FUN_0006cc30 */
/* Clone of src/eboot/FUN_000db4c0.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
typedef struct { int pad; int sub; } WithSub;
extern void FUN_00068af0(int *sub, int v);

void FUN_0006cc30(void *self, WithSub *w)
{
    if (w) FUN_00068af0(&w->sub, -1);
}

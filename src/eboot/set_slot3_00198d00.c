/* HSTMATCH module=EBOOT.BIN start=0x00198d00 end=0x00198d28 symbol=FUN_00198d00 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[140]; int arr[3]; };

void FUN_00198d00(struct S *s, int i, int v)
{
    if (i >= 0 && i < 3)
        s->arr[i] = v;
}

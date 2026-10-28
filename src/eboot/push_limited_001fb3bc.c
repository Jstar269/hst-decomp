/* HSTMATCH module=EBOOT.BIN start=0x001fb3bc end=0x001fb3f4 symbol=FUN_001fb3bc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[3984]; int arr[40]; int f1030; };

void FUN_001fb3bc(struct S *s, int v)
{
    if (s->f1030 < 0)
        return;
    if (s->f1030 >= 10)
        return;
    s->arr[s->f1030] = v;
    s->f1030 = s->f1030 + 1;
}

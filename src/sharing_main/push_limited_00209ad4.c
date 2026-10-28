/* HSTMATCH module=hstp_trans_main.prx start=0x00209ad4 end=0x00209b0c symbol=FUN_00209ad4 lang=c99 */
/* Clone of src/eboot/push_limited_001fb3bc.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[3984]; int arr[40]; int f1030; };

void FUN_00209ad4(struct S *s, int v)
{
    if (s->f1030 < 0)
        return;
    if (s->f1030 >= 10)
        return;
    s->arr[s->f1030] = v;
    s->f1030 = s->f1030 + 1;
}

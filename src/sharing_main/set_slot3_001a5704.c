/* HSTMATCH module=hstp_trans_main.prx start=0x001a5704 end=0x001a572c symbol=FUN_001a5704 lang=c99 */
/* Clone of src/eboot/set_slot3_00198d00.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[140]; int arr[3]; };

void FUN_001a5704(struct S *s, int i, int v)
{
    if (i >= 0 && i < 3)
        s->arr[i] = v;
}

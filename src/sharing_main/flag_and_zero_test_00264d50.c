/* HSTMATCH module=hstp_trans_main.prx start=0x00264d50 end=0x00264d80 symbol=FUN_00264d50 lang=c99 */
/* Clone of src/eboot/flag_and_zero_test_002548d8.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { int f0; unsigned char flags[472]; int v[1]; };

int FUN_00264d50(struct S *s, int i)
{
    return s->flags[i] != 0 && s->v[i] == 0;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x002b16e4 end=0x002b1710 symbol=FUN_002b16e4 lang=c99 */
/* Clone of src/eboot/state_test_002a234c.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct P { int f0; };
struct S { char pad[432]; int f1b0; char pad2[28]; struct P *f1d0; };

int FUN_002b16e4(struct S *s)
{
    return s->f1b0 == 5 && s->f1d0->f0 == 2;
}

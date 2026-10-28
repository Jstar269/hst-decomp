/* HSTMATCH module=hstp_trans_main.prx start=0x0001de88 end=0x0001deb4 symbol=FUN_0001de88 lang=c99 */
/* Clone of src/eboot/flag_set_clear_0001e23c.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[132]; int f84; };

void FUN_0001de88(struct S *s, int a1, int a2)
{
    if (a2)
        s->f84 = s->f84 | a1;
    else
        s->f84 = s->f84 & ~a1;
}

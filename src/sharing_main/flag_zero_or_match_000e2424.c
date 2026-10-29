/* HSTMATCH module=hstp_trans_main.prx start=0x000e2424 end=0x000e2454 symbol=FUN_000e2424 lang=c99 */
/* Clone of src/eboot/flag_zero_or_match_000de238.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct S { char pad[135]; unsigned char flag; char pad2[156 - 135 - 1]; int value; };

int FUN_000e2424(struct S *s, int a1)
{
    return s->flag != 0 && (a1 < 0 || s->value == a1);
}

/* HSTMATCH module=EBOOT.BIN start=0x000de298 end=0x000de2c8 symbol=FUN_000de298 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct S { char pad[99]; unsigned char flag; char pad2[48]; int value; };

int FUN_000de298(struct S *s, int a1)
{
    return s->flag != 0 && (a1 < 0 || a1 == s->value);
}

/* HSTMATCH module=EBOOT.BIN start=0x000de238 end=0x000de268 symbol=FUN_000de238 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct S { char pad[135]; unsigned char flag; char pad2[156 - 135 - 1]; int value; };

int FUN_000de238(struct S *s, int a1)
{
    return s->flag != 0 && (a1 < 0 || s->value == a1);
}

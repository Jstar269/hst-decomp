/* HSTMATCH module=hstp_trans_main.prx start=0x00050aec end=0x00050b1c symbol=FUN_00050aec lang=c99 */
/* Clone of src/eboot/bounded_elem_00050210.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct E { int a, b, c, d; };
struct S { char pad[520]; struct E e[576]; };

int FUN_00050aec(struct S *s, int i)
{
    if (i >= 0) {
        if (i < 576)
            return s->e[i].a;
    }
    return 0;
}

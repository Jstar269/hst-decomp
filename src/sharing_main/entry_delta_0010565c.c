/* HSTMATCH module=hstp_trans_main.prx start=0x0010565c end=0x00105688 symbol=FUN_0010565c lang=c99 */
/* Clone of src/eboot/entry_delta_000ffd28.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned short u16;
struct E { u16 a; u16 x; u16 b; u16 y; };
struct S { char pad[8]; u16 f08; char pad2[70]; struct E *f50; };

u16 FUN_0010565c(struct S *s, int i)
{
    struct E *p = s->f50;
    if (p != 0)
        return p[i].b - p[i].a;
    return s->f08;
}

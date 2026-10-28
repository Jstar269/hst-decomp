/* HSTMATCH module=EBOOT.BIN start=0x000ffd28 end=0x000ffd54 symbol=FUN_000ffd28 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned short u16;
struct E { u16 a; u16 x; u16 b; u16 y; };
struct S { char pad[8]; u16 f08; char pad2[70]; struct E *f50; };

u16 FUN_000ffd28(struct S *s, int i)
{
    struct E *p = s->f50;
    if (p != 0)
        return p[i].b - p[i].a;
    return s->f08;
}

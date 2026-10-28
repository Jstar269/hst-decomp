/* HSTMATCH module=EBOOT.BIN start=0x000f5e20 end=0x000f5e5c symbol=FUN_000f5e20 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct E { unsigned char flag; char pad[15]; int count; char pad2[44]; };
struct S { char pad[160]; struct E e[16]; };

void FUN_000f5e20(struct S *s)
{
    unsigned int i;
    for (i = 0; i < 16; i++) {
        if (s->e[i].flag == 0)
            continue;
        if (s->e[i].count > 0)
            s->e[i].count = s->e[i].count - 1;
        else
            s->e[i].flag = 0;
    }
}

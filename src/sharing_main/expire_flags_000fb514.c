/* HSTMATCH module=hstp_trans_main.prx start=0x000fb514 end=0x000fb550 symbol=FUN_000fb514 lang=c99 */
/* Clone of src/eboot/expire_flags_000f5e20.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct E { unsigned char flag; char pad[15]; int count; char pad2[44]; };
struct S { char pad[160]; struct E e[16]; };

void FUN_000fb514(struct S *s)
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

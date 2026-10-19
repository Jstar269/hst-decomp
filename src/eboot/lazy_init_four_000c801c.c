/* HSTMATCH module=EBOOT.BIN start=0x000c801c end=0x000c80e0 symbol=FUN_000c801c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Self {
    char pad0[0x3c];
    void *f3c;
    void *f40;
    char pad1[0x48 - 0x44];
    void *f48;
    void *f4c;
    char pad2[0x5c - 0x50];
    int f5c;
};

extern void *FUN_00000bcc(int size);
extern void *FUN_000ce954(void *p);
extern void *FUN_000cede4(void *p, int a);
extern void *FUN_000d0cfc(void *p);
extern void *FUN_000ebdfc(void *p);

int FUN_000c801c(struct Self *s)
{
    void *p;

    if (s->f3c == 0) {
        p = FUN_00000bcc(1360);
        if (p != 0)
            p = FUN_000ce954(p);
        s->f3c = p;
    }
    if (s->f40 == 0) {
        p = FUN_00000bcc(192);
        if (p != 0)
            p = FUN_000cede4(p, s->f5c);
        s->f40 = p;
    }
    if (s->f48 == 0) {
        p = FUN_00000bcc(464);
        if (p != 0)
            p = FUN_000d0cfc(p);
        s->f48 = p;
    }
    if (s->f4c == 0) {
        p = FUN_00000bcc(116);
        if (p != 0)
            p = FUN_000ebdfc(p);
        s->f4c = p;
    }
    return 1;
}

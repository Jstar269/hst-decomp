/* HSTMATCH module=hstp_trans_main.prx start=0x000cbbbc end=0x000cbc80 symbol=FUN_000cbbbc lang=c99 */
/* Clone of src/eboot/lazy_init_four_000c801c.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
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
extern void *FUN_000d2550(void *p);
extern void *FUN_000d29e0(void *p, int a);
extern void *FUN_000d48f8(void *p);
extern void *FUN_000f1354(void *p);

int FUN_000cbbbc(struct Self *s)
{
    void *p;

    if (s->f3c == 0) {
        p = FUN_00000bcc(1360);
        if (p != 0)
            p = FUN_000d2550(p);
        s->f3c = p;
    }
    if (s->f40 == 0) {
        p = FUN_00000bcc(192);
        if (p != 0)
            p = FUN_000d29e0(p, s->f5c);
        s->f40 = p;
    }
    if (s->f48 == 0) {
        p = FUN_00000bcc(464);
        if (p != 0)
            p = FUN_000d48f8(p);
        s->f48 = p;
    }
    if (s->f4c == 0) {
        p = FUN_00000bcc(116);
        if (p != 0)
            p = FUN_000f1354(p);
        s->f4c = p;
    }
    return 1;
}

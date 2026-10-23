/* HSTMATCH module=EBOOT.BIN start=0x000bab10 end=0x000babb8 symbol=FUN_000bab10 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_002b7d58(int);
extern void FUN_000ba3ac(const char *, ...);
extern char DAT_002d4fe4[];
extern char DAT_002d500c[];
extern void *DAT_00338ac4;
extern int FUN_000bda40(void *, void *, int, int, int);

int FUN_000bab10(char *self)
{
    int r = FUN_002b7d58(*(int *)(self + 0x20));
    if (r < 0) {
        FUN_000ba3ac(DAT_002d4fe4, r);
        return 0;
    }
    FUN_000ba3ac(DAT_002d500c);
    *(int *)(self + 0x28) = 1;
    switch (*(int *)(self + 0x28)) {
    case 4:
    case 8: {
        void *g = DAT_00338ac4;
        *(int *)(self + 0x17c) =
            (unsigned char)FUN_000bda40(g, (char *)g + 56, *(unsigned short *)(self + 0x10), 1444, 0);
        break;
    }
    case 10:
        break;
    }
    return 1;
}

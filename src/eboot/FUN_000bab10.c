/* HSTMATCH module=EBOOT.BIN start=0x000bab10 end=0x000babb8 symbol=FUN_000bab10 lang=c99 data=0x002d4fe4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d4fe4-0x002d502d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern int FUN_002b7d58(int);
extern void FUN_000ba3ac(const char *, ...);
extern void *DAT_00338ac4;
extern int FUN_000bda40(void *, void *, int, int, int);

int FUN_000bab10(char *self)
{
    int r = FUN_002b7d58(*(int *)(self + 0x20));
    if (r < 0) {
        FUN_000ba3ac("sceNetAdhocctlConnect() failed(0x%X)\n", r);
        return 0;
    }
    FUN_000ba3ac("sceNetAdhocctlConnect() success\n");
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

/* HSTMATCH module=hstp_trans_main.prx start=0x002aa2cc end=0x002aa3b8 symbol=FUN_002aa2cc lang=c++ rodata=0x002db4c4 */
/* Clone of src/eboot/state_dispatch_table_0029b05c.cpp (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void *DAT_003ea8ec;

extern "C" void FUN_002aa06c(void *, int);
extern "C" void FUN_002ac900();
extern "C" void FUN_002ac4b4();
extern "C" void FUN_002ac08c();
extern "C" void FUN_002aba38();
extern "C" void FUN_002ab1ec();
extern "C" void FUN_002aafa4();
extern "C" void FUN_002a5ba8(void *);
extern "C" void FUN_002aa3b8();

extern "C" void FUN_002aa2cc(char *p) {
    char *s = *(char **)(p + 0x3c);
    switch (*(int *)(s + 8)) {
    case 3:
        if (*(int *)(s + 4) >= 10) FUN_002aa06c(s, 4);
        break;
    case 4:
        FUN_002ac900();
        break;
    case 5:
        FUN_002ac4b4();
        break;
    case 6:
        FUN_002ac08c();
        break;
    case 7:
        FUN_002aba38();
        break;
    case 8:
        FUN_002ab1ec();
        break;
    case 9:
        FUN_002ab1ec();
        break;
    case 10:
        FUN_002aafa4();
        FUN_002a5ba8(DAT_003ea8ec);
        break;
    case 11:
        FUN_002aa3b8();
    }
}

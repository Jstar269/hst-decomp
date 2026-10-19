/* HSTMATCH module=EBOOT.BIN start=0x0029b05c end=0x0029b148 symbol=FUN_0029b05c lang=c++ rodata=0x002cb524 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void *DAT_003415ac;

extern "C" void FUN_0029ade8(void *, int);
extern "C" void FUN_0029d72c();
extern "C" void FUN_0029d2b8();
extern "C" void FUN_0029ce64();
extern "C" void FUN_0029c7d0();
extern "C" void FUN_0029bf68();
extern "C" void FUN_0029bd0c();
extern "C" void FUN_00295cdc(void *);
extern "C" void FUN_0029b148();

extern "C" void FUN_0029b05c(char *p) {
    char *s = *(char **)(p + 0x3c);
    switch (*(int *)(s + 8)) {
    case 3:
        if (*(int *)(s + 4) >= 10) FUN_0029ade8(s, 4);
        break;
    case 4:
        FUN_0029d72c();
        break;
    case 5:
        FUN_0029d2b8();
        break;
    case 6:
        FUN_0029ce64();
        break;
    case 7:
        FUN_0029c7d0();
        break;
    case 8:
        FUN_0029bf68();
        break;
    case 9:
        FUN_0029bf68();
        break;
    case 10:
        FUN_0029bd0c();
        FUN_00295cdc(DAT_003415ac);
        break;
    case 11:
        FUN_0029b148();
    }
}

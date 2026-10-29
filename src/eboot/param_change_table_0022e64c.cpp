/* HSTMATCH module=EBOOT.BIN start=0x0022e64c end=0x0022e734 symbol=FUN_0022e64c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void *DAT_003415a8;
extern "C" int DAT_0034a318[15];

extern "C" bool FUN_0022e64c(char *p) {
    bool changed = false;
    int i = 0;
    char *g = (char *)DAT_003415a8 + 0x86a9c;
    int *prev = DAT_0034a318;
    do {
        int v = *(int *)(p + 0x244);
        if (v != *prev) {
            switch (i) {
            case 0: *(char *)g = v != 0; changed = true; break;
            case 1: *(int *)(g + 4) = v; changed = true; break;
            case 2: *(int *)(g + 0x140) = v; changed = true; break;
            case 14: *(int *)(g + 0xc) = v; changed = true; break;
            case 13: *(char *)(g + 0x130) = v != 0; changed = true; break;
            case 8: *(int *)(g + 0x134) = v; break;
            case 9: *(int *)(g + 0x138) = 1 - v; break;
            }
        }
        i++;
        *prev = *(int *)(p + 0x244);
        prev++;
        p += 4;
    } while (i < 15);
    return changed;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0023e74c end=0x0023e834 symbol=FUN_0023e74c lang=c++ */
/* Clone of src/eboot/param_change_table_0022e64c.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void *DAT_003ea8e8;
extern "C" int DAT_003f3648[15];

extern "C" bool FUN_0023e74c(char *p) {
    bool changed = false;
    int i = 0;
    char *g = (char *)DAT_003ea8e8 + 0x86a9c;
    int *prev = DAT_003f3648;
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

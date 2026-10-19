/* HSTMATCH module=EBOOT.BIN start=0x001ff3dc end=0x001ff4a0 symbol=FUN_001ff3dc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char u8;

extern void *DAT_003386c8;
extern void *DAT_00338ac4;
extern int FUN_000be7b4(void *arg);

int FUN_001ff3dc(int param_1) {
    int res = 0;
    if (DAT_003386c8 != 0) {
        if (DAT_00338ac4 != 0) {
            if (FUN_000be7b4(DAT_00338ac4) != 0) {
                char *sub = 0;
                if (DAT_003386c8 != 0) {
                    if (DAT_00338ac4 != 0) {
                        char *base = *(char **)((char *)DAT_003386c8 + 0x40);
                        if (*(u8 *)((char *)DAT_00338ac4 + 0x178) != 0) {
                            sub = base + 0x1ef8;
                        } else {
                            sub = base + 0x1aa0;
                        }
                    }
                }
                if (*(u8 *)(sub + 0x12d) != 0 && param_1 != 0 && param_1 == *(int *)(sub + 0x3b0) && param_1 == *(int *)(sub + 0x3b4)) {
                    res = 1;
                }
            }
        }
    }
    return res;
}

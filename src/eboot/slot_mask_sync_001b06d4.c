/* HSTMATCH module=EBOOT.BIN start=0x001b06d4 end=0x001b08a0 symbol=FUN_001b06d4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00062418(int, int);
extern void FUN_001b0ef8(int *, int, int, int, int);

void FUN_001b06d4(int *param_1, int *param_2, int count, int flag)
{
    int i, j;
    unsigned char buf[474];
    unsigned char *p;
    int n;

    if (flag != 0) {
        n = 474;
        p = buf;
        if (p != 0) {
            do {
                *p++ = 0;
            } while (--n);
        }
        for (i = 0; i < count; i++)
            buf[param_2[i]] = 1;
        for (j = 0; j < 474; j++) {
            if (buf[j] == 0) {
                if (param_1[j] != 0) {
                    FUN_00062418(param_1[j], 1);
                    param_1[j] = 0;
                }
            }
        }
    }
    for (j = 0; j < count; j++)
        FUN_001b0ef8(param_1, param_2[j], 0, 0, 0);
}

/* HSTMATCH module=EBOOT.BIN start=0x00101048 end=0x00101194 symbol=FUN_00101048 lang=c99 */
extern char DAT_00307b58[];
extern char DAT_00307bac[];
extern char DAT_00307b38[];
extern void FUN_00107034(int);
extern void *FUN_00000bcc(int);
extern void FUN_00050fc0(void *);
extern void FUN_00100a1c(void *, int, int, int, int);
extern void FUN_00106ff0(int, int **, int);

void FUN_00101048(int param_1, int param_2, int *param_3, unsigned int param_4)
{
    int i;
    int *p;
    int *q;
    int n;

    if (*(int *)(param_1 + 8) == 0 && *(unsigned int *)(param_1 + 0xc) < param_4)
        FUN_00107034(param_1 + 4);
    for (i = 0; i < (int)param_4; i++) {
        p = (int *)FUN_00000bcc(0x9c);
        if (p != 0) {
            FUN_00050fc0(p);
            *p = (int)DAT_00307b58;
            p[0x12] = 0;
            p[0x13] = -1;
            *p = (int)DAT_00307bac;
            p[0x14] = 0;
            *p = (int)DAT_00307b38;
            p[0x15] = 0;
            *(char *)(p + 0x16) = 0;
        }
        p[0x12] = param_1;
        q = p;
        FUN_00100a1c(p, param_2, *param_3, 0, 0);
        if (*(unsigned int *)(param_1 + 8) < *(unsigned int *)(param_1 + 0xc)) {
            n = *(unsigned int *)(param_1 + 8) + 1;
            *(int *)(param_1 + 8) = n;
            *(int **)(*(int *)(param_1 + 4) + n * 4 - 4) = q;
        } else {
            FUN_00106ff0(param_1 + 4, &q, 0);
        }
        param_3++;
    }
}
// near miss: 89/83 words. Same allocator shape as 0x00100eb8 but with 0x9c-byte nodes: the
// count==0 growth call, the 0x307b58/0x307bac/0x307b38 vtable stores (+0x48/+0x4c/+0x50/+0x54
// and a byte at +0x58), FUN_00100a1c(p, param_2, *param_3, 0, 0), then the count<capacity push or
// FUN_00106ff0. Ours is 6 words long; the deltas are register roles and the push_back temp.
// near miss from lane fm6 (unreviewed)

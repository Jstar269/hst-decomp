/* HSTMATCH module=EBOOT.BIN start=0x00100eb8 end=0x00101048 symbol=FUN_00100eb8 lang=c99 */
extern char DAT_00307b58[];
extern char DAT_00307bac[];
extern void FUN_00107034(int);
extern void *FUN_00000bcc(int);
extern void FUN_00050fc0(void *);
extern void FUN_000511c4(void *, int, int);
extern void FUN_00051398(float, void *);
extern int FUN_0004cad0(int, int *, int, int);
extern void FUN_00106ff0(int, int **, int);

void FUN_00100eb8(int param_1, int *param_2, unsigned int param_3, int param_4)
{
    int i;
    int *p;
    int local_8;
    int r;
    int n;
    int *q;

    if (*(int *)(param_1 + 8) == 0 && *(unsigned int *)(param_1 + 0xc) < param_3)
        FUN_00107034(param_1 + 4);
    for (i = 0; i < (int)param_3; i++) {
        p = (int *)FUN_00000bcc(0x54);
        if (p != 0) {
            FUN_00050fc0(p);
            *p = (int)DAT_00307b58;
            p[0x12] = 0;
            p[0x13] = -1;
            *p = (int)DAT_00307bac;
            p[0x14] = 0;
        }
        p[0x12] = param_1;
        FUN_000511c4(p, *param_2, 0);
        FUN_00051398(100000.0f, p);
        if (param_4 == 0) {
            p[0x14] = 0;
        } else {
            r = FUN_0004cad0(param_4, &local_8, 0x10, 1);
            if (r == 0 || local_8 < 1)
                p[0x14] = 0;
            else
                p[0x14] = r;
        }
        if (*(unsigned int *)(param_1 + 8) < *(unsigned int *)(param_1 + 0xc)) {
            n = *(unsigned int *)(param_1 + 8) + 1;
            *(int *)(param_1 + 8) = n;
            *(int **)(*(int *)(param_1 + 4) + n * 4 - 4) = p;
        } else {
            q = p;
            FUN_00106ff0(param_1 + 4, &q, 0);
        }
        param_2++;
    }
}
// near miss: 98/100 words. Structure matches (the count==0 && capacity<param_3 growth call, the
// 0x54-byte alloc with the 0x307b58/0x307bac vtable stores at +0/+0x48/+0x4c/+0x50, the
// +0x48 = param_1 back-pointer, FUN_000511c4(p, *param_2, 0), FUN_00051398(100000.0f, p) -- the
// constant is 0x47c35000, NOT 100.0f -- the +0x50 handle from FUN_0004cad0 or 0, and the
// count==capacity push). Ours is 2 words short and differs by register roles plus an extra s6
// holding the 0x307bac vtable that retail re-materialises inline.
// near miss from lane fm6 (unreviewed)

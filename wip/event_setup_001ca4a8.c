/* HSTMATCH module=EBOOT.BIN start=0x001ca4a8 end=0x001ca60c symbol=FUN_001ca4a8 lang=c99 */
extern int *DAT_0034a118;
extern char DAT_002eaa48[];
extern char DAT_0034179c[];
extern void FUN_001b2430(char *);
extern void FUN_00288828(int, int, int);
extern void FUN_00022434(float *, int, float *);
extern void FUN_00048f08(float *, float *);
extern void FUN_00022498(float *, float *, float);
extern void FUN_00022418(float *, float *, float *);
extern void FUN_001cc7d0(int, char *);

void FUN_001ca4a8(int param_1)
{
    int idx = *(int *)(param_1 + 0x50) - 1;
    float v[4];
    float w[4];
    float u[4];
    float y[4];
    float t[4];
    float z[4];
    float *p;

    FUN_001b2430(DAT_0034179c);
    FUN_00288828(idx, *(int *)(param_1 + 0xc0), 1001);
    *(int *)(param_1 + 0x98) = *(int *)(*(int *)(param_1 + 0x4c) + idx * 4);
    p = ((float *(*)(int))((void **)*DAT_0034a118)[0x9c / 4])(*DAT_0034a118);
    v[0] = p[0];
    v[1] = p[1];
    v[2] = p[2];
    v[3] = p[3];
    FUN_00022434(t, param_1 + 0xa0, v);
    u[0] = t[0];
    u[1] = t[1];
    u[2] = t[2];
    u[3] = t[3];
    FUN_00048f08(w, u);
    FUN_00022498(z, w, 0.5f);
    y[0] = z[0];
    y[1] = z[1];
    y[2] = z[2];
    y[3] = z[3];
    FUN_00022418(v, v, y);
    ((void (*)(int, float *))((void **)*(int *)(param_1 + 0x98))[0x1c / 4])(
        *(int *)(param_1 + 0x98), v);
    ((void (*)(int, int))((void **)*(int *)(param_1 + 0x98))[0x24 / 4])(
        *(int *)(param_1 + 0x98), param_1 + 0xa0);
    ((void (*)(int))((void **)*(int *)(param_1 + 0x98))[0x58 / 4])(
        *(int *)(param_1 + 0x98));
    FUN_001cc7d0(param_1, DAT_002eaa48);
}
// near miss from lane fm6 (unreviewed)

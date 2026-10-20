/* HSTMATCH module=EBOOT.BIN start=0x000a8080 end=0x000a817c symbol=FUN_000a8080 lang=c99 */
extern char DAT_003386b0[];
extern float DAT_003411cc[];
extern int FUN_000b3c68(void);
extern float FUN_00163d68(int, int);
extern void FUN_00022450(float *, int *, int *);
extern void FUN_00022434(float *, int, float *);
extern float FUN_00022400(float);

int FUN_000a8080(int self, int pos, int limit)
{
    int base = *(int *)(*(int *)(DAT_003386b0 + 0x88) + 0x268);
    float scale = (float)FUN_00163d68(FUN_000b3c68(), *(int *)(self + 0x154)) * 0.01f;
    float a[4], b[4], d[2];
    int i;

    if (*(int *)(self + 0x440) > 0)
        scale = scale * DAT_003411cc[*(int *)(self + 0x440)] * 0.01f;
    FUN_00022450(a, (int *)(self + 0x580), (int *)(self + 0x5a0));
    for (i = 0; i < 4; i++)
        b[i] = a[i];
    FUN_00022434(d, pos, b);
    return (limit - base) - (int)(FUN_00022400(d[0] * d[0] + d[1] * d[1]) / scale);
}
// Near miss: sqrt helper address and the float compare/`0 <` guard layout unverified; the frame
// (0x30) and the a->b vec copy order are guesses.
// near miss from lane ds8 (unreviewed)

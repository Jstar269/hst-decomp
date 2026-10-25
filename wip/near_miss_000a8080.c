/* HSTMATCH module=EBOOT.BIN start=0x000a8080 end=0x000a817c symbol=FUN_000a8080 lang=c99 */
typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    float x, y;
} Vec2;

extern void *DAT_003386b0;
extern float DAT_003411cc[];
extern int FUN_000b3c68(void);
extern float FUN_00163d68(int, int);
extern void FUN_00022450(Vec4 *, int *, int *);
extern void FUN_00022434(Vec4 *, int, Vec4 *);
extern float sqrtf(float);

int FUN_000a8080(int self, int pos, int limit)
{
    int remaining = limit - *(int *)(*(int *)((char *)DAT_003386b0 + 0x88) + 0x268);
    float scale = 0.01f * FUN_00163d68(FUN_000b3c68(), *(int *)(self + 0x154));
    Vec4 b;
    Vec4 a;
    Vec4 d;

    if (*(int *)(self + 0x440) > 0)
        scale = scale * (0.01f * DAT_003411cc[*(int *)(self + 0x440)]);
    FUN_00022450(&a, (int *)(self + 0x580), (int *)(self + 0x5a0));
    b = a;
    FUN_00022434(&d, pos, &b);
    return remaining - (int)(sqrtf(d.x * d.x + d.z * d.z) / scale);
}
// Near miss: 63/63 words, 5 differ: retail saves a1 to s1 before a0 to s2 and materialises the first (stack) argument of FUN_00022450 before the two self-relative ones; the distance is sqrtf(d.x*d.x + d.z*d.z) on a Vec4 d at sp+0x20 and every other word matches.
// improved by lane ds9 (unreviewed): 45 -> 5 differing words

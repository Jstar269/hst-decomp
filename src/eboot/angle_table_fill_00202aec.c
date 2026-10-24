/* HSTMATCH module=EBOOT.BIN start=0x00202aec end=0x00202cb8 symbol=FUN_00202aec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag FUN_00202aec draft) corrected by hand: the four soft-float double calls are one expression (pi * ang / 2048.0), half computed before ang, struct for the count field; exact match verified; names and types await human review. */
extern int FUN_0001342c(void);
extern float FUN_0000bc34(float);
extern float FUN_0000bf34(float);

typedef struct { float a, b, c; } V3;
typedef struct {
    char pad[0xf8];
    int count;
    float rnd[40];
    V3 cs[20];
    V3 sn[20];
} Obj;

void FUN_00202aec(Obj *o, int n)
{
    int half;
    int ang;
    int i;
    char *fp;
    char *tp;
    float f;

    if (n == o->count)
        return;
    o->count = n;
    i = 0;
    if (n <= 0)
        return;
    fp = (char *)o;
    tp = (char *)o;
    do {
        *(float *)(fp + 0xfc) = (float)(FUN_0001342c() % 100) / 100.0f;
        half = (0x1000 / o->count) / 2;
        ang = ((i + 1) * 0x1000) / o->count;
        ang += FUN_0001342c() % half - half / 2;
        f = (float)(3.14159265358979323846 * ang / 2048.0);
        *(float *)(tp + 0x28c) = FUN_0000bc34(f + 1.5707964f);
        *(float *)(tp + 0x19c) = FUN_0000bf34(f + 1.5707964f);
        *(float *)(tp + 0x290) = FUN_0000bc34(f);
        *(float *)(tp + 0x1a0) = FUN_0000bf34(f);
        *(float *)(tp + 0x294) = FUN_0000bc34(f - 1.5707964f);
        *(float *)(tp + 0x1a4) = FUN_0000bf34(f - 1.5707964f);
        i++;
        fp += 4;
        tp += 12;
    } while (i < o->count);
}

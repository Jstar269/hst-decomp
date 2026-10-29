/* HSTMATCH module=EBOOT.BIN start=0x00202aec end=0x00202cb8 symbol=FUN_00202aec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag FUN_00202aec draft) corrected by hand: the four soft-float double calls are one expression (pi * ang / 2048.0), half computed before ang, struct for the count and tables; readability pass; exact match verified; names and types await human review. */
extern int FUN_0001342c(void);
extern float FUN_0000bc34(float);
extern float FUN_0000bf34(float);

#define ANGLE_STEPS 0x1000   /* the full circle is split into this many units */
#define HALF_TURN_UNITS 2048.0
#define QUARTER_TURN 1.5707964f

typedef struct { float a, b, c; } V3;
typedef struct {
    char pad[0xf8];
    int count;      /* 0xf8 number of table entries in use */
    float rnd[40];  /* 0xfc random fraction in [0,1) per entry */
    V3 cs[20];      /* 0x19c per entry: values at angle + 90, angle, angle - 90 degrees */
    V3 sn[20];      /* 0x28c same three angles through the other function */
} Obj;

/* Resizes the table to n entries: each entry gets a random value and a jittered angle slice of the circle. */
void FUN_00202aec(Obj *o, int n)
{
    int half;
    int ang;
    int i;
    float f;

    if (n == o->count)
        return;
    o->count = n;
    i = 0;
    if (n <= 0)
        return;
    do {
        o->rnd[i] = (float)(FUN_0001342c() % 100) / 100.0f;
        half = (ANGLE_STEPS / o->count) / 2;
        ang = ((i + 1) * ANGLE_STEPS) / o->count;
        ang += FUN_0001342c() % half - half / 2;
        f = (float)(3.14159265358979323846 * ang / HALF_TURN_UNITS);
        o->sn[i].a = FUN_0000bc34(f + QUARTER_TURN);
        o->cs[i].a = FUN_0000bf34(f + QUARTER_TURN);
        o->sn[i].b = FUN_0000bc34(f);
        o->cs[i].b = FUN_0000bf34(f);
        o->sn[i].c = FUN_0000bc34(f - QUARTER_TURN);
        o->cs[i].c = FUN_0000bf34(f - QUARTER_TURN);
        i++;
    } while (i < o->count);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00170a30 end=0x00170ab4 symbol=FUN_00170a30 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#define BULK_OF(a) (sizeof(a) / sizeof((a)[0]))

typedef struct Obj { char pad[0x2c]; float f2c; } Obj;
extern float DAT_003ea81c[2];   /* percentages, indexed by idx - 1 */
extern float FUN_001703f0(Obj *o, int p);

float FUN_00170a30(Obj *self, int idx, int p)
{
    float v = FUN_001703f0(self, p) * 2.0f;
    int i = idx - 1;
    if (i >= 0 && i < BULK_OF(DAT_003ea81c))
        v *= DAT_003ea81c[i] * 0.01f;
    return self->f2c + v;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0022d3ac end=0x0022d4e0 symbol=FUN_0022d3ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls FUN_002bf498 for the table index bracketing f200, stores the 28.4 fixed-point table values (first word >> 4) of entries idx and idx+1 (0 outside 0..29) in f1f0/f1f4, hands a set f20c (>= 0) to FUN_001c0018 and clears it to -1, passes idx to the f16c object (FUN_0022c6d8) and copies f1fc to f200 when f1f4 - f1f0 <= 0. Both lookups are the same inline helper: MWCC itself gives the first expansion bltz + beqzl (the table load fills the bltz slot) and the second bltzl + beqz. */
struct Ent { int value; int pad; };
struct Mode;
struct Obj {
    char pad[0x16c];
    Mode *f16c;
    char pad170[0x1f0 - 0x170];
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    char pad204[0x20c - 0x204];
    int f20c;
};
extern "C" {
extern Ent *DAT_003f4914;
extern char DAT_003eaad8[];
void FUN_002bf498(int *out_index, float *out_value, int input);
void FUN_0022d4e0(Obj *self, int idx);
void FUN_001c0018(char *, int *);
void FUN_0022c6d8(Mode *m, int mode);
void FUN_0022d6c0(Obj *self, int);
}
static inline float Value(int i)
{
    Ent *tab = DAT_003f4914;
    float f;
    if (i >= 0 && i < 30)
        f = (float)(tab[i].value >> 4);
    else
        f = 0.0f;
    return f;
}
extern "C" void FUN_0022d3ac(Obj *self)
{
    int idx;
    FUN_002bf498(&idx, 0, self->f200);
    FUN_0022d4e0(self, idx);
    self->f1f0 = (int)Value(idx);
    self->f1f4 = (int)Value(idx + 1);
    if (self->f20c >= 0) {
        FUN_001c0018(DAT_003eaad8, &self->f20c);
        self->f20c = -1;
    }
    if (self->f16c != 0)
        FUN_0022c6d8(self->f16c, idx);
    if (self->f1f4 - self->f1f0 <= 0)
        self->f200 = self->f1fc;
    FUN_0022d6c0(self, 0);
}

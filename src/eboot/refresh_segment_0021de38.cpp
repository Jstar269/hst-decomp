/* HSTMATCH module=EBOOT.BIN start=0x0021de38 end=0x0021df6c symbol=FUN_0021de38 lang=c++ */
/* Clone of src/sharing_main/refresh_segment_0022d3ac.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls FUN_002afa48 for the table index bracketing f200, stores the 28.4 fixed-point table values (first word >> 4) of entries idx and idx+1 (0 outside 0..29) in f1f0/f1f4, hands a set f20c (>= 0) to FUN_001b1f84 and clears it to -1, passes idx to the f16c object (FUN_0021d164) and copies f1fc to f200 when f1f4 - f1f0 <= 0. Both lookups are the same inline helper: MWCC itself gives the first expansion bltz + beqzl (the table load fills the bltz slot) and the second bltzl + beqz. */
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
extern Ent *DAT_0034b5d4;
extern char DAT_0034179c[];
void FUN_002afa48(int *out_index, float *out_value, int input);
void FUN_0021df6c(Obj *self, int idx);
void FUN_001b1f84(char *, int *);
void FUN_0021d164(Mode *m, int mode);
void FUN_0021e14c(Obj *self, int);
}
static inline float Value(int i)
{
    Ent *tab = DAT_0034b5d4;
    float f;
    if (i >= 0 && i < 30)
        f = (float)(tab[i].value >> 4);
    else
        f = 0.0f;
    return f;
}
extern "C" void FUN_0021de38(Obj *self)
{
    int idx;
    FUN_002afa48(&idx, 0, self->f200);
    FUN_0021df6c(self, idx);
    self->f1f0 = (int)Value(idx);
    self->f1f4 = (int)Value(idx + 1);
    if (self->f20c >= 0) {
        FUN_001b1f84(DAT_0034179c, &self->f20c);
        self->f20c = -1;
    }
    if (self->f16c != 0)
        FUN_0021d164(self->f16c, idx);
    if (self->f1f4 - self->f1f0 <= 0)
        self->f200 = self->f1fc;
    FUN_0021e14c(self, 0);
}

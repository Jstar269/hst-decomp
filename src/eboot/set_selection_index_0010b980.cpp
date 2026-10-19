/* HSTMATCH module=EBOOT.BIN start=0x0010b980 end=0x0010ba20 symbol=FUN_0010b980 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inline Clamp with const ref bounds and ternary flag; exact match verified; names and types await human review. */

extern const int DAT_002d921c;

struct Item12 {
    short s0;
    char pad[10];
};

struct Obj {
    char pad0[0xd0];
    int f208;
    char pad1[0x8];
    int f220;
    int f224;
    int f228;
    char pad2[0x2];
    char f234;
    char pad3[0x35];
    Item12 *f288;
};

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_0010b980(Obj *self, int val, int flag)
{
    int hi = self->f228 - self->f224;
    int new_val = Clamp(val, DAT_002d921c, hi);
    int old_val = self->f220;

    if (old_val != new_val || flag) {
        self->f208 = (self->f288[old_val].s0 != self->f288[new_val].s0) ? 3 : 0;
        self->f234 = 1;
    }
    self->f220 = new_val;
}

/* HSTMATCH module=EBOOT.BIN start=0x00231ba0 end=0x00231c5c symbol=FUN_00231ba0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: restored self argument to FUN_00231c5c, inline SetIndex helper with != first and two-case switch on field_1dc, and &DAT_0034179c; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_0034179c;
int FUN_001b1c44(void *, int);
void FUN_00231c5c(void *);
void FUN_00231f84(void *, int *, float *);
void FUN_00232558(void *, int);
}

struct Obj_00231ba0 {
    char pad[0x1dc];
    int field_1dc;
    int field_1e0;
    int field_1e4;
    unsigned char field_1e8;
};

static inline void SetIndex(Obj_00231ba0 *self, int val)
{
    if (self->field_1e0 != val) {
        FUN_001b1c44(&DAT_0034179c, 1);
        self->field_1e0 = val;
    } else {
        self->field_1e0 = val;
    }
    switch (self->field_1dc) {
    case 0:
        break;
    case 1:
        FUN_00232558(self, self->field_1e0);
        break;
    }
}

extern "C" void FUN_00231ba0(Obj_00231ba0 *self)
{
    if (self->field_1e8 == 0 && self->field_1dc == 0) {
        FUN_00231c5c(self);
    }
    if (self->field_1dc == 0 && self->field_1e8 != 0) {
        self->field_1e8 = 0;
        int idx;
        float dist;
        FUN_00231f84(self, &idx, &dist);
        SetIndex(self, idx);
    }
}

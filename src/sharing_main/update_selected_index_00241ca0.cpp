/* HSTMATCH module=hstp_trans_main.prx start=0x00241ca0 end=0x00241d5c symbol=FUN_00241ca0 lang=c++ */
/* Clone of src/eboot/update_selected_index_00231ba0.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: restored self argument to FUN_00241d5c, inline SetIndex helper with != first and two-case switch on field_1dc, and &DAT_003eaad8; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003eaad8;
int FUN_001bfc3c(void *, int);
void FUN_00241d5c(void *);
void FUN_00242084(void *, int *, float *);
void FUN_00242658(void *, int);
}

struct Obj_00241ca0 {
    char pad[0x1dc];
    int field_1dc;
    int field_1e0;
    int field_1e4;
    unsigned char field_1e8;
};

static inline void SetIndex(Obj_00241ca0 *self, int val)
{
    if (self->field_1e0 != val) {
        FUN_001bfc3c(&DAT_003eaad8, 1);
        self->field_1e0 = val;
    } else {
        self->field_1e0 = val;
    }
    switch (self->field_1dc) {
    case 0:
        break;
    case 1:
        FUN_00242658(self, self->field_1e0);
        break;
    }
}

extern "C" void FUN_00241ca0(Obj_00241ca0 *self)
{
    if (self->field_1e8 == 0 && self->field_1dc == 0) {
        FUN_00241d5c(self);
    }
    if (self->field_1dc == 0 && self->field_1e8 != 0) {
        self->field_1e8 = 0;
        int idx;
        float dist;
        FUN_00242084(self, &idx, &dist);
        SetIndex(self, idx);
    }
}

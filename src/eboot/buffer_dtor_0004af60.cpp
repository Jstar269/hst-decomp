/* HSTMATCH module=EBOOT.BIN start=0x0004af60 end=0x0004afe0 symbol=FUN_0004af60 lang=c++ */
/* Clone of src/sharing_main/buffer_dtor_0004b13c.cpp (hstclone.py tag s10172123g5r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: nested null check on m0 in C++ (matching idiom); exact match verified; names and types await human review. */

extern "C" {
void FUN_000006e8(void *, void *);
void FUN_000104e0(void *);
void FUN_0004a1a4(void);
}

struct Obj {
    void *m0;
    void *m4;
    void *m8;
};

extern "C" void FUN_0004af60(Obj *self)
{
    if (self->m8) {
        FUN_000006e8(self->m8, (void *)FUN_0004a1a4);
        self->m8 = 0;
    }
    if (self->m4) {
        FUN_000104e0(self->m4);
        self->m4 = 0;
    }
    if (self->m0) {
        if (self->m0) {
            FUN_000104e0(self->m0);
            self->m0 = 0;
        }
    }
    self->m0 = 0;
    self->m4 = 0;
    self->m8 = 0;
}

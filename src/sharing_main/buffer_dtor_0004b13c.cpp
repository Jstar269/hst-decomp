/* HSTMATCH module=hstp_trans_main.prx start=0x0004b13c end=0x0004b1bc symbol=FUN_0004b13c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: nested null check on m0 in C++ (matching idiom); exact match verified; names and types await human review. */

extern "C" {
void FUN_000006e8(void *, void *);
void FUN_000104e0(void *);
void FUN_0004a174(void);
}

struct Obj {
    void *m0;
    void *m4;
    void *m8;
};

extern "C" void FUN_0004b13c(Obj *self)
{
    if (self->m8) {
        FUN_000006e8(self->m8, (void *)FUN_0004a174);
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

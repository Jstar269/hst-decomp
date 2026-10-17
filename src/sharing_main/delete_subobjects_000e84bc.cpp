/* HSTMATCH module=hstp_trans_main.prx start=0x000e84bc end=0x000e8534 symbol=FUN_000e84bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Sub {
    virtual ~Sub();
};

struct Elem {
    Elem();
};

struct Obj {
    char pad[0x40];
    Sub *sub; // 0x40
    char pad2[0xc];
    Elem *arr; // 0x50
};

extern "C" void FUN_000e8534(Obj *self);

extern "C" void FUN_000e84bc(Obj *self) {
    if (self->arr != 0) {
        FUN_000e8534(self);
        if (self->arr != 0) {
            delete[] self->arr;
            self->arr = 0;
        }
    }
    if (self->sub != 0) {
        delete self->sub;
        self->sub = 0;
    }
}

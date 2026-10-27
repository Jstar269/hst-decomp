/* HSTMATCH module=hstp_trans_main.prx start=0x00229f60 end=0x00229fa8 symbol=FUN_00229f60 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Child {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Self {
    char pad[0xe0];
    Child *child;
};

extern "C" void FUN_00108aec(Self *self);

extern "C" void FUN_00229f60(Self *self)
{
    if (self->child != 0) {
        self->child->v3();
    }
    FUN_00108aec(self);
}

/* HSTMATCH module=EBOOT.BIN start=0x0021a9ec end=0x0021aa34 symbol=FUN_0021a9ec lang=c++ */
/* Hand-written reconstruction from the disassembly (same source as the Sharing twin src/sharing_main/call_slot3_then_notify_00229f60.cpp, addresses substituted); exact match verified; names and types await human review. */
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

extern "C" void FUN_001031e8(Self *self);

extern "C" void FUN_0021a9ec(Self *self)
{
    if (self->child != 0) {
        self->child->v3();
    }
    FUN_001031e8(self);
}

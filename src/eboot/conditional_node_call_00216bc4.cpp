/* HSTMATCH module=EBOOT.BIN start=0x00216bc4 end=0x00216c28 symbol=FUN_00216bc4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: modeled the indirect call as the first virtual member; exact match verified; names and types await human review. */
struct Node {
    virtual void update(int) = 0;
};
struct Owner {
    int pad;
    Node *node;
};
extern "C" void FUN_00000a00(void *);

extern "C" Owner *FUN_00216bc4(Owner *self, short count)
{
    if (self != 0) {
        if (self->node != 0) {
            self->node->update(1);
        }
        if (count > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}

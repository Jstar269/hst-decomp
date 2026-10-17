/* HSTMATCH module=hstp_trans_main.prx start=0x00225bc8 end=0x00225c2c symbol=FUN_00225bc8 lang=c++ */
/* Clone of src/eboot/conditional_node_call_00216bc4.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: modeled the indirect call as the first virtual member; exact match verified; names and types await human review. */
struct Node {
    virtual void update(int) = 0;
};
struct Owner {
    int pad;
    Node *node;
};
extern "C" void FUN_00000a00(void *);

extern "C" Owner *FUN_00225bc8(Owner *self, short count)
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

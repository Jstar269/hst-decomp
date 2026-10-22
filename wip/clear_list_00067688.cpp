/* HSTMATCH module=EBOOT.BIN start=0x00067688 end=0x00067730 symbol=FUN_00067688 lang=c++ */
/* NEAR MISS: 42/42 words, 6 differ.  Walks a linked list of 12-byte nodes: every node points at a
   polymorphic value whose vtable slot 1 is called with the float at +0x48 of the object and, when
   the value's byte at +0x10 is set, slot 0 is called with 1 and the list is advanced by
   FUN_000679cc.
   MATCHED: the frame (48 bytes, five saved registers), the register allocation (the value, the node
   and the sentinel pointer in s2/s1/s0, the object in s3), the virtual calls through the vtable
   slots 0 and 1, and the list walk.
   DIFFERENCE: retail's test of the flag byte is a branch-likely (`beqzl v1`) while ours is a plain
   `beqz`, and retail stores the copy of the node pointer into the local at +0x24 only once (in the
   delay slot of the FUN_000679cc call) while MWCC hoists that store before the indirect call and
   repeats it afterwards because the local is address-taken.
   RULED OUT: the flag test written as `if (v->f10)` or `== 0`, the local as a Node * instead of an
   int, the local declared at function scope, and the "flag == 0" case written first. */
struct Value {
    virtual void slot0(int n);
    virtual void slot1(float f);
    char pad[12];
    unsigned char f10;
};

struct Node {
    void *vptr;
    Node *next;
    Value *value;
};

struct Obj {
    char pad[0x3c];
    void *f3c;
    Node *sentinel;
    Node *head;
    float f48;
};

extern "C" void FUN_000679cc(int *out, void *ctx, int *p);

extern "C" void FUN_00067688(Obj *self)
{
    Value *v;
    Node *p = self->head;
    Node *end = (Node *)&self->sentinel;
    while (p != end) {
        v = p->value;
        v->slot1(self->f48);
        p = p->next;
        if (v->f10 != 0) {
            if (v != 0) {
                v->slot0(1);
            }
            int out[2];
            int c = (int)p;
            FUN_000679cc(out, self->f3c, &c);
            p = (Node *)out[0];
        }
    }
}
// near miss from lane om1 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x0001f294 end=0x0001f2f8 symbol=FUN_0001f294 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); exact match verified; names and types await human review. Steering trick: the unused empty by-value Tag parameter on FUN_0001f294 exists only for the frame/stack slots. */
struct Tag
{
};

struct Releasable
{
    virtual void release(int mode);
};

struct Node
{
    char pad00[8];
    Releasable *obj;
};

struct Holder
{
    int pad00;
    int pad04;
    int count;
    Node *node;
};

extern "C" void FUN_0001f294(Holder *self, Tag tag)
{
    if (!self->count)
        return;
    Node **pp = &self->node;
    while (self->count)
    {
        Node *n = *pp;
        if (n->obj)
            n->obj->release(1);
    }
}

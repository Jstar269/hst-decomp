/* HSTMATCH module=EBOOT.BIN start=0x00067a3c end=0x00067b28 symbol=FUN_00067a3c lang=c++ */
/* Clone of src/eboot/list_insert_0014f228.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list insert(pos, x) for a 4-byte value (sibling of the erase at 0x14f188): allocate a 12-byte
   node into a holder referencing the allocator (empty, at list+4), copy-construct the value through the raw
   node pointer (constructing through the holder's get() swaps s4/s5), release, link before pos, ++size and
   return the new iterator by value (hidden return pointer in a0, v0 = 0). Names provisional. */
extern "C" {
struct Reent_00067a3c { int pad[3]; void *err; };
Reent_00067a3c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002bc650[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) throw() { return p; }

typedef int Value_00067a3c;
struct Node_00067a3c {
    Node_00067a3c *prev_;
    Node_00067a3c *next_;
    Value_00067a3c value_;
};
struct Alloc_00067a3c {
    Node_00067a3c *allocate(unsigned n)
    {
        Node_00067a3c *p = (Node_00067a3c *)FUN_00000bcc(n * sizeof(Node_00067a3c));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc650);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_00067a3c *p) { FUN_00000a00(p); }
};
struct Holder_00067a3c {
    Alloc_00067a3c *a_;
    Node_00067a3c *p_;
    Holder_00067a3c(Alloc_00067a3c &a, Node_00067a3c *p) : a_(&a), p_(p) {}
    ~Holder_00067a3c() { if (p_) a_->deallocate(p_); }
    Node_00067a3c *release() { Node_00067a3c *t = p_; p_ = 0; return t; }
};
struct It_00067a3c {
    Node_00067a3c *node_;
    It_00067a3c(Node_00067a3c *n) : node_(n) {}
};
struct List_00067a3c {
    unsigned size_;
    Node_00067a3c *head_;
    Alloc_00067a3c &alloc() { return *(Alloc_00067a3c *)&head_; }
};

extern "C" It_00067a3c FUN_00067a3c(List_00067a3c *l, const It_00067a3c &pos, const Value_00067a3c &x)
{
    Alloc_00067a3c &a = l->alloc();
    Node_00067a3c *m = a.allocate(1);
    Holder_00067a3c h(a, m);
    new (&m->value_) Value_00067a3c(x);
    Node_00067a3c *n = h.release();
    Node_00067a3c *p = pos.node_;
    p->prev_->next_ = n;
    n->prev_ = p->prev_;
    p->prev_ = n;
    n->next_ = p;
    ++l->size_;
    return It_00067a3c(n);
}

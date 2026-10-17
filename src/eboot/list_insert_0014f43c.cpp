/* HSTMATCH module=EBOOT.BIN start=0x0014f43c end=0x0014f528 symbol=FUN_0014f43c lang=c++ */
/* Clone of src/eboot/list_insert_0014f228.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list insert(pos, x) for a 4-byte value (sibling of the erase at 0x14f188): allocate a 12-byte
   node into a holder referencing the allocator (empty, at list+4), copy-construct the value through the raw
   node pointer (constructing through the holder's get() swaps s4/s5), release, link before pos, ++size and
   return the new iterator by value (hidden return pointer in a0, v0 = 0). Names provisional. */
extern "C" {
struct Reent_0014f43c { int pad[3]; void *err; };
Reent_0014f43c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002c1ac8[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) throw() { return p; }

typedef int Value_0014f43c;
struct Node_0014f43c {
    Node_0014f43c *prev_;
    Node_0014f43c *next_;
    Value_0014f43c value_;
};
struct Alloc_0014f43c {
    Node_0014f43c *allocate(unsigned n)
    {
        Node_0014f43c *p = (Node_0014f43c *)FUN_00000bcc(n * sizeof(Node_0014f43c));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1ac8);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_0014f43c *p) { FUN_00000a00(p); }
};
struct Holder_0014f43c {
    Alloc_0014f43c *a_;
    Node_0014f43c *p_;
    Holder_0014f43c(Alloc_0014f43c &a, Node_0014f43c *p) : a_(&a), p_(p) {}
    ~Holder_0014f43c() { if (p_) a_->deallocate(p_); }
    Node_0014f43c *release() { Node_0014f43c *t = p_; p_ = 0; return t; }
};
struct It_0014f43c {
    Node_0014f43c *node_;
    It_0014f43c(Node_0014f43c *n) : node_(n) {}
};
struct List_0014f43c {
    unsigned size_;
    Node_0014f43c *head_;
    Alloc_0014f43c &alloc() { return *(Alloc_0014f43c *)&head_; }
};

extern "C" It_0014f43c FUN_0014f43c(List_0014f43c *l, const It_0014f43c &pos, const Value_0014f43c &x)
{
    Alloc_0014f43c &a = l->alloc();
    Node_0014f43c *m = a.allocate(1);
    Holder_0014f43c h(a, m);
    new (&m->value_) Value_0014f43c(x);
    Node_0014f43c *n = h.release();
    Node_0014f43c *p = pos.node_;
    p->prev_->next_ = n;
    n->prev_ = p->prev_;
    p->prev_ = n;
    n->next_ = p;
    ++l->size_;
    return It_0014f43c(n);
}

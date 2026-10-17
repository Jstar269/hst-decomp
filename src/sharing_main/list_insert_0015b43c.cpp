/* HSTMATCH module=hstp_trans_main.prx start=0x0015b43c end=0x0015b528 symbol=FUN_0015b43c lang=c++ */
/* Clone of src/eboot/list_insert_0001f75c.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list insert(pos, x) for a 4-byte value (sibling of the erase at 0x14f188): allocate a 12-byte
   node into a holder referencing the allocator (empty, at list+4), copy-construct the value through the raw
   node pointer (constructing through the holder's get() swaps s4/s5), release, link before pos, ++size and
   return the new iterator by value (hidden return pointer in a0, v0 = 0). Names provisional. */
extern "C" {
struct Reent_0015b43c { int pad[3]; void *err; };
Reent_0015b43c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002d1ea8[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) throw() { return p; }

typedef int Value_0015b43c;
struct Node_0015b43c {
    Node_0015b43c *prev_;
    Node_0015b43c *next_;
    Value_0015b43c value_;
};
struct Alloc_0015b43c {
    Node_0015b43c *allocate(unsigned n)
    {
        Node_0015b43c *p = (Node_0015b43c *)FUN_00000bcc(n * sizeof(Node_0015b43c));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1ea8);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_0015b43c *p) { FUN_00000a00(p); }
};
struct Holder_0015b43c {
    Alloc_0015b43c *a_;
    Node_0015b43c *p_;
    Holder_0015b43c(Alloc_0015b43c &a, Node_0015b43c *p) : a_(&a), p_(p) {}
    ~Holder_0015b43c() { if (p_) a_->deallocate(p_); }
    Node_0015b43c *release() { Node_0015b43c *t = p_; p_ = 0; return t; }
};
struct It_0015b43c {
    Node_0015b43c *node_;
    It_0015b43c(Node_0015b43c *n) : node_(n) {}
};
struct List_0015b43c {
    unsigned size_;
    Node_0015b43c *head_;
    Alloc_0015b43c &alloc() { return *(Alloc_0015b43c *)&head_; }
};

extern "C" It_0015b43c FUN_0015b43c(List_0015b43c *l, const It_0015b43c &pos, const Value_0015b43c &x)
{
    Alloc_0015b43c &a = l->alloc();
    Node_0015b43c *m = a.allocate(1);
    Holder_0015b43c h(a, m);
    new (&m->value_) Value_0015b43c(x);
    Node_0015b43c *n = h.release();
    Node_0015b43c *p = pos.node_;
    p->prev_->next_ = n;
    n->prev_ = p->prev_;
    p->prev_ = n;
    n->next_ = p;
    ++l->size_;
    return It_0015b43c(n);
}

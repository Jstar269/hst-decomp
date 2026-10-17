/* HSTMATCH module=EBOOT.BIN start=0x0001f75c end=0x0001f848 symbol=FUN_0001f75c lang=c++ */
/* Clone of src/eboot/list_insert_0014f228.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list insert(pos, x) for a 4-byte value (sibling of the erase at 0x14f188): allocate a 12-byte
   node into a holder referencing the allocator (empty, at list+4), copy-construct the value through the raw
   node pointer (constructing through the holder's get() swaps s4/s5), release, link before pos, ++size and
   return the new iterator by value (hidden return pointer in a0, v0 = 0). Names provisional. */
extern "C" {
struct Reent_0001f75c { int pad[3]; void *err; };
Reent_0001f75c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002bb580[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) throw() { return p; }

typedef int Value_0001f75c;
struct Node_0001f75c {
    Node_0001f75c *prev_;
    Node_0001f75c *next_;
    Value_0001f75c value_;
};
struct Alloc_0001f75c {
    Node_0001f75c *allocate(unsigned n)
    {
        Node_0001f75c *p = (Node_0001f75c *)FUN_00000bcc(n * sizeof(Node_0001f75c));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bb580);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_0001f75c *p) { FUN_00000a00(p); }
};
struct Holder_0001f75c {
    Alloc_0001f75c *a_;
    Node_0001f75c *p_;
    Holder_0001f75c(Alloc_0001f75c &a, Node_0001f75c *p) : a_(&a), p_(p) {}
    ~Holder_0001f75c() { if (p_) a_->deallocate(p_); }
    Node_0001f75c *release() { Node_0001f75c *t = p_; p_ = 0; return t; }
};
struct It_0001f75c {
    Node_0001f75c *node_;
    It_0001f75c(Node_0001f75c *n) : node_(n) {}
};
struct List_0001f75c {
    unsigned size_;
    Node_0001f75c *head_;
    Alloc_0001f75c &alloc() { return *(Alloc_0001f75c *)&head_; }
};

extern "C" It_0001f75c FUN_0001f75c(List_0001f75c *l, const It_0001f75c &pos, const Value_0001f75c &x)
{
    Alloc_0001f75c &a = l->alloc();
    Node_0001f75c *m = a.allocate(1);
    Holder_0001f75c h(a, m);
    new (&m->value_) Value_0001f75c(x);
    Node_0001f75c *n = h.release();
    Node_0001f75c *p = pos.node_;
    p->prev_->next_ = n;
    n->prev_ = p->prev_;
    p->prev_ = n;
    n->next_ = p;
    ++l->size_;
    return It_0001f75c(n);
}

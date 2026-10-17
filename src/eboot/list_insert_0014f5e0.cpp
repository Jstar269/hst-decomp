/* HSTMATCH module=EBOOT.BIN start=0x0014f5e0 end=0x0014f6cc symbol=FUN_0014f5e0 lang=c++ */
/* Clone of src/eboot/list_insert_0014f228.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list insert(pos, x) for a 4-byte value (sibling of the erase at 0x14f188): allocate a 12-byte
   node into a holder referencing the allocator (empty, at list+4), copy-construct the value through the raw
   node pointer (constructing through the holder's get() swaps s4/s5), release, link before pos, ++size and
   return the new iterator by value (hidden return pointer in a0, v0 = 0). Names provisional. */
extern "C" {
struct Reent_0014f5e0 { int pad[3]; void *err; };
Reent_0014f5e0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002c1aac[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) throw() { return p; }

typedef int Value_0014f5e0;
struct Node_0014f5e0 {
    Node_0014f5e0 *prev_;
    Node_0014f5e0 *next_;
    Value_0014f5e0 value_;
};
struct Alloc_0014f5e0 {
    Node_0014f5e0 *allocate(unsigned n)
    {
        Node_0014f5e0 *p = (Node_0014f5e0 *)FUN_00000bcc(n * sizeof(Node_0014f5e0));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1aac);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_0014f5e0 *p) { FUN_00000a00(p); }
};
struct Holder_0014f5e0 {
    Alloc_0014f5e0 *a_;
    Node_0014f5e0 *p_;
    Holder_0014f5e0(Alloc_0014f5e0 &a, Node_0014f5e0 *p) : a_(&a), p_(p) {}
    ~Holder_0014f5e0() { if (p_) a_->deallocate(p_); }
    Node_0014f5e0 *release() { Node_0014f5e0 *t = p_; p_ = 0; return t; }
};
struct It_0014f5e0 {
    Node_0014f5e0 *node_;
    It_0014f5e0(Node_0014f5e0 *n) : node_(n) {}
};
struct List_0014f5e0 {
    unsigned size_;
    Node_0014f5e0 *head_;
    Alloc_0014f5e0 &alloc() { return *(Alloc_0014f5e0 *)&head_; }
};

extern "C" It_0014f5e0 FUN_0014f5e0(List_0014f5e0 *l, const It_0014f5e0 &pos, const Value_0014f5e0 &x)
{
    Alloc_0014f5e0 &a = l->alloc();
    Node_0014f5e0 *m = a.allocate(1);
    Holder_0014f5e0 h(a, m);
    new (&m->value_) Value_0014f5e0(x);
    Node_0014f5e0 *n = h.release();
    Node_0014f5e0 *p = pos.node_;
    p->prev_->next_ = n;
    n->prev_ = p->prev_;
    p->prev_ = n;
    n->next_ = p;
    ++l->size_;
    return It_0014f5e0(n);
}

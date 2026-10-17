/* HSTMATCH module=hstp_trans_main.prx start=0x0001f784 end=0x0001f870 symbol=FUN_0001f784 lang=c++ */
/* Clone of src/eboot/list_insert_0001f75c.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list insert(pos, x) for a 4-byte value (sibling of the erase at 0x14f188): allocate a 12-byte
   node into a holder referencing the allocator (empty, at list+4), copy-construct the value through the raw
   node pointer (constructing through the holder's get() swaps s4/s5), release, link before pos, ++size and
   return the new iterator by value (hidden return pointer in a0, v0 = 0). Names provisional. */
extern "C" {
struct Reent_0001f784 { int pad[3]; void *err; };
Reent_0001f784 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002cb300[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) throw() { return p; }

typedef int Value_0001f784;
struct Node_0001f784 {
    Node_0001f784 *prev_;
    Node_0001f784 *next_;
    Value_0001f784 value_;
};
struct Alloc_0001f784 {
    Node_0001f784 *allocate(unsigned n)
    {
        Node_0001f784 *p = (Node_0001f784 *)FUN_00000bcc(n * sizeof(Node_0001f784));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cb300);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_0001f784 *p) { FUN_00000a00(p); }
};
struct Holder_0001f784 {
    Alloc_0001f784 *a_;
    Node_0001f784 *p_;
    Holder_0001f784(Alloc_0001f784 &a, Node_0001f784 *p) : a_(&a), p_(p) {}
    ~Holder_0001f784() { if (p_) a_->deallocate(p_); }
    Node_0001f784 *release() { Node_0001f784 *t = p_; p_ = 0; return t; }
};
struct It_0001f784 {
    Node_0001f784 *node_;
    It_0001f784(Node_0001f784 *n) : node_(n) {}
};
struct List_0001f784 {
    unsigned size_;
    Node_0001f784 *head_;
    Alloc_0001f784 &alloc() { return *(Alloc_0001f784 *)&head_; }
};

extern "C" It_0001f784 FUN_0001f784(List_0001f784 *l, const It_0001f784 &pos, const Value_0001f784 &x)
{
    Alloc_0001f784 &a = l->alloc();
    Node_0001f784 *m = a.allocate(1);
    Holder_0001f784 h(a, m);
    new (&m->value_) Value_0001f784(x);
    Node_0001f784 *n = h.release();
    Node_0001f784 *p = pos.node_;
    p->prev_->next_ = n;
    n->prev_ = p->prev_;
    p->prev_ = n;
    n->next_ = p;
    ++l->size_;
    return It_0001f784(n);
}

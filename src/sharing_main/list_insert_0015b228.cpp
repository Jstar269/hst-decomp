/* HSTMATCH module=hstp_trans_main.prx start=0x0015b228 end=0x0015b314 symbol=FUN_0015b228 lang=c++ */
/* Clone of src/eboot/list_insert_0001f75c.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Doubly-linked list insert(pos, x) for a 4-byte value (sibling of the erase at 0x14f188): allocate a 12-byte
   node into a holder referencing the allocator (empty, at list+4), copy-construct the value through the raw
   node pointer (constructing through the holder's get() swaps s4/s5), release, link before pos, ++size and
   return the new iterator by value (hidden return pointer in a0, v0 = 0). Names provisional. */
extern "C" {
struct Reent_0015b228 { int pad[3]; void *err; };
Reent_0015b228 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002d1ec4[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) throw() { return p; }

typedef int Value_0015b228;
struct Node_0015b228 {
    Node_0015b228 *prev_;
    Node_0015b228 *next_;
    Value_0015b228 value_;
};
struct Alloc_0015b228 {
    Node_0015b228 *allocate(unsigned n)
    {
        Node_0015b228 *p = (Node_0015b228 *)FUN_00000bcc(n * sizeof(Node_0015b228));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1ec4);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_0015b228 *p) { FUN_00000a00(p); }
};
struct Holder_0015b228 {
    Alloc_0015b228 *a_;
    Node_0015b228 *p_;
    Holder_0015b228(Alloc_0015b228 &a, Node_0015b228 *p) : a_(&a), p_(p) {}
    ~Holder_0015b228() { if (p_) a_->deallocate(p_); }
    Node_0015b228 *release() { Node_0015b228 *t = p_; p_ = 0; return t; }
};
struct It_0015b228 {
    Node_0015b228 *node_;
    It_0015b228(Node_0015b228 *n) : node_(n) {}
};
struct List_0015b228 {
    unsigned size_;
    Node_0015b228 *head_;
    Alloc_0015b228 &alloc() { return *(Alloc_0015b228 *)&head_; }
};

extern "C" It_0015b228 FUN_0015b228(List_0015b228 *l, const It_0015b228 &pos, const Value_0015b228 &x)
{
    Alloc_0015b228 &a = l->alloc();
    Node_0015b228 *m = a.allocate(1);
    Holder_0015b228 h(a, m);
    new (&m->value_) Value_0015b228(x);
    Node_0015b228 *n = h.release();
    Node_0015b228 *p = pos.node_;
    p->prev_->next_ = n;
    n->prev_ = p->prev_;
    p->prev_ = n;
    n->next_ = p;
    ++l->size_;
    return It_0015b228(n);
}

/* HSTMATCH module=EBOOT.BIN start=0x0006d160 end=0x0006d2b0 symbol=FUN_0006d160 lang=c++ */
/* Clone of src/eboot/tree_insert_node_0019695c.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert-at: length check ("tree::insert length_error"), allocate a 20-byte node into a
   holder that references the allocator (an empty member at tree+4), copy-construct the 8-byte value,
   release, link under the parent, ++size, rebalance (0x6445c), update leftmost. Names provisional. */
extern "C" {
struct Reent_0006d160 { int pad[3]; void *err; };
Reent_0006d160 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002d12c4[];
extern char DAT_002bc688[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct Value_0006d160 {
    int a, b;
    Value_0006d160(const Value_0006d160 &o) : a(o.a), b(o.b) {}
};
struct Node_0006d160 {
    Node_0006d160 *left_;
    Node_0006d160 *right_;
    unsigned parent_;
    Value_0006d160 value_;
    void set_parent(Node_0006d160 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_0006445c(Node_0006d160 *x, Node_0006d160 *root);

struct Alloc_0006d160 {
    Node_0006d160 *allocate(unsigned n)
    {
        Node_0006d160 *p = (Node_0006d160 *)FUN_00000bcc(n * sizeof(Node_0006d160));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc688);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_0006d160 *p) { FUN_00000a00(p); }
};

struct Holder_0006d160 {
    Alloc_0006d160 *a_;
    Node_0006d160 *p_;
    Holder_0006d160(Alloc_0006d160 &a, Node_0006d160 *p) : a_(&a), p_(p) {}
    ~Holder_0006d160() { if (p_) a_->deallocate(p_); }
    Node_0006d160 *get() const { return p_; }
    Node_0006d160 *release() { Node_0006d160 *t = p_; p_ = 0; return t; }
};

struct Tree_0006d160 {
    unsigned size_;
    Node_0006d160 *root_;
    Node_0006d160 *x8_;
    Node_0006d160 *leftmost_;
    Alloc_0006d160 &alloc() { return *(Alloc_0006d160 *)&root_; }
};

extern "C" Node_0006d160 *FUN_0006d160(Tree_0006d160 *t, Node_0006d160 *parent, bool left, bool leftmost,
                                       const Value_0006d160 &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d12c4);
        FUN_0000d518();
    }
    Alloc_0006d160 &a = t->alloc();
    Holder_0006d160 h(a, a.allocate(1));
    new (&h.get()->value_) Value_0006d160(v);
    Node_0006d160 *n = h.release();
    n->left_ = n->right_ = 0;
    n->set_parent(parent);
    if (left)
        parent->left_ = n;
    else
        parent->right_ = n;
    ++t->size_;
    FUN_0006445c(n, t->root_);
    if (leftmost)
        t->leftmost_ = n;
    return n;
}

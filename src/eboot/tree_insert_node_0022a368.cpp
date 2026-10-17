/* HSTMATCH module=EBOOT.BIN start=0x0022a368 end=0x0022a4b8 symbol=FUN_0022a368 lang=c++ */
/* Clone of src/eboot/tree_insert_node_0019695c.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert-at: length check ("tree::insert length_error"), allocate a 20-byte node into a
   holder that references the allocator (an empty member at tree+4), copy-construct the 8-byte value,
   release, link under the parent, ++size, rebalance (0x6445c), update leftmost. Names provisional. */
extern "C" {
struct Reent_0022a368 { int pad[3]; void *err; };
Reent_0022a368 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002f2b5c[];
extern char DAT_002c9a48[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct Value_0022a368 {
    int a, b;
    Value_0022a368(const Value_0022a368 &o) : a(o.a), b(o.b) {}
};
struct Node_0022a368 {
    Node_0022a368 *left_;
    Node_0022a368 *right_;
    unsigned parent_;
    Value_0022a368 value_;
    void set_parent(Node_0022a368 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_0006445c(Node_0022a368 *x, Node_0022a368 *root);

struct Alloc_0022a368 {
    Node_0022a368 *allocate(unsigned n)
    {
        Node_0022a368 *p = (Node_0022a368 *)FUN_00000bcc(n * sizeof(Node_0022a368));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c9a48);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_0022a368 *p) { FUN_00000a00(p); }
};

struct Holder_0022a368 {
    Alloc_0022a368 *a_;
    Node_0022a368 *p_;
    Holder_0022a368(Alloc_0022a368 &a, Node_0022a368 *p) : a_(&a), p_(p) {}
    ~Holder_0022a368() { if (p_) a_->deallocate(p_); }
    Node_0022a368 *get() const { return p_; }
    Node_0022a368 *release() { Node_0022a368 *t = p_; p_ = 0; return t; }
};

struct Tree_0022a368 {
    unsigned size_;
    Node_0022a368 *root_;
    Node_0022a368 *x8_;
    Node_0022a368 *leftmost_;
    Alloc_0022a368 &alloc() { return *(Alloc_0022a368 *)&root_; }
};

extern "C" Node_0022a368 *FUN_0022a368(Tree_0022a368 *t, Node_0022a368 *parent, bool left, bool leftmost,
                                       const Value_0022a368 &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002f2b5c);
        FUN_0000d518();
    }
    Alloc_0022a368 &a = t->alloc();
    Holder_0022a368 h(a, a.allocate(1));
    new (&h.get()->value_) Value_0022a368(v);
    Node_0022a368 *n = h.release();
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

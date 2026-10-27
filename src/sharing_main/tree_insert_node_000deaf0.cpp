/* HSTMATCH module=hstp_trans_main.prx start=0x000deaf0 end=0x000dec48 symbol=FUN_000deaf0 lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the same MSL tree-insert code as src/eboot/tree_insert_node_0006cc5c.cpp; 28-byte node, out-of-line 16-byte value copy ctor, errors reported through the empty print stub 0xdd96c); exact match verified; names and types await human review. */
extern "C" {
struct Reent_000deaf0 { int pad[3]; void *err; };
Reent_000deaf0 *FUN_0000fe3c(void);
void FUN_000dd96c(...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
void *FUN_00002f60(unsigned size, void *p);
void FUN_000dec48(void *dst, const void *src);
extern char DAT_0037d708[];
extern char DAT_002d08e8[];
}

struct Value_000deaf0 {
    char b[16];
};
struct Node_000deaf0 {
    Node_000deaf0 *left_;
    Node_000deaf0 *right_;
    unsigned parent_;
    Value_000deaf0 value_;
    void set_parent(Node_000deaf0 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_00065320(Node_000deaf0 *x, Node_000deaf0 *root);

struct Alloc_000deaf0 {
    Node_000deaf0 *allocate(unsigned n)
    {
        Node_000deaf0 *p = (Node_000deaf0 *)FUN_00000bcc(n * sizeof(Node_000deaf0));
        if (p == 0) {
            FUN_000dd96c(FUN_0000fe3c()->err, DAT_002d08e8);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_000deaf0 *p) { FUN_00000a00(p); }
};

struct Holder_000deaf0 {
    Alloc_000deaf0 *a_;
    Node_000deaf0 *p_;
    Holder_000deaf0(Alloc_000deaf0 &a, Node_000deaf0 *p) : a_(&a), p_(p) {}
    ~Holder_000deaf0() { if (p_) a_->deallocate(p_); }
    Node_000deaf0 *get() const { return p_; }
    Node_000deaf0 *release() { Node_000deaf0 *t = p_; p_ = 0; return t; }
};

struct Tree_000deaf0 {
    unsigned size_;
    Node_000deaf0 *root_;
    Node_000deaf0 *x8_;
    Node_000deaf0 *leftmost_;
    Alloc_000deaf0 &alloc() { return *(Alloc_000deaf0 *)&root_; }
};

extern "C" Node_000deaf0 *FUN_000deaf0(Tree_000deaf0 *t, Node_000deaf0 *parent, bool left, bool leftmost,
                                       const Value_000deaf0 &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_000dd96c(FUN_0000fe3c()->err, DAT_0037d708);
        FUN_0000d530();
    }
    Alloc_000deaf0 &a = t->alloc();
    Holder_000deaf0 h(a, a.allocate(1));
    Value_000deaf0 *q = (Value_000deaf0 *)FUN_00002f60(sizeof(Value_000deaf0), &h.get()->value_);
    if (q != 0)
        FUN_000dec48(q, &v);
    Node_000deaf0 *n = h.release();
    n->left_ = n->right_ = 0;
    n->set_parent(parent);
    if (left)
        parent->left_ = n;
    else
        parent->right_ = n;
    ++t->size_;
    FUN_00065320(n, t->root_);
    if (leftmost)
        t->leftmost_ = n;
    return n;
}

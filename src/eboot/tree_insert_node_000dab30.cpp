/* HSTMATCH module=EBOOT.BIN start=0x000dab30 end=0x000dac88 symbol=FUN_000dab30 lang=c++ */
/* Clone of src/sharing_main/tree_insert_node_000deaf0.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the same MSL tree-insert code as src/eboot/tree_insert_node_0006cc5c.cpp; 28-byte node, out-of-line 16-byte value copy ctor, errors reported through the empty print stub 0xdd96c); exact match verified; names and types await human review. */
extern "C" {
struct Reent_000dab30 { int pad[3]; void *err; };
Reent_000dab30 *FUN_0000fe3c(void);
void FUN_000d9a00(...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
void *FUN_00002f60(unsigned size, void *p);
void FUN_000dac88(void *dst, const void *src);
extern char DAT_002d6ad4[];
extern char DAT_002c06b8[];
}

struct Value_000dab30 {
    char b[16];
};
struct Node_000dab30 {
    Node_000dab30 *left_;
    Node_000dab30 *right_;
    unsigned parent_;
    Value_000dab30 value_;
    void set_parent(Node_000dab30 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_0006445c(Node_000dab30 *x, Node_000dab30 *root);

struct Alloc_000dab30 {
    Node_000dab30 *allocate(unsigned n)
    {
        Node_000dab30 *p = (Node_000dab30 *)FUN_00000bcc(n * sizeof(Node_000dab30));
        if (p == 0) {
            FUN_000d9a00(FUN_0000fe3c()->err, DAT_002c06b8);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_000dab30 *p) { FUN_00000a00(p); }
};

struct Holder_000dab30 {
    Alloc_000dab30 *a_;
    Node_000dab30 *p_;
    Holder_000dab30(Alloc_000dab30 &a, Node_000dab30 *p) : a_(&a), p_(p) {}
    ~Holder_000dab30() { if (p_) a_->deallocate(p_); }
    Node_000dab30 *get() const { return p_; }
    Node_000dab30 *release() { Node_000dab30 *t = p_; p_ = 0; return t; }
};

struct Tree_000dab30 {
    unsigned size_;
    Node_000dab30 *root_;
    Node_000dab30 *x8_;
    Node_000dab30 *leftmost_;
    Alloc_000dab30 &alloc() { return *(Alloc_000dab30 *)&root_; }
};

extern "C" Node_000dab30 *FUN_000dab30(Tree_000dab30 *t, Node_000dab30 *parent, bool left, bool leftmost,
                                       const Value_000dab30 &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_000d9a00(FUN_0000fe3c()->err, DAT_002d6ad4);
        FUN_0000d518();
    }
    Alloc_000dab30 &a = t->alloc();
    Holder_000dab30 h(a, a.allocate(1));
    Value_000dab30 *q = (Value_000dab30 *)FUN_00002f60(sizeof(Value_000dab30), &h.get()->value_);
    if (q != 0)
        FUN_000dac88(q, &v);
    Node_000dab30 *n = h.release();
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

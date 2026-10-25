/* HSTMATCH module=hstp_trans_main.prx start=0x0006e244 end=0x0006e39c symbol=FUN_0006e244 lang=c++ */
/* Clone of src/eboot/tree_insert_node_0006cc5c.cpp (hstclone.py tag h1025s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the same MSL tree-insert code as src/eboot/tree_insert_node_0006c3b0.cpp; 60-byte node, out-of-line 48-byte value copy ctor); exact match verified; names and types await human review. */
extern "C" {
struct Reent_0006e244 { int pad[3]; void *err; };
Reent_0006e244 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
void *FUN_00002f60(unsigned size, void *p);
void FUN_0006e39c(void *dst, const void *src);
extern char DAT_003772d8[];
extern char DAT_002cc54c[];
}

struct Value_0006e244 {
    char b[48];
};
struct Node_0006e244 {
    Node_0006e244 *left_;
    Node_0006e244 *right_;
    unsigned parent_;
    Value_0006e244 value_;
    void set_parent(Node_0006e244 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_00065320(Node_0006e244 *x, Node_0006e244 *root);

struct Alloc_0006e244 {
    Node_0006e244 *allocate(unsigned n)
    {
        Node_0006e244 *p = (Node_0006e244 *)FUN_00000bcc(n * sizeof(Node_0006e244));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc54c);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_0006e244 *p) { FUN_00000a00(p); }
};

struct Holder_0006e244 {
    Alloc_0006e244 *a_;
    Node_0006e244 *p_;
    Holder_0006e244(Alloc_0006e244 &a, Node_0006e244 *p) : a_(&a), p_(p) {}
    ~Holder_0006e244() { if (p_) a_->deallocate(p_); }
    Node_0006e244 *get() const { return p_; }
    Node_0006e244 *release() { Node_0006e244 *t = p_; p_ = 0; return t; }
};

struct Tree_0006e244 {
    unsigned size_;
    Node_0006e244 *root_;
    Node_0006e244 *x8_;
    Node_0006e244 *leftmost_;
    Alloc_0006e244 &alloc() { return *(Alloc_0006e244 *)&root_; }
};

extern "C" Node_0006e244 *FUN_0006e244(Tree_0006e244 *t, Node_0006e244 *parent, bool left, bool leftmost,
                                       const Value_0006e244 &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003772d8);
        FUN_0000d530();
    }
    Alloc_0006e244 &a = t->alloc();
    Holder_0006e244 h(a, a.allocate(1));
    Value_0006e244 *q = (Value_0006e244 *)FUN_00002f60(sizeof(Value_0006e244), &h.get()->value_);
    if (q != 0)
        FUN_0006e39c(q, &v);
    Node_0006e244 *n = h.release();
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

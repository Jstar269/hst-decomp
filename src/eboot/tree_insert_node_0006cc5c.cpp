/* HSTMATCH module=EBOOT.BIN start=0x0006cc5c end=0x0006cdb4 symbol=FUN_0006cc5c lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the same MSL tree-insert code as src/eboot/tree_insert_node_0006c3b0.cpp; 60-byte node, out-of-line 48-byte value copy ctor); exact match verified; names and types await human review. */
extern "C" {
struct Reent_0006cc5c { int pad[3]; void *err; };
Reent_0006cc5c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
void *FUN_00002f60(unsigned size, void *p);
void FUN_0006cdb4(void *dst, const void *src);
extern char DAT_002d12c4[];
extern char DAT_002bc6a4[];
}

struct Value_0006cc5c {
    char b[48];
};
struct Node_0006cc5c {
    Node_0006cc5c *left_;
    Node_0006cc5c *right_;
    unsigned parent_;
    Value_0006cc5c value_;
    void set_parent(Node_0006cc5c *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_0006445c(Node_0006cc5c *x, Node_0006cc5c *root);

struct Alloc_0006cc5c {
    Node_0006cc5c *allocate(unsigned n)
    {
        Node_0006cc5c *p = (Node_0006cc5c *)FUN_00000bcc(n * sizeof(Node_0006cc5c));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc6a4);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_0006cc5c *p) { FUN_00000a00(p); }
};

struct Holder_0006cc5c {
    Alloc_0006cc5c *a_;
    Node_0006cc5c *p_;
    Holder_0006cc5c(Alloc_0006cc5c &a, Node_0006cc5c *p) : a_(&a), p_(p) {}
    ~Holder_0006cc5c() { if (p_) a_->deallocate(p_); }
    Node_0006cc5c *get() const { return p_; }
    Node_0006cc5c *release() { Node_0006cc5c *t = p_; p_ = 0; return t; }
};

struct Tree_0006cc5c {
    unsigned size_;
    Node_0006cc5c *root_;
    Node_0006cc5c *x8_;
    Node_0006cc5c *leftmost_;
    Alloc_0006cc5c &alloc() { return *(Alloc_0006cc5c *)&root_; }
};

extern "C" Node_0006cc5c *FUN_0006cc5c(Tree_0006cc5c *t, Node_0006cc5c *parent, bool left, bool leftmost,
                                       const Value_0006cc5c &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d12c4);
        FUN_0000d518();
    }
    Alloc_0006cc5c &a = t->alloc();
    Holder_0006cc5c h(a, a.allocate(1));
    Value_0006cc5c *q = (Value_0006cc5c *)FUN_00002f60(sizeof(Value_0006cc5c), &h.get()->value_);
    if (q != 0)
        FUN_0006cdb4(q, &v);
    Node_0006cc5c *n = h.release();
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

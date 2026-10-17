/* HSTMATCH module=hstp_trans_main.prx start=0x0006dd2c end=0x0006de7c symbol=FUN_0006dd2c lang=c++ */
/* Clone of src/eboot/tree_insert_node_00066f0c.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert-at: length check ("tree::insert length_error"), allocate a 20-byte node into a
   holder that references the allocator (an empty member at tree+4), copy-construct the 8-byte value,
   release, link under the parent, ++size, rebalance (0x6445c), update leftmost. Names provisional. */
extern "C" {
struct Reent_0006dd2c { int pad[3]; void *err; };
Reent_0006dd2c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_003772d8[];
extern char DAT_002cc584[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct Value_0006dd2c {
    int a, b;
    Value_0006dd2c(const Value_0006dd2c &o) : a(o.a), b(o.b) {}
};
struct Node_0006dd2c {
    Node_0006dd2c *left_;
    Node_0006dd2c *right_;
    unsigned parent_;
    Value_0006dd2c value_;
    void set_parent(Node_0006dd2c *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_00065320(Node_0006dd2c *x, Node_0006dd2c *root);

struct Alloc_0006dd2c {
    Node_0006dd2c *allocate(unsigned n)
    {
        Node_0006dd2c *p = (Node_0006dd2c *)FUN_00000bcc(n * sizeof(Node_0006dd2c));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc584);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_0006dd2c *p) { FUN_00000a00(p); }
};

struct Holder_0006dd2c {
    Alloc_0006dd2c *a_;
    Node_0006dd2c *p_;
    Holder_0006dd2c(Alloc_0006dd2c &a, Node_0006dd2c *p) : a_(&a), p_(p) {}
    ~Holder_0006dd2c() { if (p_) a_->deallocate(p_); }
    Node_0006dd2c *get() const { return p_; }
    Node_0006dd2c *release() { Node_0006dd2c *t = p_; p_ = 0; return t; }
};

struct Tree_0006dd2c {
    unsigned size_;
    Node_0006dd2c *root_;
    Node_0006dd2c *x8_;
    Node_0006dd2c *leftmost_;
    Alloc_0006dd2c &alloc() { return *(Alloc_0006dd2c *)&root_; }
};

extern "C" Node_0006dd2c *FUN_0006dd2c(Tree_0006dd2c *t, Node_0006dd2c *parent, bool left, bool leftmost,
                                       const Value_0006dd2c &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_003772d8);
        FUN_0000d530();
    }
    Alloc_0006dd2c &a = t->alloc();
    Holder_0006dd2c h(a, a.allocate(1));
    new (&h.get()->value_) Value_0006dd2c(v);
    Node_0006dd2c *n = h.release();
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

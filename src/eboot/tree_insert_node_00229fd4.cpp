/* HSTMATCH module=EBOOT.BIN start=0x00229fd4 end=0x0022a124 symbol=FUN_00229fd4 lang=c++ */
/* Clone of src/eboot/tree_insert_node_0019695c.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert-at: length check ("tree::insert length_error"), allocate a 20-byte node into a
   holder that references the allocator (an empty member at tree+4), copy-construct the 8-byte value,
   release, link under the parent, ++size, rebalance (0x6445c), update leftmost. Names provisional. */
extern "C" {
struct Reent_00229fd4 { int pad[3]; void *err; };
Reent_00229fd4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002f2b5c[];
extern char DAT_002c9a64[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct Value_00229fd4 {
    int a, b;
    Value_00229fd4(const Value_00229fd4 &o) : a(o.a), b(o.b) {}
};
struct Node_00229fd4 {
    Node_00229fd4 *left_;
    Node_00229fd4 *right_;
    unsigned parent_;
    Value_00229fd4 value_;
    void set_parent(Node_00229fd4 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_0006445c(Node_00229fd4 *x, Node_00229fd4 *root);

struct Alloc_00229fd4 {
    Node_00229fd4 *allocate(unsigned n)
    {
        Node_00229fd4 *p = (Node_00229fd4 *)FUN_00000bcc(n * sizeof(Node_00229fd4));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c9a64);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_00229fd4 *p) { FUN_00000a00(p); }
};

struct Holder_00229fd4 {
    Alloc_00229fd4 *a_;
    Node_00229fd4 *p_;
    Holder_00229fd4(Alloc_00229fd4 &a, Node_00229fd4 *p) : a_(&a), p_(p) {}
    ~Holder_00229fd4() { if (p_) a_->deallocate(p_); }
    Node_00229fd4 *get() const { return p_; }
    Node_00229fd4 *release() { Node_00229fd4 *t = p_; p_ = 0; return t; }
};

struct Tree_00229fd4 {
    unsigned size_;
    Node_00229fd4 *root_;
    Node_00229fd4 *x8_;
    Node_00229fd4 *leftmost_;
    Alloc_00229fd4 &alloc() { return *(Alloc_00229fd4 *)&root_; }
};

extern "C" Node_00229fd4 *FUN_00229fd4(Tree_00229fd4 *t, Node_00229fd4 *parent, bool left, bool leftmost,
                                       const Value_00229fd4 &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002f2b5c);
        FUN_0000d518();
    }
    Alloc_00229fd4 &a = t->alloc();
    Holder_00229fd4 h(a, a.allocate(1));
    new (&h.get()->value_) Value_00229fd4(v);
    Node_00229fd4 *n = h.release();
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

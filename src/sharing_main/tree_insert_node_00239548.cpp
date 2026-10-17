/* HSTMATCH module=hstp_trans_main.prx start=0x00239548 end=0x00239698 symbol=FUN_00239548 lang=c++ */
/* Clone of src/eboot/tree_insert_node_00066f0c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert-at: length check ("tree::insert length_error"), allocate a 20-byte node into a
   holder that references the allocator (an empty member at tree+4), copy-construct the 8-byte value,
   release, link under the parent, ++size, rebalance (0x6445c), update leftmost. Names provisional. */
extern "C" {
struct Reent_00239548 { int pad[3]; void *err; };
Reent_00239548 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_0039af28[];
extern char DAT_002da024[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct Value_00239548 {
    int a, b;
    Value_00239548(const Value_00239548 &o) : a(o.a), b(o.b) {}
};
struct Node_00239548 {
    Node_00239548 *left_;
    Node_00239548 *right_;
    unsigned parent_;
    Value_00239548 value_;
    void set_parent(Node_00239548 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_00065320(Node_00239548 *x, Node_00239548 *root);

struct Alloc_00239548 {
    Node_00239548 *allocate(unsigned n)
    {
        Node_00239548 *p = (Node_00239548 *)FUN_00000bcc(n * sizeof(Node_00239548));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002da024);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_00239548 *p) { FUN_00000a00(p); }
};

struct Holder_00239548 {
    Alloc_00239548 *a_;
    Node_00239548 *p_;
    Holder_00239548(Alloc_00239548 &a, Node_00239548 *p) : a_(&a), p_(p) {}
    ~Holder_00239548() { if (p_) a_->deallocate(p_); }
    Node_00239548 *get() const { return p_; }
    Node_00239548 *release() { Node_00239548 *t = p_; p_ = 0; return t; }
};

struct Tree_00239548 {
    unsigned size_;
    Node_00239548 *root_;
    Node_00239548 *x8_;
    Node_00239548 *leftmost_;
    Alloc_00239548 &alloc() { return *(Alloc_00239548 *)&root_; }
};

extern "C" Node_00239548 *FUN_00239548(Tree_00239548 *t, Node_00239548 *parent, bool left, bool leftmost,
                                       const Value_00239548 &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0039af28);
        FUN_0000d530();
    }
    Alloc_00239548 &a = t->alloc();
    Holder_00239548 h(a, a.allocate(1));
    new (&h.get()->value_) Value_00239548(v);
    Node_00239548 *n = h.release();
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

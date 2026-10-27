/* HSTMATCH module=hstp_trans_main.prx start=0x001a3254 end=0x001a33a4 symbol=FUN_001a3254 lang=c++ data=0x00388d28 */
/* Clone of src/eboot/tree_insert_node_00066f0c.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00388d28-0x00388d42) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert-at: length check ("tree::insert length_error"), allocate a 20-byte node into a
   holder that references the allocator (an empty member at tree+4), copy-construct the 8-byte value,
   release, link under the parent, ++size, rebalance (0x6445c), update leftmost. Names provisional. */
extern "C" {
struct Reent_001a3254 { int pad[3]; void *err; };
Reent_001a3254 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002d2d84[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct Value_001a3254 {
    int a, b;
    Value_001a3254(const Value_001a3254 &o) : a(o.a), b(o.b) {}
};
struct Node_001a3254 {
    Node_001a3254 *left_;
    Node_001a3254 *right_;
    unsigned parent_;
    Value_001a3254 value_;
    void set_parent(Node_001a3254 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_00065320(Node_001a3254 *x, Node_001a3254 *root);

struct Alloc_001a3254 {
    Node_001a3254 *allocate(unsigned n)
    {
        Node_001a3254 *p = (Node_001a3254 *)FUN_00000bcc(n * sizeof(Node_001a3254));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d2d84);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_001a3254 *p) { FUN_00000a00(p); }
};

struct Holder_001a3254 {
    Alloc_001a3254 *a_;
    Node_001a3254 *p_;
    Holder_001a3254(Alloc_001a3254 &a, Node_001a3254 *p) : a_(&a), p_(p) {}
    ~Holder_001a3254() { if (p_) a_->deallocate(p_); }
    Node_001a3254 *get() const { return p_; }
    Node_001a3254 *release() { Node_001a3254 *t = p_; p_ = 0; return t; }
};

struct Tree_001a3254 {
    unsigned size_;
    Node_001a3254 *root_;
    Node_001a3254 *x8_;
    Node_001a3254 *leftmost_;
    Alloc_001a3254 &alloc() { return *(Alloc_001a3254 *)&root_; }
};

extern "C" Node_001a3254 *FUN_001a3254(Tree_001a3254 *t, Node_001a3254 *parent, bool left, bool leftmost,
                                       const Value_001a3254 &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "tree::insert length error");
        FUN_0000d530();
    }
    Alloc_001a3254 &a = t->alloc();
    Holder_001a3254 h(a, a.allocate(1));
    new (&h.get()->value_) Value_001a3254(v);
    Node_001a3254 *n = h.release();
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

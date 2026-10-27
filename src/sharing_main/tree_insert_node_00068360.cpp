/* HSTMATCH module=hstp_trans_main.prx start=0x00068360 end=0x000684b0 symbol=FUN_00068360 lang=c++ data=0x00377160 */
/* Clone of src/eboot/tree_insert_node_00066f0c.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00377160-0x0037717a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert-at: length check ("tree::insert length_error"), allocate a 20-byte node into a
   holder that references the allocator (an empty member at tree+4), copy-construct the 8-byte value,
   release, link under the parent, ++size, rebalance (0x6445c), update leftmost. Names provisional. */
extern "C" {
struct Reent_00068360 { int pad[3]; void *err; };
Reent_00068360 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002cc44c[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct Value_00068360 {
    int a, b;
    Value_00068360(const Value_00068360 &o) : a(o.a), b(o.b) {}
};
struct Node_00068360 {
    Node_00068360 *left_;
    Node_00068360 *right_;
    unsigned parent_;
    Value_00068360 value_;
    void set_parent(Node_00068360 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_00065320(Node_00068360 *x, Node_00068360 *root);

struct Alloc_00068360 {
    Node_00068360 *allocate(unsigned n)
    {
        Node_00068360 *p = (Node_00068360 *)FUN_00000bcc(n * sizeof(Node_00068360));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002cc44c);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_00068360 *p) { FUN_00000a00(p); }
};

struct Holder_00068360 {
    Alloc_00068360 *a_;
    Node_00068360 *p_;
    Holder_00068360(Alloc_00068360 &a, Node_00068360 *p) : a_(&a), p_(p) {}
    ~Holder_00068360() { if (p_) a_->deallocate(p_); }
    Node_00068360 *get() const { return p_; }
    Node_00068360 *release() { Node_00068360 *t = p_; p_ = 0; return t; }
};

struct Tree_00068360 {
    unsigned size_;
    Node_00068360 *root_;
    Node_00068360 *x8_;
    Node_00068360 *leftmost_;
    Alloc_00068360 &alloc() { return *(Alloc_00068360 *)&root_; }
};

extern "C" Node_00068360 *FUN_00068360(Tree_00068360 *t, Node_00068360 *parent, bool left, bool leftmost,
                                       const Value_00068360 &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "tree::insert length error");
        FUN_0000d530();
    }
    Alloc_00068360 &a = t->alloc();
    Holder_00068360 h(a, a.allocate(1));
    new (&h.get()->value_) Value_00068360(v);
    Node_00068360 *n = h.release();
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

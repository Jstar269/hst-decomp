/* HSTMATCH module=EBOOT.BIN start=0x00066f0c end=0x0006705c symbol=FUN_00066f0c lang=c++ data=0x002d11d4 */
/* Clone of src/eboot/tree_insert_node_0019695c.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d11d4-0x002d11ee) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert-at: length check ("tree::insert length_error"), allocate a 20-byte node into a
   holder that references the allocator (an empty member at tree+4), copy-construct the 8-byte value,
   release, link under the parent, ++size, rebalance (0x6445c), update leftmost. Names provisional. */
extern "C" {
struct Reent_00066f0c { int pad[3]; void *err; };
Reent_00066f0c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002bc5fc[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct Value_00066f0c {
    int a, b;
    Value_00066f0c(const Value_00066f0c &o) : a(o.a), b(o.b) {}
};
struct Node_00066f0c {
    Node_00066f0c *left_;
    Node_00066f0c *right_;
    unsigned parent_;
    Value_00066f0c value_;
    void set_parent(Node_00066f0c *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_0006445c(Node_00066f0c *x, Node_00066f0c *root);

struct Alloc_00066f0c {
    Node_00066f0c *allocate(unsigned n)
    {
        Node_00066f0c *p = (Node_00066f0c *)FUN_00000bcc(n * sizeof(Node_00066f0c));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc5fc);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_00066f0c *p) { FUN_00000a00(p); }
};

struct Holder_00066f0c {
    Alloc_00066f0c *a_;
    Node_00066f0c *p_;
    Holder_00066f0c(Alloc_00066f0c &a, Node_00066f0c *p) : a_(&a), p_(p) {}
    ~Holder_00066f0c() { if (p_) a_->deallocate(p_); }
    Node_00066f0c *get() const { return p_; }
    Node_00066f0c *release() { Node_00066f0c *t = p_; p_ = 0; return t; }
};

struct Tree_00066f0c {
    unsigned size_;
    Node_00066f0c *root_;
    Node_00066f0c *x8_;
    Node_00066f0c *leftmost_;
    Alloc_00066f0c &alloc() { return *(Alloc_00066f0c *)&root_; }
};

extern "C" Node_00066f0c *FUN_00066f0c(Tree_00066f0c *t, Node_00066f0c *parent, bool left, bool leftmost,
                                       const Value_00066f0c &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "tree::insert length error");
        FUN_0000d518();
    }
    Alloc_00066f0c &a = t->alloc();
    Holder_00066f0c h(a, a.allocate(1));
    new (&h.get()->value_) Value_00066f0c(v);
    Node_00066f0c *n = h.release();
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

/* HSTMATCH module=EBOOT.BIN start=0x0019695c end=0x00196aac symbol=FUN_0019695c lang=c++ data=0x002e15e4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e15e4-0x002e15fe) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* MSL-style tree insert-at: length check ("tree::insert length_error"), allocate a 20-byte node into a
   holder that references the allocator (an empty member at tree+4), copy-construct the 8-byte value,
   release, link under the parent, ++size, rebalance (0x6445c), update leftmost. Names provisional. */
extern "C" {
struct Reent_0019695c { int pad[3]; void *err; };
Reent_0019695c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002c2884[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct Value_0019695c {
    int a, b;
    Value_0019695c(const Value_0019695c &o) : a(o.a), b(o.b) {}
};
struct Node_0019695c {
    Node_0019695c *left_;
    Node_0019695c *right_;
    unsigned parent_;
    Value_0019695c value_;
    void set_parent(Node_0019695c *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_0006445c(Node_0019695c *x, Node_0019695c *root);

struct Alloc_0019695c {
    Node_0019695c *allocate(unsigned n)
    {
        Node_0019695c *p = (Node_0019695c *)FUN_00000bcc(n * sizeof(Node_0019695c));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2884);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_0019695c *p) { FUN_00000a00(p); }
};

struct Holder_0019695c {
    Alloc_0019695c *a_;
    Node_0019695c *p_;
    Holder_0019695c(Alloc_0019695c &a, Node_0019695c *p) : a_(&a), p_(p) {}
    ~Holder_0019695c() { if (p_) a_->deallocate(p_); }
    Node_0019695c *get() const { return p_; }
    Node_0019695c *release() { Node_0019695c *t = p_; p_ = 0; return t; }
};

struct Tree_0019695c {
    unsigned size_;
    Node_0019695c *root_;
    Node_0019695c *x8_;
    Node_0019695c *leftmost_;
    Alloc_0019695c &alloc() { return *(Alloc_0019695c *)&root_; }
};

/* Link a new node holding a copy of `value` under `parent` (as left or right child), rebalance, and update the leftmost pointer when asked. */
extern "C" Node_0019695c *FUN_0019695c(Tree_0019695c *tree, Node_0019695c *parent, bool left, bool leftmost,
                                       const Value_0019695c &value)
{
    if (tree->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "tree::insert length error");
        FUN_0000d518();
    }
    Alloc_0019695c &alloc = tree->alloc();
    Holder_0019695c holder(alloc, alloc.allocate(1));
    new (&holder.get()->value_) Value_0019695c(value);
    Node_0019695c *node = holder.release();
    node->left_ = node->right_ = 0;
    node->set_parent(parent);
    if (left)
        parent->left_ = node;
    else
        parent->right_ = node;
    ++tree->size_;
    FUN_0006445c(node, tree->root_);
    if (leftmost)
        tree->leftmost_ = node;
    return node;
}

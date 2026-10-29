/* HSTMATCH module=EBOOT.BIN start=0x0006cc5c end=0x0006cdb4 symbol=FUN_0006cc5c lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the same MSL tree-insert code as src/eboot/tree_insert_node_0006c3b0.cpp; 60-byte node, out-of-line 48-byte value copy ctor); exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...); /* fprintf */
void FUN_00000a00(void *p);                              /* operator delete */
void *FUN_00002f60(unsigned size, void *p);              /* placement new */
void FUN_0006cdb4(void *dst, const void *src);           /* value copy constructor */
extern char DAT_002d12c4[];                              /* size-limit error message */
extern char DAT_002bc6a4[];                              /* allocation-failure message */
}

struct Value {
    char b[48];
};
struct Node {
    Node *left_;
    Node *right_;
    unsigned parent_;
    Value value_;
    void set_parent(Node *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_0006445c(Node *x, Node *root);

struct Alloc {
    Node *allocate(unsigned n)
    {
        Node *p = (Node *)FUN_00000bcc(n * sizeof(Node));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002bc6a4);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node *p) { FUN_00000a00(p); }
};

struct Holder {
    Alloc *a_;
    Node *p_;
    Holder(Alloc &a, Node *p) : a_(&a), p_(p) {}
    ~Holder() { if (p_) a_->deallocate(p_); }
    Node *get() const { return p_; }
    Node *release() { Node *t = p_; p_ = 0; return t; }
};

struct Tree {
    unsigned size_;
    Node *root_;
    Node *x8_;
    Node *leftmost_;
    Alloc &alloc() { return *(Alloc *)&root_; }
};

extern "C" Node *FUN_0006cc5c(Tree *tree, Node *parent, bool left, bool leftmost,
                                       const Value &v)
{
    if (tree->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d12c4);
        FUN_0000d518();
    }
    Alloc &a = tree->alloc();
    Holder h(a, a.allocate(1));
    Value *q = (Value *)FUN_00002f60(sizeof(Value), &h.get()->value_);
    if (q != 0)
        FUN_0006cdb4(q, &v);
    Node *n = h.release();
    n->left_ = n->right_ = 0;
    n->set_parent(parent);
    if (left)
        parent->left_ = n;
    else
        parent->right_ = n;
    ++tree->size_;
    FUN_0006445c(n, tree->root_);
    if (leftmost)
        tree->leftmost_ = n;
    return n;
}

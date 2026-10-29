/* HSTMATCH module=EBOOT.BIN start=0x000d7460 end=0x000d7608 symbol=FUN_000d7460 lang=c++ data=0x002d6838 */
/* Hand-written reconstruction from the disassembly (derived from src/eboot/tree_insert_node_0019695c.cpp with a 16-byte string+int value); exact match verified; matching idiom: the node holder carries an unused leading 4-byte member (retail's holder is 12 bytes: it moves the never-written fwd_tag slot read by `lb t1,32(sp)` below it); names and types await human review. Data: its string literals (1 strings, 0x002d6838-0x002d6852) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* MSL-style tree insert-at for a node whose 16-byte value is a short-string-optimised string (3 words, flag bit 0 = heap mode: reserve via 0x3ed4, assign range via 0x3370 with a derived empty tag) plus an int; same shape as 0x19695c (length check, 28-byte node, holder, link, ++size, rebalance 0x6445c, leftmost). */
#include "hst/vec_reserve.h"

extern "C" {
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_00000a00(void *p);
extern char DAT_002c0624[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct in_tag {};
struct fwd_tag : in_tag {};
struct Str_000d7460 { unsigned v[3]; };
extern "C" void FUN_00003ed4(Str_000d7460 *, unsigned);
extern "C" void FUN_00003370(Str_000d7460 *, unsigned, unsigned, unsigned, unsigned, fwd_tag);

struct Value_000d7460 {
    Str_000d7460 s;
    int extra;
    Value_000d7460(const Value_000d7460 &o)
    {
        if ((o.s.v[0] & 1) == 0) {
            s = o.s;
        } else {
            s.v[0] = 0;
            s.v[1] = 0;
            s.v[2] = 0;
            FUN_00003ed4(&s, o.s.v[1]);
            FUN_00003370(&s, 0, 0, o.s.v[2], o.s.v[2] + o.s.v[1], fwd_tag());
        }
        extra = o.extra;
    }
};
struct Node_000d7460 {
    Node_000d7460 *left_;
    Node_000d7460 *right_;
    unsigned parent_;
    Value_000d7460 value_;
    void set_parent(Node_000d7460 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_0006445c(Node_000d7460 *x, Node_000d7460 *root);

struct Alloc_000d7460 {
    Node_000d7460 *allocate(unsigned n)
    {
        Node_000d7460 *p = (Node_000d7460 *)FUN_00000bcc(n * sizeof(Node_000d7460));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c0624);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(Node_000d7460 *p) { FUN_00000a00(p); }
};

struct Holder_000d7460 {
    int unused_;
    Alloc_000d7460 *a_;
    Node_000d7460 *p_;
    Holder_000d7460(Alloc_000d7460 &a, Node_000d7460 *p) : a_(&a), p_(p) {}
    ~Holder_000d7460() { if (p_) a_->deallocate(p_); }
    Node_000d7460 *get() const { return p_; }
    Node_000d7460 *release() { Node_000d7460 *t = p_; p_ = 0; return t; }
};

/* Tree header: element count, root, an unused word, leftmost node; the allocator overlays the root slot. */
struct Tree_000d7460 {
    unsigned size_;
    Node_000d7460 *root_;
    Node_000d7460 *unk8_;
    Node_000d7460 *leftmost_;
    Alloc_000d7460 &alloc() { return *(Alloc_000d7460 *)&root_; }
};

extern "C" Node_000d7460 *FUN_000d7460(Tree_000d7460 *tree, Node_000d7460 *parent, bool left, bool leftmost,
                                       const Value_000d7460 &v)
{
    /* insert a node holding a copy of v under parent (left or right link); update leftmost, rebalance */
    if (tree->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "tree::insert length error");
        FUN_0000d518();
    }
    Alloc_000d7460 &alloc = tree->alloc();
    Holder_000d7460 holder(alloc, alloc.allocate(1));
    new (&holder.get()->value_) Value_000d7460(v);
    Node_000d7460 *node = holder.release();
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

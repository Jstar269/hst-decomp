/* HSTMATCH module=hstp_trans_main.prx start=0x000db150 end=0x000db2f8 symbol=FUN_000db150 lang=c++ data=0x0037d328 */
/* Clone of src/eboot/tree_insert_node_000d7460.cpp (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037d328-0x0037d342) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly (derived from src/eboot/tree_insert_node_0019695c.cpp with a 16-byte string+int value); exact match verified; matching idiom: the node holder carries an unused leading 4-byte member (retail's holder is 12 bytes: it moves the never-written fwd_tag slot read by `lb t1,32(sp)` below it); names and types await human review. */
/* MSL-style tree insert-at for a node whose 16-byte value is a short-string-optimised string (3 words, flag bit 0 = heap mode: reserve via 0x3ed4, assign range via 0x3370 with a derived empty tag) plus an int; same shape as 0x19695c (length check, 28-byte node, holder, link, ++size, rebalance 0x6445c, leftmost). */
extern "C" {
struct Reent_000db150 { int pad[3]; void *err; };
Reent_000db150 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002d0854[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct in_tag {};
struct fwd_tag : in_tag {};
struct Str_000db150 { unsigned v[3]; };
extern "C" void FUN_00003ed4(Str_000db150 *, unsigned);
extern "C" void FUN_00003370(Str_000db150 *, unsigned, unsigned, unsigned, unsigned, fwd_tag);

struct Value_000db150 {
    Str_000db150 s;
    int extra;
    Value_000db150(const Value_000db150 &o)
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
struct Node_000db150 {
    Node_000db150 *left_;
    Node_000db150 *right_;
    unsigned parent_;
    Value_000db150 value_;
    void set_parent(Node_000db150 *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_00065320(Node_000db150 *x, Node_000db150 *root);

struct Alloc_000db150 {
    Node_000db150 *allocate(unsigned n)
    {
        Node_000db150 *p = (Node_000db150 *)FUN_00000bcc(n * sizeof(Node_000db150));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d0854);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_000db150 *p) { FUN_00000a00(p); }
};

struct Holder_000db150 {
    int unused_;
    Alloc_000db150 *a_;
    Node_000db150 *p_;
    Holder_000db150(Alloc_000db150 &a, Node_000db150 *p) : a_(&a), p_(p) {}
    ~Holder_000db150() { if (p_) a_->deallocate(p_); }
    Node_000db150 *get() const { return p_; }
    Node_000db150 *release() { Node_000db150 *t = p_; p_ = 0; return t; }
};

struct Tree_000db150 {
    unsigned size_;
    Node_000db150 *root_;
    Node_000db150 *x8_;
    Node_000db150 *leftmost_;
    Alloc_000db150 &alloc() { return *(Alloc_000db150 *)&root_; }
};

extern "C" Node_000db150 *FUN_000db150(Tree_000db150 *t, Node_000db150 *parent, bool left, bool leftmost,
                                       const Value_000db150 &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, "tree::insert length error");
        FUN_0000d530();
    }
    Alloc_000db150 &a = t->alloc();
    Holder_000db150 h(a, a.allocate(1));
    new (&h.get()->value_) Value_000db150(v);
    Node_000db150 *n = h.release();
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

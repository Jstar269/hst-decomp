/* HSTMATCH module=hstp_trans_main.prx start=0x002398dc end=0x00239a2c symbol=FUN_002398dc lang=c++ */
/* Clone of src/eboot/tree_insert_node_00066f0c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert-at: length check ("tree::insert length_error"), allocate a 20-byte node into a
   holder that references the allocator (an empty member at tree+4), copy-construct the 8-byte value,
   release, link under the parent, ++size, rebalance (0x6445c), update leftmost. Names provisional. */
extern "C" {
struct Reent_002398dc { int pad[3]; void *err; };
Reent_002398dc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_0039af28[];
extern char DAT_002da008[];
}
inline void *operator new(unsigned, void *p) throw() { return p; }

struct Value_002398dc {
    int a, b;
    Value_002398dc(const Value_002398dc &o) : a(o.a), b(o.b) {}
};
struct Node_002398dc {
    Node_002398dc *left_;
    Node_002398dc *right_;
    unsigned parent_;
    Value_002398dc value_;
    void set_parent(Node_002398dc *p) { parent_ = (unsigned)p | (parent_ & 1); }
};
extern "C" void FUN_00065320(Node_002398dc *x, Node_002398dc *root);

struct Alloc_002398dc {
    Node_002398dc *allocate(unsigned n)
    {
        Node_002398dc *p = (Node_002398dc *)FUN_00000bcc(n * sizeof(Node_002398dc));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002da008);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(Node_002398dc *p) { FUN_00000a00(p); }
};

struct Holder_002398dc {
    Alloc_002398dc *a_;
    Node_002398dc *p_;
    Holder_002398dc(Alloc_002398dc &a, Node_002398dc *p) : a_(&a), p_(p) {}
    ~Holder_002398dc() { if (p_) a_->deallocate(p_); }
    Node_002398dc *get() const { return p_; }
    Node_002398dc *release() { Node_002398dc *t = p_; p_ = 0; return t; }
};

struct Tree_002398dc {
    unsigned size_;
    Node_002398dc *root_;
    Node_002398dc *x8_;
    Node_002398dc *leftmost_;
    Alloc_002398dc &alloc() { return *(Alloc_002398dc *)&root_; }
};

extern "C" Node_002398dc *FUN_002398dc(Tree_002398dc *t, Node_002398dc *parent, bool left, bool leftmost,
                                       const Value_002398dc &v)
{
    if (t->size_ == 0xffffffff) {
        FUN_0000f3e8(FUN_0000fe3c()->err, DAT_0039af28);
        FUN_0000d530();
    }
    Alloc_002398dc &a = t->alloc();
    Holder_002398dc h(a, a.allocate(1));
    new (&h.get()->value_) Value_002398dc(v);
    Node_002398dc *n = h.release();
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

/* HSTMATCH module=EBOOT.BIN start=0x000daf14 end=0x000db17c symbol=FUN_000daf14 lang=c++ */
/* Clone of src/eboot/tree_destroy_000d71a8.cpp (hstclone.py tag c27): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Red-black tree node teardown (map<string, T>-style: node = left, right, parent, value at +12 whose first
   member is a short-string-optimised string). Retail is the out-of-line copy of a recursive inline
   destroy(node): the two inlined recursion levels are spelled out here as Destroy1/Destroy2 because the
   inner levels call out-of-line copies (value-allocator accessor 0xd7458, allocator destroy 0xd7420,
   node-allocator accessor 0xd7418, deallocate 0xd7410, value destructor 0xc75f4) that a single natural
   template would re-emit as local weak copies in this object. Names provisional. */
struct String_000daf14 {
    unsigned cap;
    unsigned size;
    char *data;
    ~String_000daf14() { if (cap & 1) operator delete(data); }
};
struct Value_000daf14 { String_000daf14 first; int second; };
struct Node_000daf14 { Node_000daf14 *left; Node_000daf14 *right; Node_000daf14 *parent; Value_000daf14 value; };
struct Tree_000daf14;
extern "C" {
void *FUN_000db1c4(Tree_000daf14 *t);
void FUN_000db18c(void *a, Value_000daf14 *p);
void *FUN_000db184(Tree_000daf14 *t);
void FUN_000db17c(void *a, Node_000daf14 *p, unsigned n);
void FUN_000d9968(Value_000daf14 *p, int flags);
void FUN_000daf14(Tree_000daf14 *t, Node_000daf14 *x);
}
static inline void Destroy2_000daf14(Tree_000daf14 *t, Node_000daf14 *x)
{
    if (x->left)
        FUN_000daf14(t, x->left);
    if (x->right)
        FUN_000daf14(t, x->right);
    FUN_000db18c(FUN_000db1c4(t), &x->value);
    FUN_000db17c(FUN_000db184(t), x, 1);
}
static inline void Destroy1_000daf14(Tree_000daf14 *t, Node_000daf14 *x)
{
    if (x->left)
        Destroy2_000daf14(t, x->left);
    if (x->right)
        Destroy2_000daf14(t, x->right);
    FUN_000db1c4(t);
    FUN_000d9968(&x->value, -1);
    FUN_000db184(t);
    operator delete(x);
}
inline void DestroyValue_000daf14(Value_000daf14 *p) { p->~Value_000daf14(); }
extern "C" void FUN_000daf14(Tree_000daf14 *t, Node_000daf14 *x)
{
    if (x->left)
        Destroy1_000daf14(t, x->left);
    if (x->right)
        Destroy1_000daf14(t, x->right);
    DestroyValue_000daf14(&x->value);
    operator delete(x);
}

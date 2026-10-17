/* HSTMATCH module=hstp_trans_main.prx start=0x000deed4 end=0x000df13c symbol=FUN_000deed4 lang=c++ */
/* Clone of src/eboot/tree_destroy_000d71a8.cpp (hstclone.py tag c28): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Red-black tree node teardown (map<string, T>-style: node = left, right, parent, value at +12 whose first
   member is a short-string-optimised string). Retail is the out-of-line copy of a recursive inline
   destroy(node): the two inlined recursion levels are spelled out here as Destroy1/Destroy2 because the
   inner levels call out-of-line copies (value-allocator accessor 0xd7458, allocator destroy 0xd7420,
   node-allocator accessor 0xd7418, deallocate 0xd7410, value destructor 0xc75f4) that a single natural
   template would re-emit as local weak copies in this object. Names provisional. */
struct String_000deed4 {
    unsigned cap;
    unsigned size;
    char *data;
    ~String_000deed4() { if (cap & 1) operator delete(data); }
};
struct Value_000deed4 { String_000deed4 first; int second; };
struct Node_000deed4 { Node_000deed4 *left; Node_000deed4 *right; Node_000deed4 *parent; Value_000deed4 value; };
struct Tree_000deed4;
extern "C" {
void *FUN_000df184(Tree_000deed4 *t);
void FUN_000df14c(void *a, Value_000deed4 *p);
void *FUN_000df144(Tree_000deed4 *t);
void FUN_000df13c(void *a, Node_000deed4 *p, unsigned n);
void FUN_000dd8d4(Value_000deed4 *p, int flags);
void FUN_000deed4(Tree_000deed4 *t, Node_000deed4 *x);
}
static inline void Destroy2_000deed4(Tree_000deed4 *t, Node_000deed4 *x)
{
    if (x->left)
        FUN_000deed4(t, x->left);
    if (x->right)
        FUN_000deed4(t, x->right);
    FUN_000df14c(FUN_000df184(t), &x->value);
    FUN_000df13c(FUN_000df144(t), x, 1);
}
static inline void Destroy1_000deed4(Tree_000deed4 *t, Node_000deed4 *x)
{
    if (x->left)
        Destroy2_000deed4(t, x->left);
    if (x->right)
        Destroy2_000deed4(t, x->right);
    FUN_000df184(t);
    FUN_000dd8d4(&x->value, -1);
    FUN_000df144(t);
    operator delete(x);
}
inline void DestroyValue_000deed4(Value_000deed4 *p) { p->~Value_000deed4(); }
extern "C" void FUN_000deed4(Tree_000deed4 *t, Node_000deed4 *x)
{
    if (x->left)
        Destroy1_000deed4(t, x->left);
    if (x->right)
        Destroy1_000deed4(t, x->right);
    DestroyValue_000deed4(&x->value);
    operator delete(x);
}

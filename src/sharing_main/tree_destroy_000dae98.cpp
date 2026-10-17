/* HSTMATCH module=hstp_trans_main.prx start=0x000dae98 end=0x000db100 symbol=FUN_000dae98 lang=c++ */
/* Clone of src/eboot/tree_destroy_000d71a8.cpp (hstclone.py tag c28): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Red-black tree node teardown (map<string, T>-style: node = left, right, parent, value at +12 whose first
   member is a short-string-optimised string). Retail is the out-of-line copy of a recursive inline
   destroy(node): the two inlined recursion levels are spelled out here as Destroy1/Destroy2 because the
   inner levels call out-of-line copies (value-allocator accessor 0xd7458, allocator destroy 0xd7420,
   node-allocator accessor 0xd7418, deallocate 0xd7410, value destructor 0xc75f4) that a single natural
   template would re-emit as local weak copies in this object. Names provisional. */
struct String_000dae98 {
    unsigned cap;
    unsigned size;
    char *data;
    ~String_000dae98() { if (cap & 1) operator delete(data); }
};
struct Value_000dae98 { String_000dae98 first; int second; };
struct Node_000dae98 { Node_000dae98 *left; Node_000dae98 *right; Node_000dae98 *parent; Value_000dae98 value; };
struct Tree_000dae98;
extern "C" {
void *FUN_000db148(Tree_000dae98 *t);
void FUN_000db110(void *a, Value_000dae98 *p);
void *FUN_000db108(Tree_000dae98 *t);
void FUN_000db100(void *a, Node_000dae98 *p, unsigned n);
void FUN_000cb0a8(Value_000dae98 *p, int flags);
void FUN_000dae98(Tree_000dae98 *t, Node_000dae98 *x);
}
static inline void Destroy2_000dae98(Tree_000dae98 *t, Node_000dae98 *x)
{
    if (x->left)
        FUN_000dae98(t, x->left);
    if (x->right)
        FUN_000dae98(t, x->right);
    FUN_000db110(FUN_000db148(t), &x->value);
    FUN_000db100(FUN_000db108(t), x, 1);
}
static inline void Destroy1_000dae98(Tree_000dae98 *t, Node_000dae98 *x)
{
    if (x->left)
        Destroy2_000dae98(t, x->left);
    if (x->right)
        Destroy2_000dae98(t, x->right);
    FUN_000db148(t);
    FUN_000cb0a8(&x->value, -1);
    FUN_000db108(t);
    operator delete(x);
}
inline void DestroyValue_000dae98(Value_000dae98 *p) { p->~Value_000dae98(); }
extern "C" void FUN_000dae98(Tree_000dae98 *t, Node_000dae98 *x)
{
    if (x->left)
        Destroy1_000dae98(t, x->left);
    if (x->right)
        Destroy1_000dae98(t, x->right);
    DestroyValue_000dae98(&x->value);
    operator delete(x);
}

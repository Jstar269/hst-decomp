/* HSTMATCH module=EBOOT.BIN start=0x000d71a8 end=0x000d7410 symbol=FUN_000d71a8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Red-black tree node teardown (map<string, T>-style: node = left, right, parent, value at +12 whose first
   member is a short-string-optimised string). Retail is the out-of-line copy of a recursive inline
   destroy(node): the two inlined recursion levels are spelled out here as Destroy1/Destroy2 because the
   inner levels call out-of-line copies (value-allocator accessor 0xd7458, allocator destroy 0xd7420,
   node-allocator accessor 0xd7418, deallocate 0xd7410, value destructor 0xc75f4) that a single natural
   template would re-emit as local weak copies in this object. Names provisional. */
struct String_000d71a8 {
    unsigned cap;
    unsigned size;
    char *data;
    ~String_000d71a8() { if (cap & 1) operator delete(data); }
};
struct Value_000d71a8 { String_000d71a8 first; int second; };
struct Node_000d71a8 { Node_000d71a8 *left; Node_000d71a8 *right; Node_000d71a8 *parent; Value_000d71a8 value; };
struct Tree_000d71a8;
extern "C" {
void *FUN_000d7458(Tree_000d71a8 *t);
void FUN_000d7420(void *a, Value_000d71a8 *p);
void *FUN_000d7418(Tree_000d71a8 *t);
void FUN_000d7410(void *a, Node_000d71a8 *p, unsigned n);
void FUN_000c75f4(Value_000d71a8 *p, int flags);
void FUN_000d71a8(Tree_000d71a8 *t, Node_000d71a8 *x);
}
static inline void Destroy2_000d71a8(Tree_000d71a8 *t, Node_000d71a8 *x)
{
    if (x->left)
        FUN_000d71a8(t, x->left);
    if (x->right)
        FUN_000d71a8(t, x->right);
    FUN_000d7420(FUN_000d7458(t), &x->value);
    FUN_000d7410(FUN_000d7418(t), x, 1);
}
static inline void Destroy1_000d71a8(Tree_000d71a8 *t, Node_000d71a8 *x)
{
    if (x->left)
        Destroy2_000d71a8(t, x->left);
    if (x->right)
        Destroy2_000d71a8(t, x->right);
    FUN_000d7458(t);
    FUN_000c75f4(&x->value, -1);
    FUN_000d7418(t);
    operator delete(x);
}
inline void DestroyValue_000d71a8(Value_000d71a8 *p) { p->~Value_000d71a8(); }
extern "C" void FUN_000d71a8(Tree_000d71a8 *t, Node_000d71a8 *x)
{
    if (x->left)
        Destroy1_000d71a8(t, x->left);
    if (x->right)
        Destroy1_000d71a8(t, x->right);
    DestroyValue_000d71a8(&x->value);
    operator delete(x);
}

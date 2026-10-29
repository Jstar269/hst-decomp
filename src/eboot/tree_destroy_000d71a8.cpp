/* HSTMATCH module=EBOOT.BIN start=0x000d71a8 end=0x000d7410 symbol=FUN_000d71a8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Red-black tree node teardown (map<string, T>-style: node = left, right, parent, value at +12 whose first
   member is a short-string-optimised string). Retail is the out-of-line copy of a recursive inline
   destroy(node): the two inlined recursion levels are spelled out here as Destroy1/Destroy2 because the
   inner levels call out-of-line copies (value-allocator accessor 0xd7458, allocator destroy 0xd7420,
   node-allocator accessor 0xd7418, deallocate 0xd7410, value destructor 0xc75f4) that a single natural
   template would re-emit as local weak copies in this object. Names provisional. */
/* Short-string-optimised string: bit 0 of cap set = heap storage. */
struct String_000d71a8 {
    unsigned cap;
    unsigned size;
    char *data;
    ~String_000d71a8() { if (cap & 1) operator delete(data); }
};
struct Value_000d71a8 { String_000d71a8 first; int second; };
struct Node_000d71a8 { Node_000d71a8 *left; Node_000d71a8 *right; Node_000d71a8 *parent; Value_000d71a8 value; };
struct Tree_000d71a8; /* only passed through */
extern "C" {
void *FUN_000d7458(Tree_000d71a8 *tree);
void FUN_000d7420(void *a, Value_000d71a8 *p);
void *FUN_000d7418(Tree_000d71a8 *tree);
void FUN_000d7410(void *a, Node_000d71a8 *p, unsigned n);
void FUN_000c75f4(Value_000d71a8 *p, int flags);
void FUN_000d71a8(Tree_000d71a8 *tree, Node_000d71a8 *node);
}
static inline void Destroy2_000d71a8(Tree_000d71a8 *tree, Node_000d71a8 *node)
{
    if (node->left)
        FUN_000d71a8(tree, node->left);
    if (node->right)
        FUN_000d71a8(tree, node->right);
    FUN_000d7420(FUN_000d7458(tree), &node->value);
    FUN_000d7410(FUN_000d7418(tree), node, 1);
}
static inline void Destroy1_000d71a8(Tree_000d71a8 *tree, Node_000d71a8 *node)
{
    if (node->left)
        Destroy2_000d71a8(tree, node->left);
    if (node->right)
        Destroy2_000d71a8(tree, node->right);
    FUN_000d7458(tree);
    FUN_000c75f4(&node->value, -1);
    FUN_000d7418(tree);
    operator delete(node);
}
inline void DestroyValue_000d71a8(Value_000d71a8 *p) { p->~Value_000d71a8(); }
/* Destroys the subtree below node and then node itself (children first). */
extern "C" void FUN_000d71a8(Tree_000d71a8 *tree, Node_000d71a8 *node)
{
    if (node->left)
        Destroy1_000d71a8(tree, node->left);
    if (node->right)
        Destroy1_000d71a8(tree, node->right);
    DestroyValue_000d71a8(&node->value);
    operator delete(node);
}

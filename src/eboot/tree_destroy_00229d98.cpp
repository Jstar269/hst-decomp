/* HSTMATCH module=EBOOT.BIN start=0x00229d98 end=0x00229fbc symbol=FUN_00229d98 lang=c++ */
/* Clone of src/eboot/tree_destroy_00196720.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_00229d98 { int v; };
struct Node_00229d98 { Node_00229d98 *left; Node_00229d98 *right; Node_00229d98 *parent; Value_00229d98 value; };
struct Tree_00229d98;
extern "C" {
void FUN_00066efc(void *alloc, Value_00229d98 *p);
void FUN_00229fbc(void *alloc, Node_00229d98 *p, unsigned n);
void *FUN_00229fc4(Tree_00229d98 *t);
void *FUN_00229fcc(Tree_00229d98 *t);
void FUN_00229d98(Tree_00229d98 *t, Node_00229d98 *n);
}
inline void Destroy2_00229d98(Tree_00229d98 *t, Node_00229d98 *n)
{
    if (n->left)
        FUN_00229d98(t, n->left);
    if (n->right)
        FUN_00229d98(t, n->right);
    FUN_00066efc(FUN_00229fcc(t), &n->value);
    FUN_00229fbc(FUN_00229fc4(t), n, 1);
}
inline void Destroy1_00229d98(Tree_00229d98 *t, Node_00229d98 *n)
{
    if (n->left)
        Destroy2_00229d98(t, n->left);
    if (n->right)
        Destroy2_00229d98(t, n->right);
    FUN_00229fcc(t);
    FUN_00229fc4(t);
    delete n;
}
extern "C" void FUN_00229d98(Tree_00229d98 *t, Node_00229d98 *n)
{
    if (n->left)
        Destroy1_00229d98(t, n->left);
    if (n->right)
        Destroy1_00229d98(t, n->right);
    delete n;
}

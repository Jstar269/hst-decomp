/* HSTMATCH module=EBOOT.BIN start=0x00066cc8 end=0x00066eec symbol=FUN_00066cc8 lang=c++ */
/* Clone of src/eboot/tree_destroy_00196720.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree teardown: free the left and right subtrees, then the node. Retail is a recursive member whose
   recursion was inlined two levels deep: at the first inlined level the allocator accessors stay out of
   line (0x196954 value allocator = this, 0x19694c node allocator = this+4) with their results unused, at
   the second the value destroy (0x66efc, empty) and node deallocate (0x196944) are calls too and deeper
   subtrees recurse through this function. Written here with the levels unrolled. Names provisional. */
struct Value_00066cc8 { int v; };
struct Node_00066cc8 { Node_00066cc8 *left; Node_00066cc8 *right; Node_00066cc8 *parent; Value_00066cc8 value; };
struct Tree_00066cc8;
extern "C" {
void FUN_00066efc(void *alloc, Value_00066cc8 *p);
void FUN_00066eec(void *alloc, Node_00066cc8 *p, unsigned n);
void *FUN_00066ef4(Tree_00066cc8 *t);
void *FUN_00066f04(Tree_00066cc8 *t);
void FUN_00066cc8(Tree_00066cc8 *t, Node_00066cc8 *n);
}
inline void Destroy2_00066cc8(Tree_00066cc8 *t, Node_00066cc8 *n)
{
    if (n->left)
        FUN_00066cc8(t, n->left);
    if (n->right)
        FUN_00066cc8(t, n->right);
    FUN_00066efc(FUN_00066f04(t), &n->value);
    FUN_00066eec(FUN_00066ef4(t), n, 1);
}
inline void Destroy1_00066cc8(Tree_00066cc8 *t, Node_00066cc8 *n)
{
    if (n->left)
        Destroy2_00066cc8(t, n->left);
    if (n->right)
        Destroy2_00066cc8(t, n->right);
    FUN_00066f04(t);
    FUN_00066ef4(t);
    delete n;
}
extern "C" void FUN_00066cc8(Tree_00066cc8 *t, Node_00066cc8 *n)
{
    if (n->left)
        Destroy1_00066cc8(t, n->left);
    if (n->right)
        Destroy1_00066cc8(t, n->right);
    delete n;
}

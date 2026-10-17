/* HSTMATCH module=EBOOT.BIN start=0x00229cfc end=0x00229d60 symbol=FUN_00229cfc lang=c++ */
/* Clone of src/eboot/tree_lower_bound_cstr_001966bc.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree lower_bound for C-string keys (strcmp 0x14934), called by tree_find_cstr_00196478.cpp: walk from x down,
   remembering the last node whose key is not less than *key. The branch is written `cmp >= 0` first (go left
   and remember) with the `< 0` case as the else; the opposite order gives the wrong branch layout. Names
   provisional. */
struct Node_00229cfc { Node_00229cfc *l; Node_00229cfc *r; unsigned parent; const char *key; };
struct Tree_00229cfc { int pad0; Node_00229cfc *root; };
extern "C" int FUN_00014934(const char *, const char *);
extern "C" Node_00229cfc *FUN_00229cfc(Tree_00229cfc *, const char *const *key, Node_00229cfc *x, Node_00229cfc *y)
{
    while (x) { if (FUN_00014934(x->key, *key) >= 0) { y = x; x = x->l; } else x = x->r; }
    return y;
}

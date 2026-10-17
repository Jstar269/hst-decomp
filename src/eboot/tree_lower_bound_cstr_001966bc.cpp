/* HSTMATCH module=EBOOT.BIN start=0x001966bc end=0x00196720 symbol=FUN_001966bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree lower_bound for C-string keys (strcmp 0x14934), called by tree_find_cstr_00196478.cpp: walk from x down,
   remembering the last node whose key is not less than *key. The branch is written `cmp >= 0` first (go left
   and remember) with the `< 0` case as the else; the opposite order gives the wrong branch layout. Names
   provisional. */
struct Node_001966bc { Node_001966bc *l; Node_001966bc *r; unsigned parent; const char *key; };
struct Tree_001966bc { int pad0; Node_001966bc *root; };
extern "C" int FUN_00014934(const char *, const char *);
extern "C" Node_001966bc *FUN_001966bc(Tree_001966bc *, const char *const *key, Node_001966bc *x, Node_001966bc *y)
{
    while (x) { if (FUN_00014934(x->key, *key) >= 0) { y = x; x = x->l; } else x = x->r; }
    return y;
}

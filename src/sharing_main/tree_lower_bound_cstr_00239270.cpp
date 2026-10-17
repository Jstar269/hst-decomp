/* HSTMATCH module=hstp_trans_main.prx start=0x00239270 end=0x002392d4 symbol=FUN_00239270 lang=c++ */
/* Clone of src/eboot/tree_lower_bound_cstr_00066444.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree lower_bound for C-string keys (strcmp 0x14934), called by tree_find_cstr_00196478.cpp: walk from x down,
   remembering the last node whose key is not less than *key. The branch is written `cmp >= 0` first (go left
   and remember) with the `< 0` case as the else; the opposite order gives the wrong branch layout. Names
   provisional. */
struct Node_00239270 { Node_00239270 *l; Node_00239270 *r; unsigned parent; const char *key; };
struct Tree_00239270 { int pad0; Node_00239270 *root; };
extern "C" int FUN_00014934(const char *, const char *);
extern "C" Node_00239270 *FUN_00239270(Tree_00239270 *, const char *const *key, Node_00239270 *x, Node_00239270 *y)
{
    while (x) { if (FUN_00014934(x->key, *key) >= 0) { y = x; x = x->l; } else x = x->r; }
    return y;
}

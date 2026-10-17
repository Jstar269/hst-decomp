/* HSTMATCH module=EBOOT.BIN start=0x00196478 end=0x001964f8 symbol=FUN_00196478 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree find(key) for C-string keys (strcmp 0x14934): lower_bound from the root (tree+4 doubles as the end/header node), not found when it is end or key < node key (+12); the result iterator is stored through a0. Same shape as tree_find_000d53bc. */
struct Node { Node *l; Node *r; unsigned parent; const char *key; };
struct Tree { int pad0; Node *root; };
extern "C" Node *FUN_001966bc(Tree *, const char *const *, Node *, Node *);
extern "C" int FUN_00014934(const char *, const char *);
extern "C" void FUN_00196478(Node **out, Tree *t, const char *const *key)
{
    Node *it = FUN_001966bc(t, key, t->root, (Node *)&t->root);
    if (it == (Node *)&t->root || FUN_00014934(*key, it->key) < 0)
        *out = (Node *)&t->root;
    else
        *out = it;
}

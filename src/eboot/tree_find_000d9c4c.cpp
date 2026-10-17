/* HSTMATCH module=EBOOT.BIN start=0x000d9c4c end=0x000d9ccc symbol=FUN_000d9c4c lang=c++ */
/* Clone of src/eboot/tree_find_000d53bc.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Tree find(key): lower_bound from the root (tree+4 doubles as the end/header node), then the not-found test compares key against the node key (+12); the result iterator is stored through a0. */
struct Node { Node *l; Node *r; int pad; char key[4]; };
struct Tree { int pad0; Node *root; };
extern "C" Node *FUN_000da294(Tree *, void *, Node *, Node *);
extern "C" int FUN_0000430c(void *, void *);
extern "C" void FUN_000d9c4c(Node **out, Tree *t, void *key)
{
    Node *it = FUN_000da294(t, key, t->root, (Node *)&t->root);
    if (it == (Node *)&t->root || FUN_0000430c(key, it->key) < 0)
        *out = (Node *)&t->root;
    else
        *out = it;
}

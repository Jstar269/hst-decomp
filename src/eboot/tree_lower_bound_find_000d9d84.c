/* HSTMATCH module=EBOOT.BIN start=0x000d9d84 end=0x000d9df8 symbol=FUN_000d9d84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node { struct Node *left; struct Node *right; int pad; short key; };
struct Tree { int pad; struct Node header; };

extern struct Node * FUN_000da39c(struct Tree *, short *, struct Node *, struct Node *);

/* find(): *out = node whose key equals *key, or the end (header) node when there is none. */
void FUN_000d9d84(struct Node **out, struct Tree *tree, short *key)
{
  struct Node *it;

  it = FUN_000da39c(tree, key, tree->header.left, &tree->header);
  if (it == &tree->header || *key < it->key) {
    *out = &tree->header;
  }
  else {
    *out = it;
  }
}

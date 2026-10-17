/* HSTMATCH module=EBOOT.BIN start=0x000d9d84 end=0x000d9df8 symbol=FUN_000d9d84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node { struct Node *left; struct Node *right; int pad; short key; };
struct Tree { int pad; struct Node header; };

extern struct Node * FUN_000da39c(struct Tree *, short *, struct Node *, struct Node *);

void FUN_000d9d84(struct Node **param_1, struct Tree *param_2, short *param_3)
{
  struct Node *it;

  it = FUN_000da39c(param_2, param_3, param_2->header.left, &param_2->header);
  if (it == &param_2->header || *param_3 < it->key) {
    *param_1 = &param_2->header;
  }
  else {
    *param_1 = it;
  }
}

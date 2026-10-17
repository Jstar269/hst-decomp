/* HSTMATCH module=hstp_trans_main.prx start=0x000ddd44 end=0x000dddb8 symbol=FUN_000ddd44 lang=c99 */
/* Clone of src/eboot/tree_lower_bound_find_000d9d84.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node { struct Node *left; struct Node *right; int pad; short key; };
struct Tree { int pad; struct Node header; };

extern struct Node * FUN_000de35c(struct Tree *, short *, struct Node *, struct Node *);

void FUN_000ddd44(struct Node **param_1, struct Tree *param_2, short *param_3)
{
  struct Node *it;

  it = FUN_000de35c(param_2, param_3, param_2->header.left, &param_2->header);
  if (it == &param_2->header || *param_3 < it->key) {
    *param_1 = &param_2->header;
  }
  else {
    *param_1 = it;
  }
}

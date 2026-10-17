/* HSTMATCH module=EBOOT.BIN start=0x00229c4c end=0x00229cfc symbol=FUN_00229c4c lang=c++ */
/* Clone of src/eboot/tree_find_insert_pos_0019660c.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree find-insert-position for C-string keys (strcmp at 0x14934): walk from the root (header at
   tree+4), remember the parent, the last node not greater than the key (j) and the left/leftmost flags.
   The parent must be declared before the cursor (register order). Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b);
struct Node_00229c4c {
    Node_00229c4c *left_;
    Node_00229c4c *right_;
    unsigned parent_;
    const char *key_;
};
struct Tree_00229c4c {
    unsigned size_;
    Node_00229c4c header_;
};
extern "C" Node_00229c4c *FUN_00229c4c(Tree_00229c4c *t, const char *const &k, Node_00229c4c *&j, bool &left, bool &leftmost)
{
    j = 0;
    Node_00229c4c *y = &t->header_;
    Node_00229c4c *x = t->header_.left_;
    left = true;
    leftmost = true;
    while (x != 0) {
        y = x;
        if (FUN_00014934(k, x->key_) < 0) {
            x = x->left_;
            left = true;
        } else {
            j = x;
            x = x->right_;
            left = false;
            leftmost = false;
        }
    }
    return y;
}

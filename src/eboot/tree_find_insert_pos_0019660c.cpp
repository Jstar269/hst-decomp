/* HSTMATCH module=EBOOT.BIN start=0x0019660c end=0x001966bc symbol=FUN_0019660c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree find-insert-position for C-string keys (strcmp at 0x14934): walk from the root (header at
   tree+4), remember the parent, the last node not greater than the key (j) and the left/leftmost flags.
   The parent must be declared before the cursor (register order). Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b);
struct Node_0019660c {
    Node_0019660c *left_;
    Node_0019660c *right_;
    unsigned parent_;
    const char *key_;
};
struct Tree_0019660c {
    unsigned size_;
    Node_0019660c header_;
};
extern "C" Node_0019660c *FUN_0019660c(Tree_0019660c *t, const char *const &k, Node_0019660c *&j, bool &left, bool &leftmost)
{
    j = 0;
    Node_0019660c *y = &t->header_;
    Node_0019660c *x = t->header_.left_;
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

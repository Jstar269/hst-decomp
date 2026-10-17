/* HSTMATCH module=hstp_trans_main.prx start=0x000677e8 end=0x00067898 symbol=FUN_000677e8 lang=c++ */
/* Clone of src/eboot/tree_find_insert_pos_00066394.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree find-insert-position for C-string keys (strcmp at 0x14934): walk from the root (header at
   tree+4), remember the parent, the last node not greater than the key (j) and the left/leftmost flags.
   The parent must be declared before the cursor (register order). Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b);
struct Node_000677e8 {
    Node_000677e8 *left_;
    Node_000677e8 *right_;
    unsigned parent_;
    const char *key_;
};
struct Tree_000677e8 {
    unsigned size_;
    Node_000677e8 header_;
};
extern "C" Node_000677e8 *FUN_000677e8(Tree_000677e8 *t, const char *const &k, Node_000677e8 *&j, bool &left, bool &leftmost)
{
    j = 0;
    Node_000677e8 *y = &t->header_;
    Node_000677e8 *x = t->header_.left_;
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

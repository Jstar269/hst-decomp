/* HSTMATCH module=hstp_trans_main.prx start=0x001a2f04 end=0x001a2fb4 symbol=FUN_001a2f04 lang=c++ */
/* Clone of src/eboot/tree_find_insert_pos_00066394.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree find-insert-position for C-string keys (strcmp at 0x14934): walk from the root (header at
   tree+4), remember the parent, the last node not greater than the key (j) and the left/leftmost flags.
   The parent must be declared before the cursor (register order). Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b);
struct Node_001a2f04 {
    Node_001a2f04 *left_;
    Node_001a2f04 *right_;
    unsigned parent_;
    const char *key_;
};
struct Tree_001a2f04 {
    unsigned size_;
    Node_001a2f04 header_;
};
extern "C" Node_001a2f04 *FUN_001a2f04(Tree_001a2f04 *t, const char *const &k, Node_001a2f04 *&j, bool &left, bool &leftmost)
{
    j = 0;
    Node_001a2f04 *y = &t->header_;
    Node_001a2f04 *x = t->header_.left_;
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

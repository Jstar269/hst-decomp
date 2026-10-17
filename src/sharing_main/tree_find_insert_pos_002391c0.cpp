/* HSTMATCH module=hstp_trans_main.prx start=0x002391c0 end=0x00239270 symbol=FUN_002391c0 lang=c++ */
/* Clone of src/eboot/tree_find_insert_pos_00066394.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree find-insert-position for C-string keys (strcmp at 0x14934): walk from the root (header at
   tree+4), remember the parent, the last node not greater than the key (j) and the left/leftmost flags.
   The parent must be declared before the cursor (register order). Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b);
struct Node_002391c0 {
    Node_002391c0 *left_;
    Node_002391c0 *right_;
    unsigned parent_;
    const char *key_;
};
struct Tree_002391c0 {
    unsigned size_;
    Node_002391c0 header_;
};
extern "C" Node_002391c0 *FUN_002391c0(Tree_002391c0 *t, const char *const &k, Node_002391c0 *&j, bool &left, bool &leftmost)
{
    j = 0;
    Node_002391c0 *y = &t->header_;
    Node_002391c0 *x = t->header_.left_;
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

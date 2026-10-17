/* HSTMATCH module=EBOOT.BIN start=0x00066280 end=0x00066338 symbol=FUN_00066280 lang=c++ */
/* Clone of src/eboot/tree_insert_unique_001964f8.cpp (hstclone.py tag c40): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for C-string keys (value {key, data}): find the insert position
   (tree_find_insert_pos_00066394), insert through tree_insert_node_00066f0c unless j's key equals the
   new key (strcmp 0x14934), and return pair<iterator, bool>. The bool values come from writable byte
   globals (0x2d11d0 true, 0x2d11d1 false); `const` globals would be loaded before the node store.
   Same shape as tree_insert_unique_000d5bf0. Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b); /* strcmp */
struct Value_00066280 { const char *key; int data; };
struct Node_00066280 {
    Node_00066280 *left_;
    Node_00066280 *right_;
    unsigned parent_;
    Value_00066280 value_;
};
struct Tree_00066280;
struct Result_00066280 { Node_00066280 *node; bool inserted; };
extern "C" {
extern bool DAT_002d11d0; /* true */
extern bool DAT_002d11d1; /* false */
Node_00066280 *FUN_00066394(Tree_00066280 *t, const Value_00066280 &v, Node_00066280 *&j, bool &left, bool &leftmost);
Node_00066280 *FUN_00066f0c(Tree_00066280 *t, Node_00066280 *parent, bool left, bool leftmost, const Value_00066280 &v);
}
extern "C" void FUN_00066280(Result_00066280 *r, Tree_00066280 *t, const Value_00066280 &v)
{
    bool left;
    bool leftmost;
    Node_00066280 *j;
    Node_00066280 *y = FUN_00066394(t, v, j, left, leftmost);
    if (j == 0 || FUN_00014934(j->value_.key, v.key) < 0) {
        r->node = FUN_00066f0c(t, y, left, leftmost, v);
        r->inserted = DAT_002d11d0;
    } else {
        r->node = j;
        r->inserted = DAT_002d11d1;
    }
}

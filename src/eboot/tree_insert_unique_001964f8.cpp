/* HSTMATCH module=EBOOT.BIN start=0x001964f8 end=0x001965b0 symbol=FUN_001964f8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for C-string keys (value {key, data}): find the insert position
   (tree_find_insert_pos_0019660c), insert through tree_insert_node_0019695c unless j's key equals the
   new key (strcmp 0x14934), and return pair<iterator, bool>. The bool values come from writable byte
   globals (0x2e15e1 true, 0x2e15e2 false); `const` globals would be loaded before the node store.
   Same shape as tree_insert_unique_000d5bf0. Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b); /* strcmp */
struct Value_001964f8 { const char *key; int data; };
struct Node_001964f8 {
    Node_001964f8 *left_;
    Node_001964f8 *right_;
    unsigned parent_;
    Value_001964f8 value_;
};
struct Tree_001964f8;
struct Result_001964f8 { Node_001964f8 *node; bool inserted; };
extern "C" {
extern bool DAT_002e15e1; /* true */
extern bool DAT_002e15e2; /* false */
Node_001964f8 *FUN_0019660c(Tree_001964f8 *t, const Value_001964f8 &v, Node_001964f8 *&j, bool &left, bool &leftmost);
Node_001964f8 *FUN_0019695c(Tree_001964f8 *t, Node_001964f8 *parent, bool left, bool leftmost, const Value_001964f8 &v);
}
/* Insert `value` unless an equal key is already present; result gets the node and whether it was inserted. */
extern "C" void FUN_001964f8(Result_001964f8 *result, Tree_001964f8 *tree, const Value_001964f8 &value)
{
    bool left;
    bool leftmost;
    Node_001964f8 *j;
    Node_001964f8 *parent = FUN_0019660c(tree, value, j, left, leftmost);
    if (j == 0 || FUN_00014934(j->value_.key, value.key) < 0) {
        result->node = FUN_0019695c(tree, parent, left, leftmost, value);
        result->inserted = DAT_002e15e1;
    } else {
        result->node = j;
        result->inserted = DAT_002e15e2;
    }
}

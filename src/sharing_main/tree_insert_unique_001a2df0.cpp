/* HSTMATCH module=hstp_trans_main.prx start=0x001a2df0 end=0x001a2ea8 symbol=FUN_001a2df0 lang=c++ */
/* Clone of src/eboot/tree_insert_unique_001964f8.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for C-string keys (value {key, data}): find the insert position
   (tree_find_insert_pos_001a2f04), insert through tree_insert_node_001a3254 unless j's key equals the
   new key (strcmp 0x14934), and return pair<iterator, bool>. The bool values come from writable byte
   globals (0x388d25 true, 0x388d26 false); `const` globals would be loaded before the node store.
   Same shape as tree_insert_unique_000d5bf0. Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b); /* strcmp */
struct Value_001a2df0 { const char *key; int data; };
struct Node_001a2df0 {
    Node_001a2df0 *left_;
    Node_001a2df0 *right_;
    unsigned parent_;
    Value_001a2df0 value_;
};
struct Tree_001a2df0;
struct Result_001a2df0 { Node_001a2df0 *node; bool inserted; };
extern "C" {
extern bool DAT_00388d25; /* true */
extern bool DAT_00388d26; /* false */
Node_001a2df0 *FUN_001a2f04(Tree_001a2df0 *t, const Value_001a2df0 &v, Node_001a2df0 *&j, bool &left, bool &leftmost);
Node_001a2df0 *FUN_001a3254(Tree_001a2df0 *t, Node_001a2df0 *parent, bool left, bool leftmost, const Value_001a2df0 &v);
}
extern "C" void FUN_001a2df0(Result_001a2df0 *r, Tree_001a2df0 *t, const Value_001a2df0 &v)
{
    bool left;
    bool leftmost;
    Node_001a2df0 *j;
    Node_001a2df0 *y = FUN_001a2f04(t, v, j, left, leftmost);
    if (j == 0 || FUN_00014934(j->value_.key, v.key) < 0) {
        r->node = FUN_001a3254(t, y, left, leftmost, v);
        r->inserted = DAT_00388d25;
    } else {
        r->node = j;
        r->inserted = DAT_00388d26;
    }
}

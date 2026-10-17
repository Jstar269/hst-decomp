/* HSTMATCH module=hstp_trans_main.prx start=0x000676d4 end=0x0006778c symbol=FUN_000676d4 lang=c++ */
/* Clone of src/eboot/tree_insert_unique_001964f8.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for C-string keys (value {key, data}): find the insert position
   (tree_find_insert_pos_000677e8), insert through tree_insert_node_00068360 unless j's key equals the
   new key (strcmp 0x14934), and return pair<iterator, bool>. The bool values come from writable byte
   globals (0x37715e true, 0x37715f false); `const` globals would be loaded before the node store.
   Same shape as tree_insert_unique_000d5bf0. Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b); /* strcmp */
struct Value_000676d4 { const char *key; int data; };
struct Node_000676d4 {
    Node_000676d4 *left_;
    Node_000676d4 *right_;
    unsigned parent_;
    Value_000676d4 value_;
};
struct Tree_000676d4;
struct Result_000676d4 { Node_000676d4 *node; bool inserted; };
extern "C" {
extern bool DAT_0037715e; /* true */
extern bool DAT_0037715f; /* false */
Node_000676d4 *FUN_000677e8(Tree_000676d4 *t, const Value_000676d4 &v, Node_000676d4 *&j, bool &left, bool &leftmost);
Node_000676d4 *FUN_00068360(Tree_000676d4 *t, Node_000676d4 *parent, bool left, bool leftmost, const Value_000676d4 &v);
}
extern "C" void FUN_000676d4(Result_000676d4 *r, Tree_000676d4 *t, const Value_000676d4 &v)
{
    bool left;
    bool leftmost;
    Node_000676d4 *j;
    Node_000676d4 *y = FUN_000677e8(t, v, j, left, leftmost);
    if (j == 0 || FUN_00014934(j->value_.key, v.key) < 0) {
        r->node = FUN_00068360(t, y, left, leftmost, v);
        r->inserted = DAT_0037715e;
    } else {
        r->node = j;
        r->inserted = DAT_0037715f;
    }
}

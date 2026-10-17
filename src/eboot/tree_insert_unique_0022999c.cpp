/* HSTMATCH module=EBOOT.BIN start=0x0022999c end=0x00229a54 symbol=FUN_0022999c lang=c++ */
/* Clone of src/eboot/tree_insert_unique_001964f8.cpp (hstclone.py tag c40): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for C-string keys (value {key, data}): find the insert position
   (tree_find_insert_pos_00229c4c), insert through tree_insert_node_00229fd4 unless j's key equals the
   new key (strcmp 0x14934), and return pair<iterator, bool>. The bool values come from writable byte
   globals (0x2f2b59 true, 0x2f2b5a false); `const` globals would be loaded before the node store.
   Same shape as tree_insert_unique_000d5bf0. Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b); /* strcmp */
struct Value_0022999c { const char *key; int data; };
struct Node_0022999c {
    Node_0022999c *left_;
    Node_0022999c *right_;
    unsigned parent_;
    Value_0022999c value_;
};
struct Tree_0022999c;
struct Result_0022999c { Node_0022999c *node; bool inserted; };
extern "C" {
extern bool DAT_002f2b59; /* true */
extern bool DAT_002f2b5a; /* false */
Node_0022999c *FUN_00229c4c(Tree_0022999c *t, const Value_0022999c &v, Node_0022999c *&j, bool &left, bool &leftmost);
Node_0022999c *FUN_00229fd4(Tree_0022999c *t, Node_0022999c *parent, bool left, bool leftmost, const Value_0022999c &v);
}
extern "C" void FUN_0022999c(Result_0022999c *r, Tree_0022999c *t, const Value_0022999c &v)
{
    bool left;
    bool leftmost;
    Node_0022999c *j;
    Node_0022999c *y = FUN_00229c4c(t, v, j, left, leftmost);
    if (j == 0 || FUN_00014934(j->value_.key, v.key) < 0) {
        r->node = FUN_00229fd4(t, y, left, leftmost, v);
        r->inserted = DAT_002f2b59;
    } else {
        r->node = j;
        r->inserted = DAT_002f2b5a;
    }
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00238f10 end=0x00238fc8 symbol=FUN_00238f10 lang=c++ */
/* Clone of src/eboot/tree_insert_unique_00066280.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for C-string keys (value {key, data}): find the insert position
   (tree_find_insert_pos_002391c0), insert through tree_insert_node_00239548 unless j's key equals the
   new key (strcmp 0x14934), and return pair<iterator, bool>. The bool values come from writable byte
   globals (0x39af25 true, 0x39af26 false); `const` globals would be loaded before the node store.
   Same shape as tree_insert_unique_000d5bf0. Names provisional. */
extern "C" int FUN_00014934(const char *a, const char *b); /* strcmp */
struct Value_00238f10 { const char *key; int data; };
struct Node_00238f10 {
    Node_00238f10 *left_;
    Node_00238f10 *right_;
    unsigned parent_;
    Value_00238f10 value_;
};
struct Tree_00238f10;
struct Result_00238f10 { Node_00238f10 *node; bool inserted; };
extern "C" {
extern bool DAT_0039af25; /* true */
extern bool DAT_0039af26; /* false */
Node_00238f10 *FUN_002391c0(Tree_00238f10 *t, const Value_00238f10 &v, Node_00238f10 *&j, bool &left, bool &leftmost);
Node_00238f10 *FUN_00239548(Tree_00238f10 *t, Node_00238f10 *parent, bool left, bool leftmost, const Value_00238f10 &v);
}
extern "C" void FUN_00238f10(Result_00238f10 *r, Tree_00238f10 *t, const Value_00238f10 &v)
{
    bool left;
    bool leftmost;
    Node_00238f10 *j;
    Node_00238f10 *y = FUN_002391c0(t, v, j, left, leftmost);
    if (j == 0 || FUN_00014934(j->value_.key, v.key) < 0) {
        r->node = FUN_00239548(t, y, left, leftmost, v);
        r->inserted = DAT_0039af25;
    } else {
        r->node = j;
        r->inserted = DAT_0039af26;
    }
}

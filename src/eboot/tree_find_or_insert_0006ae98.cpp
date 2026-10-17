/* HSTMATCH module=EBOOT.BIN start=0x0006ae98 end=0x0006af20 symbol=FUN_0006ae98 lang=c++ */
/* Clone of src/sharing_main/tree_find_or_insert_0006c480.cpp (hstclone.py tag u1r5e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Value {
    unsigned int key;
    int data;
};

struct Node {
    Node *left_;
    Node *right_;
    unsigned parent_;
    Value value_;
};

struct Tree;

extern "C" {
Node *FUN_0006c0a0(Tree *t, const unsigned int *k, Node *&j, bool &b1, bool &b2);
Node *FUN_0006c3b0(Tree *t, Node *y, bool b1, bool b2, const Value &v);
}

extern "C" Value *FUN_0006ae98(Tree *t, const unsigned int *k)
{
    bool b1;
    bool b2;
    Node *j;
    Node *y = FUN_0006c0a0(t, k, j, b1, b2);
    if (j == 0 || j->value_.key < *k) {
        Value v;
        v.key = *k;
        v.data = 0;
        return &FUN_0006c3b0(t, y, b1, b2, v)->value_;
    }
    return &j->value_;
}

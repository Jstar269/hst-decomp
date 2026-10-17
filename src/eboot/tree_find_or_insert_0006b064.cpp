/* HSTMATCH module=EBOOT.BIN start=0x0006b064 end=0x0006b0f4 symbol=FUN_0006b064 lang=c++ */
/* Clone of src/sharing_main/tree_find_or_insert_0006c64c.cpp (hstclone.py tag u1r5e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" int DAT_002d12c0;

struct Value {
    int key;
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
Node *FUN_0006bf8c(Tree *t, const int *k, Node *&j, bool &b1, bool &b2);
Node *FUN_0006c744(Tree *t, Node *y, bool b1, bool b2, const Value &v);
}

extern "C" Value *FUN_0006b064(Tree *t, const int *k)
{
    bool b1;
    bool b2;
    Node *j;
    Node *y = FUN_0006bf8c(t, k, j, b1, b2);
    if (j == 0 || j->value_.key < *k) {
        Value v;
        v.key = *k;
        v.data = DAT_002d12c0;
        return &FUN_0006c744(t, y, b1, b2, v)->value_;
    }
    return &j->value_;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0006c480 end=0x0006c508 symbol=FUN_0006c480 lang=c++ */
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
Node *FUN_0006d688(Tree *t, const unsigned int *k, Node *&j, bool &b1, bool &b2);
Node *FUN_0006d998(Tree *t, Node *y, bool b1, bool b2, const Value &v);
}

extern "C" Value *FUN_0006c480(Tree *t, const unsigned int *k)
{
    bool b1;
    bool b2;
    Node *j;
    Node *y = FUN_0006d688(t, k, j, b1, b2);
    if (j == 0 || j->value_.key < *k) {
        Value v;
        v.key = *k;
        v.data = 0;
        return &FUN_0006d998(t, y, b1, b2, v)->value_;
    }
    return &j->value_;
}

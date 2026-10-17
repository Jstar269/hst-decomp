/* HSTMATCH module=hstp_trans_main.prx start=0x0006c64c end=0x0006c6dc symbol=FUN_0006c64c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" int DAT_003772d4;

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
Node *FUN_0006d574(Tree *t, const int *k, Node *&j, bool &b1, bool &b2);
Node *FUN_0006dd2c(Tree *t, Node *y, bool b1, bool b2, const Value &v);
}

extern "C" Value *FUN_0006c64c(Tree *t, const int *k)
{
    bool b1;
    bool b2;
    Node *j;
    Node *y = FUN_0006d574(t, k, j, b1, b2);
    if (j == 0 || j->value_.key < *k) {
        Value v;
        v.key = *k;
        v.data = DAT_003772d4;
        return &FUN_0006dd2c(t, y, b1, b2, v)->value_;
    }
    return &j->value_;
}

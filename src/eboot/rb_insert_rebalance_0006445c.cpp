/* HSTMATCH module=EBOOT.BIN start=0x0006445c end=0x00064668 symbol=FUN_0006445c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Node {
    Node *left;
    Node *right;
    Node *parent_;   /* low bit = colour (1 = red) */

    Node *parent() const { return (Node *)((unsigned int)parent_ & ~1u); }
    bool is_red() const { return (unsigned int)parent_ & 1; }
    void set_black() { parent_ = (Node *)((unsigned int)parent_ & ~1u); }
    void set_red() { parent_ = (Node *)((unsigned int)parent_ | 1); }
};

extern "C" void FUN_00064668(Node *x, Node **root);
extern "C" void FUN_000646e8(Node *x, Node **root);

extern "C" void FUN_0006445c(Node *x, Node *root)
{
    x->set_red();
    while (x != root && x->parent()->is_red() == true) {
        Node *p = x->parent();
        Node *g = p->parent();
        if (p == g->left) {
            Node *y = g->right;
            if (y != 0 && y->is_red() == true) {
                x->parent()->set_black();
                y->set_black();
                x = x->parent()->parent();
                x->set_red();
            } else {
                if (x == x->parent()->right) {
                    x = x->parent();
                    FUN_000646e8(x, &root);
                }
                x->parent()->set_black();
                x->parent()->parent()->set_red();
                FUN_00064668(x->parent()->parent(), &root);
            }
        } else {
            Node *y = g->left;
            if (y != 0 && y->is_red() == true) {
                x->parent()->set_black();
                y->set_black();
                x = x->parent()->parent();
                x->set_red();
            } else {
                if (x == x->parent()->left) {
                    x = x->parent();
                    FUN_00064668(x, &root);
                }
                x->parent()->set_black();
                x->parent()->parent()->set_red();
                FUN_000646e8(x->parent()->parent(), &root);
            }
        }
    }
    root->set_black();
}

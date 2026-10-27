/* HSTMATCH module=hstp_trans_main.prx start=0x00065320 end=0x0006552c symbol=FUN_00065320 lang=c++ */
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

extern "C" void FUN_0006552c(Node *x, Node **root);
extern "C" void FUN_000655ac(Node *x, Node **root);

extern "C" void FUN_00065320(Node *x, Node *root)
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
                    FUN_000655ac(x, &root);
                }
                x->parent()->set_black();
                x->parent()->parent()->set_red();
                FUN_0006552c(x->parent()->parent(), &root);
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
                    FUN_0006552c(x, &root);
                }
                x->parent()->set_black();
                x->parent()->parent()->set_red();
                FUN_000655ac(x->parent()->parent(), &root);
            }
        }
    }
    root->set_black();
}

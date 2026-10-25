/* HSTMATCH module=EBOOT.BIN start=0x0006445c end=0x00064668 symbol=FUN_0006445c lang=c++ */
struct Node {
    Node *left;
    Node *right;
    Node *parent;   /* low bit = colour (1 = red) */
};

extern "C" void FUN_00064668(Node *x, Node **root);
extern "C" void FUN_000646e8(Node *x, Node **root);

static inline Node *Par(Node *n) { return (Node *)((unsigned int)n->parent & ~1u); }
static inline bool Red(Node *n) { return (unsigned int)n->parent & 1; }
static inline void SetBlack(Node *n) { n->parent = (Node *)((unsigned int)n->parent & ~1u); }
static inline void SetRed(Node *n) { n->parent = (Node *)((unsigned int)n->parent | 1); }

extern "C" void FUN_0006445c(Node *x, Node *rootIn)
{
    Node *root = rootIn;
    Node *p;

    SetRed(x);
    while (x != root && Red(Par(x)) != false) {
        p = Par(x);
        if (p == Par(p)->left) {
            if (Red(Par(p)->right)) {
                SetBlack(p);
                SetBlack(Par(p)->right);
                x = Par(p);
                SetRed(x);
                continue;
            }
            if (x == p->right) {
                x = p;
                FUN_000646e8(x, &root);
            }
            SetBlack(Par(x));
            SetRed(Par(Par(x)));
            FUN_00064668(Par(Par(x)), &root);
        } else {
            if (Red(Par(p)->left)) {
                SetBlack(p);
                SetBlack(Par(p)->left);
                x = Par(p);
                SetRed(x);
                continue;
            }
            if (x == p->left) {
                x = p;
                FUN_00064668(x, &root);
            }
            SetBlack(Par(x));
            SetRed(Par(Par(x)));
            FUN_000646e8(Par(Par(x)), &root);
        }
    }
    SetBlack(root);
}
// 0x0006445c: 115/131 words, 116 differ. Structure recovered (RB insert rebalance with
// colour in the low bit of the parent word; helper calls 0x64668 rot-right / 0x646e8 rot-left,
// root passed as a stack copy `Node *root = rootIn; &root`).
// Differs: retail lays the loop ROTATED (entry `b` to a shared loop test at the end of the body,
// body first; `continue` arms jump to it), MWCC keeps the test at the top for every while/for
// spelling tried, and retail re-reads x->parent three times in the rotate tail instead of caching.
// Ruled out: for(;;)+break, while(x!=root) with break, inline helper Par/Red/SetBlack wrappers.
// near miss from lane fm11 (unreviewed)

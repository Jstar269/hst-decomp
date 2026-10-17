/* HSTMATCH module=hstp_trans_main.prx start=0x000de15c end=0x000de254 symbol=FUN_000de15c lang=c++ */
/* Clone of src/eboot/tree_insert_pos_000da19c.cpp (hstclone.py tag u4r1-3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" int FUN_00003c74(const void *self, unsigned int pos, unsigned int n1, const char *s, unsigned int n2);

struct String {
    union {
        struct {
            unsigned char is_long : 1;
            unsigned char size : 7;
            char data[11];
        } s;
        struct {
            unsigned int is_long;
            unsigned int size;
            const char *ptr;
        } l;
    };
};

struct Node {
    Node *left;
    Node *right;
    unsigned int parent;
    String key;
};

struct Tree {
    int pad;
    Node *root;
};

extern "C" Node *FUN_000de15c(Tree *tree, const String &key, Node *&j, bool &left, bool &leftmost)
{
    Node *y;
    j = 0;
    Node *x = tree->root;
    left = true;
    y = (Node *)&tree->root;
    leftmost = true;
    if (x != 0) {
        do {
            const char *x_data;
            unsigned int x_size;
            y = x;
            if ((x->key.l.is_long & 1) == 0) {
                x_data = (const char *)&x->key.s.data;
                x_size = x->key.s.size;
            } else {
                x_data = x->key.l.ptr;
                x_size = x->key.l.size;
            }
            unsigned int key_size;
            if (key.l.is_long & 1) {
                key_size = key.l.size;
            } else {
                key_size = key.s.size;
            }
            if (FUN_00003c74(&key, 0, key_size, x_data, x_size) < 0) {
                x = x->left;
                left = true;
            } else {
                j = x;
                x = x->right;
                left = false;
                leftmost = false;
            }
        } while (x != 0);
    }
    return y;
}

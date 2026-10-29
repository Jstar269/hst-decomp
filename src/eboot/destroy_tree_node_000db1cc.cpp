/* HSTMATCH module=EBOOT.BIN start=0x000db1cc end=0x000db484 symbol=FUN_000db1cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Tag {};

/* Tree node: two child links, a value, and a small vector of 6-byte items. */
struct Node {
    Node *child[2];
    int unk08;
    int value;
    void *items;
    int item_count;
    int item_cap;
};

extern "C" {
void FUN_00000a00(void *p);
int FUN_000d98ac(void *p, int flag);
void FUN_000db484(void *alloc, void *elem);
void *FUN_000db48c(void *vec);
void *FUN_000db494(void *vec);
void FUN_000db4b0(void *alloc, void *node, int count);
void *FUN_000db4b8(void *ctx);
void FUN_000db4c0(void *alloc, void *elem);
void *FUN_000db4e4(void *ctx);
void FUN_000db1cc(void *ctx, Node *node);
}

static inline void TagHelper(Tag = Tag()) {}

/* Free every node below node (the first two levels of each child are unrolled), then the item vector and node. */
extern "C" void FUN_000db1cc(void *ctx, Node *node)
{
    TagHelper();
    Node *outer = node->child[0];
    if (outer != 0) {
        Node *inner = outer->child[0];
        if (inner != 0) {
            Node *left = inner->child[0];
            if (left != 0) {
                FUN_000db1cc(ctx, left);
            }
            Node *right = inner->child[1];
            if (right != 0) {
                FUN_000db1cc(ctx, right);
            }
            void *val_alloc = FUN_000db4e4(ctx);
            FUN_000db4c0(val_alloc, &inner->value);
            void *node_alloc = FUN_000db4b8(ctx);
            FUN_000db4b0(node_alloc, inner, 1);
        }
        inner = outer->child[1];
        if (inner != 0) {
            Node *left = inner->child[0];
            if (left != 0) {
                FUN_000db1cc(ctx, left);
            }
            Node *right = inner->child[1];
            if (right != 0) {
                FUN_000db1cc(ctx, right);
            }
            void *val_alloc = FUN_000db4e4(ctx);
            FUN_000db4c0(val_alloc, &inner->value);
            void *node_alloc = FUN_000db4b8(ctx);
            FUN_000db4b0(node_alloc, inner, 1);
        }
        FUN_000db4e4(ctx);
        FUN_000d98ac(&outer->value, -1);
        FUN_000db4b8(ctx);
        FUN_00000a00(outer);
    }
    outer = node->child[1];
    if (outer != 0) {
        Node *inner = outer->child[0];
        if (inner != 0) {
            Node *left = inner->child[0];
            if (left != 0) {
                FUN_000db1cc(ctx, left);
            }
            Node *right = inner->child[1];
            if (right != 0) {
                FUN_000db1cc(ctx, right);
            }
            void *val_alloc = FUN_000db4e4(ctx);
            FUN_000db4c0(val_alloc, &inner->value);
            void *node_alloc = FUN_000db4b8(ctx);
            FUN_000db4b0(node_alloc, inner, 1);
        }
        inner = outer->child[1];
        if (inner != 0) {
            Node *left = inner->child[0];
            if (left != 0) {
                FUN_000db1cc(ctx, left);
            }
            Node *right = inner->child[1];
            if (right != 0) {
                FUN_000db1cc(ctx, right);
            }
            void *val_alloc = FUN_000db4e4(ctx);
            FUN_000db4c0(val_alloc, &inner->value);
            void *node_alloc = FUN_000db4b8(ctx);
            FUN_000db4b0(node_alloc, inner, 1);
        }
        FUN_000db4e4(ctx);
        FUN_000d98ac(&outer->value, -1);
        FUN_000db4b8(ctx);
        FUN_00000a00(outer);
    }
    if (&node->value != 0) {
        if (&node->items != 0 && &node->items != 0 && &node->items != 0) {
            int count = node->item_count;
            char *end = (char *)FUN_000db494(&node->items);
            node->item_count = node->item_count - count;
            for (; count != 0; count--) {
                void *alloc = FUN_000db48c(&node->items);
                end -= 6;
                FUN_000db484(alloc, end);
            }
            if (node->items != 0) {
                FUN_00000a00(node->items);
            }
        }
    }
    FUN_00000a00(node);
}

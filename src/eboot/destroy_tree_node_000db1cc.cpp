/* HSTMATCH module=EBOOT.BIN start=0x000db1cc end=0x000db484 symbol=FUN_000db1cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Tag {};

struct Node {
    Node *child[2];
    int f08;
    int f0c;
    void *vec_data;
    int vec_size;
    int vec_cap;
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

extern "C" void FUN_000db1cc(void *ctx, Node *node)
{
    TagHelper();
    Node *s3 = node->child[0];
    if (s3 != 0) {
        Node *s2 = s3->child[0];
        if (s2 != 0) {
            Node *c0 = s2->child[0];
            if (c0 != 0) {
                FUN_000db1cc(ctx, c0);
            }
            Node *c1 = s2->child[1];
            if (c1 != 0) {
                FUN_000db1cc(ctx, c1);
            }
            void *u0 = FUN_000db4e4(ctx);
            FUN_000db4c0(u0, &s2->f0c);
            void *u1 = FUN_000db4b8(ctx);
            FUN_000db4b0(u1, s2, 1);
        }
        s2 = s3->child[1];
        if (s2 != 0) {
            Node *c0 = s2->child[0];
            if (c0 != 0) {
                FUN_000db1cc(ctx, c0);
            }
            Node *c1 = s2->child[1];
            if (c1 != 0) {
                FUN_000db1cc(ctx, c1);
            }
            void *u0 = FUN_000db4e4(ctx);
            FUN_000db4c0(u0, &s2->f0c);
            void *u1 = FUN_000db4b8(ctx);
            FUN_000db4b0(u1, s2, 1);
        }
        FUN_000db4e4(ctx);
        FUN_000d98ac(&s3->f0c, -1);
        FUN_000db4b8(ctx);
        FUN_00000a00(s3);
    }
    s3 = node->child[1];
    if (s3 != 0) {
        Node *s2 = s3->child[0];
        if (s2 != 0) {
            Node *c0 = s2->child[0];
            if (c0 != 0) {
                FUN_000db1cc(ctx, c0);
            }
            Node *c1 = s2->child[1];
            if (c1 != 0) {
                FUN_000db1cc(ctx, c1);
            }
            void *u0 = FUN_000db4e4(ctx);
            FUN_000db4c0(u0, &s2->f0c);
            void *u1 = FUN_000db4b8(ctx);
            FUN_000db4b0(u1, s2, 1);
        }
        s2 = s3->child[1];
        if (s2 != 0) {
            Node *c0 = s2->child[0];
            if (c0 != 0) {
                FUN_000db1cc(ctx, c0);
            }
            Node *c1 = s2->child[1];
            if (c1 != 0) {
                FUN_000db1cc(ctx, c1);
            }
            void *u0 = FUN_000db4e4(ctx);
            FUN_000db4c0(u0, &s2->f0c);
            void *u1 = FUN_000db4b8(ctx);
            FUN_000db4b0(u1, s2, 1);
        }
        FUN_000db4e4(ctx);
        FUN_000d98ac(&s3->f0c, -1);
        FUN_000db4b8(ctx);
        FUN_00000a00(s3);
    }
    if (&node->f0c != 0) {
        if (&node->vec_data != 0 && &node->vec_data != 0 && &node->vec_data != 0) {
            int sz = node->vec_size;
            char *end = (char *)FUN_000db494(&node->vec_data);
            node->vec_size = node->vec_size - sz;
            for (; sz != 0; sz--) {
                void *alloc = FUN_000db48c(&node->vec_data);
                end -= 6;
                FUN_000db484(alloc, end);
            }
            if (node->vec_data != 0) {
                FUN_00000a00(node->vec_data);
            }
        }
    }
    FUN_00000a00(node);
}

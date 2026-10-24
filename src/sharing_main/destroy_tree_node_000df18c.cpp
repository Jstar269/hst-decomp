/* HSTMATCH module=hstp_trans_main.prx start=0x000df18c end=0x000df444 symbol=FUN_000df18c lang=c++ */
/* Clone of src/eboot/destroy_tree_node_000db1cc.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
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
int FUN_000dd818(void *p, int flag);
void FUN_000df444(void *alloc, void *elem);
void *FUN_000df44c(void *vec);
void *FUN_000df454(void *vec);
void FUN_000df470(void *alloc, void *node, int count);
void *FUN_000df478(void *ctx);
void FUN_000df480(void *alloc, void *elem);
void *FUN_000df4a4(void *ctx);
void FUN_000df18c(void *ctx, Node *node);
}

static inline void TagHelper(Tag = Tag()) {}

extern "C" void FUN_000df18c(void *ctx, Node *node)
{
    TagHelper();
    Node *s3 = node->child[0];
    if (s3 != 0) {
        Node *s2 = s3->child[0];
        if (s2 != 0) {
            Node *c0 = s2->child[0];
            if (c0 != 0) {
                FUN_000df18c(ctx, c0);
            }
            Node *c1 = s2->child[1];
            if (c1 != 0) {
                FUN_000df18c(ctx, c1);
            }
            void *u0 = FUN_000df4a4(ctx);
            FUN_000df480(u0, &s2->f0c);
            void *u1 = FUN_000df478(ctx);
            FUN_000df470(u1, s2, 1);
        }
        s2 = s3->child[1];
        if (s2 != 0) {
            Node *c0 = s2->child[0];
            if (c0 != 0) {
                FUN_000df18c(ctx, c0);
            }
            Node *c1 = s2->child[1];
            if (c1 != 0) {
                FUN_000df18c(ctx, c1);
            }
            void *u0 = FUN_000df4a4(ctx);
            FUN_000df480(u0, &s2->f0c);
            void *u1 = FUN_000df478(ctx);
            FUN_000df470(u1, s2, 1);
        }
        FUN_000df4a4(ctx);
        FUN_000dd818(&s3->f0c, -1);
        FUN_000df478(ctx);
        FUN_00000a00(s3);
    }
    s3 = node->child[1];
    if (s3 != 0) {
        Node *s2 = s3->child[0];
        if (s2 != 0) {
            Node *c0 = s2->child[0];
            if (c0 != 0) {
                FUN_000df18c(ctx, c0);
            }
            Node *c1 = s2->child[1];
            if (c1 != 0) {
                FUN_000df18c(ctx, c1);
            }
            void *u0 = FUN_000df4a4(ctx);
            FUN_000df480(u0, &s2->f0c);
            void *u1 = FUN_000df478(ctx);
            FUN_000df470(u1, s2, 1);
        }
        s2 = s3->child[1];
        if (s2 != 0) {
            Node *c0 = s2->child[0];
            if (c0 != 0) {
                FUN_000df18c(ctx, c0);
            }
            Node *c1 = s2->child[1];
            if (c1 != 0) {
                FUN_000df18c(ctx, c1);
            }
            void *u0 = FUN_000df4a4(ctx);
            FUN_000df480(u0, &s2->f0c);
            void *u1 = FUN_000df478(ctx);
            FUN_000df470(u1, s2, 1);
        }
        FUN_000df4a4(ctx);
        FUN_000dd818(&s3->f0c, -1);
        FUN_000df478(ctx);
        FUN_00000a00(s3);
    }
    if (&node->f0c != 0) {
        if (&node->vec_data != 0 && &node->vec_data != 0 && &node->vec_data != 0) {
            int sz = node->vec_size;
            char *end = (char *)FUN_000df454(&node->vec_data);
            node->vec_size = node->vec_size - sz;
            for (; sz != 0; sz--) {
                void *alloc = FUN_000df44c(&node->vec_data);
                end -= 6;
                FUN_000df444(alloc, end);
            }
            if (node->vec_data != 0) {
                FUN_00000a00(node->vec_data);
            }
        }
    }
    FUN_00000a00(node);
}

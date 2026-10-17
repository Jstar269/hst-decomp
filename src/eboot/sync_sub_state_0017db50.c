/* HSTMATCH module=EBOOT.BIN start=0x0017db50 end=0x0017dc14 symbol=FUN_0017db50 lang=c99 */
/* Clone of src/sharing_main/sync_sub_state_0018a244.c (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sub {
    int f0;
    unsigned char f4;
    char pad[1];
    short f6;
    int f8;
};

struct Inner {
    char pad[0x1b4];
    int f1b4;
};

struct Node {
    char pad[0x60];
    struct Inner *f60;
};

struct Obj {
    char pad8[8];
    struct Node **nodes;
    char pad[740 - 12];
    struct Sub sub;
};

struct Table {
    char pad[0x3ec];
    void *(*fn)(int, int);
};

extern struct Table *FUN_0016bc70(void);
extern void FUN_0017b6b0(void *, void *, int, unsigned char, void *, int, int, int);

void FUN_0017db50(struct Obj *self)
{
    struct Node *node = self->nodes[self->sub.f0];
    struct Sub *sub = &self->sub;
    int s1 = 0;
    if (sub->f8 == 0x7fffffff) {
        if (node->f60 != 0) {
            s1 = node->f60->f1b4;
        }
    } else {
        s1 = sub->f8;
    }
    int s3 = sub->f0;
    struct Table *tab = FUN_0016bc70();
    unsigned char *res = (unsigned char *)tab->fn(s1, s3);
    FUN_0017b6b0(self, &sub->f6, sub->f0, sub->f4, &sub->f8, res[9] != 0, res[10] != 0, s1);
}

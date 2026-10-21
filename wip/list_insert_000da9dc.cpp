/* HSTMATCH module=EBOOT.BIN start=0x000da9dc end=0x000dab30 symbol=FUN_000da9dc lang=c++ */

extern "C" int FUN_0000fe3c();
extern "C" void FUN_000d9a00(void *err, const char *msg);
extern "C" void FUN_0000d518();
extern "C" void *__nw__FUi(unsigned n);
extern "C" void FUN_000041ec(void *dst, void *src);
extern "C" void FUN_0006445c(void *node, void *owner);
extern "C" void __dl__FPv(void *p);

extern char DAT_002d6ad4[];
extern char DAT_002c06d4[];

struct Node_da9dc {
    Node_da9dc *next;
    Node_da9dc *prev;
    int flags;
    char value[0x10];
};

extern "C" void *FUN_000da9dc(int *list, Node_da9dc **pos, int at_end, int set_last, void *value)
{
    if (*list == -1) {
        int e = FUN_0000fe3c();
        FUN_000d9a00(*(void **)(e + 0xc), DAT_002d6ad4);
        FUN_0000d518();
    }
    Node_da9dc *n = (Node_da9dc *)__nw__FUi(0x1c);
    if (n == 0) {
        int e = FUN_0000fe3c();
        FUN_000d9a00(*(void **)(e + 0xc), DAT_002c06d4);
        FUN_0000d518();
    }
    if (&n->value[0] != 0) {
        FUN_000041ec(&n->value[0], value);
        *(unsigned short *)(&n->value[0xc]) = *(unsigned short *)((char *)value + 0xc);
    }
    n->prev = 0;
    n->next = 0;
    n->flags = (int)pos | (n->flags & 1);
    if (at_end == 0)
        pos[1] = n;
    else
        pos[0] = n;
    *list = *list + 1;
    FUN_0006445c(n, (void *)list[1]);
    if (set_last != 0)
        list[3] = (int)n;
    return n;
}
// NEAR MISS (first attempt): 73/85 words. MSL list<T>::insert: length assert (tree::insert length error),
// new(0x1c) with the allocation-failure assert, placement copy of the payload at node+0xc (FUN_000041ec
// + u16 at +0xc), next/prev clear, `n->flags = (int)pos | (n->flags & 1)`, link at pos[0]/pos[1],
// `*list += 1`, FUN_0006445c(n, list[1]), `if (set_last) list[3] = n`. Missing: the stack holder temp
// (`sw s0,44(sp)` ... `sw zero,44(sp)` ... `if (t) delete t;`) that retail keeps at sp+44.
// near miss from lane ds10 (unreviewed)

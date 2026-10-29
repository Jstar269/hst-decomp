/* HSTMATCH module=EBOOT.BIN start=0x001b50a4 end=0x001b523c symbol=FUN_001b50a4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Destructor body of a class with two list members (+0x3c, +0xf0), 18 owned slots, two delete[] arrays. Matching idiom: the nested `if (l)` x3 in ClearList reproduces the three inlined member null checks; out/first/last iterators are address-taken locals declared in that order. */
struct Node;
struct Iter {
    Node *p;
};
struct List {
    int size;
    int sentinel;
    Node *first;
};

extern "C" {
extern char DAT_003092dc;
extern char DAT_0034179c;
void FUN_001b3590(void *, int);
void FUN_001b871c(void *);
void FUN_000622d4(int, int, int, int);
void FUN_001b3640(void *);
void FUN_001b23c0(void *, int);
void FUN_0001f0f0(void *, int);
void FUN_001b94f8(Iter *, List *, Iter *, Iter *);
void FUN_00000a00(void *);
void FUN_000009e4(void *);
}

struct Obj {
    void *vptr;
    char pad4[0x3c - 4];
    List listB;
    char pad48[0x5c - 0x48];
    void *arr5c;
    void *arr60;
    char pad64[0xa0 - 0x64];
    void *slots[18];
    char padE8[0xf0 - 0xe8];
    List listA;
};

static inline void ClearList(List *l)
{
    if (l) {
        if (l) {
            if (l) {
                Iter out;
                Iter first;
                Iter last;
                last.p = (Node *)&l->sentinel;
                first.p = (Node *)l->first;
                FUN_001b94f8(&out, l, &first, &last);
            }
        }
    }
}

extern "C" Obj *FUN_001b50a4(Obj *self, short flag)
{
    if (self) {
        self->vptr = &DAT_003092dc;
        FUN_001b3590(&DAT_0034179c, 0);
        FUN_001b871c(self);
        FUN_000622d4(3, 128, 128, 0);
        for (int i = 17; i >= 0; i--) {
            if (self->slots[i]) {
                FUN_00000a00(self->slots[i]);
                self->slots[i] = 0;
            }
        }
        if (self->arr60) {
            FUN_000009e4(self->arr60);
            self->arr60 = 0;
        }
        if (self->arr5c) {
            FUN_000009e4(self->arr5c);
            self->arr5c = 0;
        }
        FUN_001b3640(&DAT_0034179c);
        ClearList(&self->listA);
        if (&self->listB) {
            FUN_001b23c0(&DAT_0034179c, 0);
            ClearList(&self->listB);
        }
        FUN_0001f0f0(self, 0);
        if (flag > 0)
            FUN_00000a00(self);
    }
    return self;
}

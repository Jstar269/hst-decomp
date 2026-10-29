/* HSTMATCH module=EBOOT.BIN start=0x00224468 end=0x00224600 symbol=FUN_00224468 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/page_menu.h"

extern int DAT_00309624;
extern int DAT_002f11c8;
extern int DAT_002eff88;
extern int DAT_002f110c;
extern int DAT_002f115c;
extern int DAT_002f1170;
extern int DAT_002f117c;
extern int DAT_002f11a0;
extern int DAT_002f11ac;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" int FUN_001039d8(void *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void *FUN_00000bcc(unsigned int);
extern "C" void *FUN_001108fc(void *);

/* The menu is polymorphic; only slot 1 is called here. */
class Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

/* Row of the node lookup table: which child slot to search, the node id, and where the node's initial value is saved. */
struct Entry {
    int slotIndex;
    int id;
    int saved;
};

/* Record owned by the first node. */
struct Extra {
    char pad[0xd8];
    int unkD8;
    char pad2[0x114 - 0xdc];
    unsigned char unk114;
};

enum {
    CHILD_SLOTS = 3,
    HOOK_SIZE = 124
};

extern "C" PageMenu *FUN_00224468(PageMenu *self) {
    FUN_00102e38(self);
    self->vtable = &DAT_00309624;
    self->hook = 0;
    FUN_00104118(self, &DAT_002f11c8, 0);
    FUN_00103540(self, *(float *)&DAT_002eff88);
    int i = 0;
    int *tab = &DAT_002f110c;
    int off = 0;
    do {
        *(int *)((unsigned int)self + off + 0x58) = FUN_001039d8(self, *tab, 0);
        i++;
        tab++;
        off += 4;
    } while (i < CHILD_SLOTS);
    int k = 0;
    Entry *e = (Entry *)&DAT_002f115c;
    int off2 = 0;
    do {
        UiNode *n = (UiNode *)FUN_001026b8(*(int *)((char *)self + (e->slotIndex << 2) + 0x58), e->id);
        *(int *)((unsigned int)self + off2 + 0x64) = (int)n;
        e->saved = n->unk24;
        k++;
        off2 += 4;
        e++;
    } while (k < PAGE_MENU_NODES);
    Extra *p = (Extra *)self->node[0]->child;
    self->unk8c = p;
    p->unkD8 = 0;
    p->unk114 = 1;
    /* nodes 1, 2, 5 and 6 take their current and goal values from globals (the last two plus one) */
    int g0 = *(int *)&DAT_002f1170;
    UiNode *n1 = self->node[1];
    n1->unk24 = g0;
    n1->unk28 = g0;
    int g1 = *(int *)&DAT_002f117c;
    UiNode *n2 = self->node[2];
    n2->unk24 = g1;
    n2->unk28 = g1;
    int g2 = *(int *)&DAT_002f11a0 + 1;
    UiNode *n5 = self->node[5];
    n5->unk24 = g2;
    n5->unk28 = g2;
    int g3 = *(int *)&DAT_002f11ac + 1;
    UiNode *n6 = self->node[6];
    n6->unk24 = g3;
    n6->unk28 = g3;
    void *obj = FUN_00000bcc(HOOK_SIZE);
    if (obj != 0) {
        self->hook = FUN_001108fc(obj);
    } else {
        self->hook = obj;
    }
    ((Base *)self)->m1();
    return self;
}

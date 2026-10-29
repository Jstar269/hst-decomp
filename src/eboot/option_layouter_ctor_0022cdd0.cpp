/* HSTMATCH module=EBOOT.BIN start=0x0022cdd0 end=0x0022d250 symbol=FUN_0022cdd0 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane ol3 near miss reworked); exact match verified; names and types await human review. Matching idiom: byte-offset table loops written as (unsigned int)self + off + DISP with an (unsigned long) re-spelling after the call, so they keep self+off per pass with strength reduction on. */
enum { PANE_COUNT = 3, ITEM_COUNT = 70, SUB_COUNT = 12, TABLE_COUNT = 15 };

class VObj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int);
    virtual void m6(float);
};
struct PaneItem {
    void *vt;
    short x, y;
    char pad8[0x18];
    VObj *child;
    int unk24;
};
struct ItemExtra {
    char pad0[0xd8];
    int unkD8;
    char padDC[0x114 - 0xdc];
    unsigned char unk114;
    char pad115[0x12c - 0x115];
    unsigned char unk12c;
};
struct Entry {
    int idx;   /* index into the pane list */
    int id;
    int out;
};
struct OptionLayouter {
    void *vt;
    char pad4[0x54];
    int unk58[18];
    unsigned char unkA0;
    int unkA4[5];
    unsigned char unkB8;
    int panes[PANE_COUNT];
    PaneItem *items[ITEM_COUNT];
    VObj *subs[SUB_COUNT];
    ItemExtra *extra;
    int unk214;
    int pad218;
    int unk21c;
    int unk220;
    int unk224[8];
    char pad244[0x290 - 0x244];
    char a290[0x344 - 0x290];
    char a344[0x404 - 0x344];
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
};
extern "C" {
extern char DAT_0030983c[];
extern unsigned char DAT_002f332c;
extern int DAT_0034a318[TABLE_COUNT];
extern int DAT_002c9b38[TABLE_COUNT];
extern char DAT_002f3480[];
extern float DAT_002f2bd4;
extern int DAT_002f2bf0[PANE_COUNT];
extern Entry DAT_002f2fb4[ITEM_COUNT];
extern int DAT_002f32fc[SUB_COUNT];
extern int DAT_003386c8;
extern int DAT_0034a114;
extern int DAT_003415d4;
extern int DAT_0034b350;
void FUN_00102e38(void *);
void FUN_000007f4(void *, void *, void *, int, int);
void FUN_000c777c();
void FUN_00053618();
void FUN_00104118(void *, void *, int);
void FUN_00103540(void *, float);
int FUN_001039d8(void *, int, int);
PaneItem *FUN_001026b8(int, int);
void FUN_000ffc3c(void *, int);
void FUN_0010b8cc(ItemExtra *, int, int);
void *FUN_0008d994(int);
void *FUN_001cd804(int);
void FUN_001037c8(int, int);
void FUN_0022d3f0(OptionLayouter *, int);
void *FUN_00000bcc(unsigned);
int FUN_0015dbc8(void *);
int FUN_0018ff74(void *);
void FUN_002a49d8(void *);
void FUN_0001f21c(int, int);
}

/* Constructs the option screen layout: builds its panes and items, fetches their widgets and sets their initial state. */
extern "C" OptionLayouter *FUN_0022cdd0(OptionLayouter *self, int reload)
{
    FUN_00102e38(self);
    self->vt = DAT_0030983c;
    self->unk58[0] = 0;
    self->unk58[1] = 0;
    self->unk58[2] = 0;
    self->unk58[3] = 0;
    self->unk58[4] = 0;
    self->unk58[5] = 0;
    self->unk58[6] = 0;
    self->unk58[7] = 0;
    self->unk58[8] = 0;
    self->unk58[9] = 0;
    self->unk58[10] = 0;
    self->unk58[11] = 0;
    self->unk58[12] = 0;
    self->unk58[13] = 0;
    self->unk58[14] = 0;
    self->unk58[15] = 0;
    self->unk58[16] = 0;
    self->unk58[17] = 0;
    self->unkB8 = 0;
    self->unk21c = 0;
    self->unk220 = 0;
    FUN_000007f4(self->a290, (void *)FUN_000c777c, (void *)FUN_00053618, 12, 15);
    FUN_000007f4(self->a344, (void *)FUN_000c777c, (void *)FUN_00053618, 12, 15);
    if (DAT_002f332c) {
        for (int i = 0; i < TABLE_COUNT; i++)
            DAT_0034a318[i] = DAT_002c9b38[i];
        DAT_002f332c = 0;
    }
    FUN_00104118(self, DAT_002f3480, 0);
    FUN_00103540(self, DAT_002f2bd4);
    self->unk224[0] = 0;
    self->unk224[1] = 0;
    self->unk224[2] = 0;
    self->unk224[3] = 0;
    self->unk224[4] = 0;
    self->unk224[5] = 0;
    self->unk224[6] = 0;
    self->unk224[7] = 0;
    self->unk414 = 0;
    self->unkA4[0] = -1;
    self->unkA4[1] = -1;
    self->unkA4[2] = -1;
    self->unkA4[3] = -1;
    self->unkA4[4] = -1;
    self->unkA0 = 1;
    int pane_index = 0;
    int *pane_kinds = DAT_002f2bf0;
    int pane_off = 0;
    do {
        VObj *pane;
        *(VObj **)((unsigned int)self + pane_off + 188) = pane = (VObj *)FUN_001039d8(self, *pane_kinds, 0);
        pane->m5(-2);
        pane_index++;
        pane_kinds++;
        pane_off += 4;
    } while (pane_index < PANE_COUNT);
    int item_index = 0;
    Entry *entry = DAT_002f2fb4;
    int item_off = 0;
    do {
        PaneItem *item = FUN_001026b8(self->panes[entry->idx], entry->id);
        *(PaneItem **)((unsigned int)self + item_off + 200) = item;
        if (item != 0) {
            FUN_000ffc3c(item, -256);
            entry->out = (*(PaneItem **)((unsigned long)self + item_off + 200))->unk24;
        }
        item_index++;
        entry++;
        item_off += 4;
    } while (item_index < ITEM_COUNT);
    int sub_index = 0;
    int *sub_item_ids = DAT_002f32fc;
    int sub_off = 0;
    do {
        VObj **slot = (VObj **)((unsigned int)self + sub_off + 480);
        PaneItem *item = self->items[*sub_item_ids];
        *slot = item->child;
        (*slot)->m5(-16);
        sub_index++;
        sub_item_ids++;
        sub_off += 4;
    } while (sub_index < SUB_COUNT);
    self->unk404 = self->items[67]->y;
    self->unk408 = self->items[68]->y;
    self->unk40c = self->items[13]->x;
    self->unk410 = self->items[19]->x;
    ItemExtra *extra_obj = (ItemExtra *)self->items[69]->child;
    self->extra = extra_obj;
    extra_obj->unkD8 = 0;
    extra_obj->unk114 = 1;
    FUN_0010b8cc(self->extra, self->unk224[0], 2);
    self->extra->unk12c = 0;
    ((VObj *)self->extra)->m6(100.0f + DAT_002f2bd4);
    FUN_000ffc3c(self->items[69], -8);
    self->unk214 = 0;
    if (DAT_003386c8 != 0) {
        void *p = FUN_0008d994(DAT_003386c8);
        self->unk214 = (int)p;
        FUN_00103540(p, 100000.0f);
    } else if (DAT_0034a114 != 0) {
        void *p = FUN_001cd804(DAT_0034a114);
        self->unk214 = (int)p;
        FUN_00103540(p, 100000.0f);
        FUN_001037c8(self->unk214, -1);
    }
    FUN_0022d3f0(self, reload);
    void *m = FUN_00000bcc(68);
    if (m != 0)
        self->unk21c = FUN_0015dbc8(m);
    else
        self->unk21c = (int)m;
    if (reload == 0) {
        if (DAT_003415d4 == 0) {
            void *q = FUN_00000bcc(64);
            if (q != 0)
                self->unk220 = FUN_0018ff74(q);
            else
                self->unk220 = (int)q;
            FUN_0001f21c(DAT_003386c8, DAT_003415d4);
        }
        if (DAT_0034b350 == 0) {
            void *q = FUN_00000bcc(0xd58);
            if (q != 0)
                FUN_002a49d8(q);
            FUN_0001f21c(DAT_003386c8, DAT_0034b350);
        }
    }
    ((VObj *)self)->m1();
    return self;
}

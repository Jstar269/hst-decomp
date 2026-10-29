/* HSTMATCH module=EBOOT.BIN start=0x000efe28 end=0x000eff98 symbol=FUN_000efe28 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003078d4;
extern int DAT_002d7380;
extern int DAT_002d72b4;
extern int DAT_002d7318;
extern int DAT_002d7378;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" int FUN_001039d8(void *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void FUN_000f031c(void *);

class Iface {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void hit(int x);
};

struct Entry {
    int slot_index;  /* index into Self::slots */
    int id;
    int out;
};

struct Self {
    void *vt;
    char pad[0x54];
    int slots[3];
    int nodes[8];
    int targets[2];
    int unk8c;
    int unk90;
    int unk94;
};

extern "C" Self *FUN_000efe28(Self *self) {
    FUN_00102e38(self);
    self->vt = &DAT_003078d4;
    FUN_00104118(self, &DAT_002d7380, 0);
    FUN_00103540(self, 3000.0f);
    FUN_001037c8(self, -304);
    /* Create one object per slot kind. */
    {
        int i = 0;
        int *slot_kinds = (int *)&DAT_002d72b4;
        int slot_off = 0;
        do {
            *(int *)((unsigned int)self + slot_off + 0x58) = FUN_001039d8(self, *slot_kinds, 0);
            i++;
            slot_kinds++;
            slot_off += 4;
        } while (i < 3);
    }
    /* Look up the eight nodes from the slot objects. */
    {
        int node_i = 0;
        Entry *entry = (Entry *)&DAT_002d7318;
        int node_off = 0;
        do {
            int *node = (int *)FUN_001026b8(self->slots[entry->slot_index], entry->id);
            *(int *)((unsigned int)self + node_off + 0x64) = (int)node;
            entry->out = node[9];
            node_i++;
            node_off += 4;
            entry++;
        } while (node_i < 8);
    }
    /* Pick the two target handles and notify them. */
    {
        int target_i = 0;
        int *target_nodes = (int *)&DAT_002d7378;
        int target_off = 0;
        do {
            *(int *)((unsigned int)self + target_off + 0x84) = *(int *)(self->nodes[*target_nodes] + 0x20);
            ((Iface *)*(int *)((unsigned int)self + target_off + 0x84))->hit(-16);
            target_i++;
            target_nodes++;
            target_off += 4;
        } while (target_i < 2);
    }
    FUN_000f031c(self);
    self->unk8c = 0;
    self->unk90 = 0;
    self->unk94 = 0x3f800000;  /* 1.0f */
    return self;
}

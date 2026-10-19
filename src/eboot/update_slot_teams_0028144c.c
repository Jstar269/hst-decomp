/* HSTMATCH module=EBOOT.BIN start=0x0028144c end=0x002815c4 symbol=FUN_0028144c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void *DAT_003415a8;
extern unsigned char DAT_003417be;
extern int DAT_0034a77c;
extern int FUN_0024dd40(int, float);

struct TableEntry {
    int pad0;
    float f4;
    char pad[0x38 - 8];
};

struct Sub {
    int count;
    struct TableEntry entries[15];
};

struct Slot {
    char pad0[0x18];
    short id;
    char pad1[0x7f - 0x1a];
    char team;
    char pad2[0x120 - 0x80];
};

struct Obj {
    char pad0[0x5c];
    int m5c;
    char pad1[0x80 - 0x60];
    int m80;
    char pad2[0x510 - 0x84];
    struct Slot slots[3];
};

static inline int GetSlotVal(short id) {
    char *base = (char *)DAT_003415a8;
    struct Sub *sub = (struct Sub *)(base + 0x80);
    struct TableEntry *e;
    if (id >= 0) {
        if (id < 15) {
            e = &sub->entries[id];
        } else {
            e = 0;
        }
    } else {
        e = 0;
    }
    float f = e->f4;
    if (DAT_003417be != 0) {
        f = 0.0f;
    }
    return FUN_0024dd40(DAT_0034a77c, f);
}

void FUN_0028144c(struct Obj *self) {
    int s0 = GetSlotVal(self->slots[0].id);
    int a1 = 0;
    if (self->m5c == 1) {
        if (self->m80 == 3) {
        } else if (self->m80 != 0) {
            a1 = GetSlotVal(self->slots[1].id);
        }
    }
    switch (self->m80) {
    case 3:
        self->slots[0].team = s0;
        self->slots[1].team = 9;
        self->slots[2].team = 9;
        break;
    case 2:
        self->slots[0].team = s0;
        self->slots[1].team = a1;
        self->slots[2].team = a1;
        break;
    case 1:
    case 0:
        self->slots[0].team = s0;
        self->slots[1].team = a1;
        self->slots[2].team = a1;
        break;
    }
}

/* HSTMATCH module=EBOOT.BIN start=0x000562d8 end=0x000564c4 symbol=FUN_000562d8 lang=c++ */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); exact match verified; names and types await human review. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Node {
    void *names;   /* 0x0 name table */
    int count;     /* 0x4 number of names */
};

struct Self {
    Node *list;    /* 0x00 */
    u16 *table;    /* 0x04 output: [0] = count, then one lookup result per name (0xffff = not found) */
    u8 f08;
    u8 lr_mode;    /* 0x09 when set, names with certain prefixes get 'L'/'R' at position 5 */
    u16 idx_a;     /* 0x0a result for the first special name */
    u16 idx_b;     /* 0x0c result for the second special name */
};

struct Tgt {
    char pad[8];
    void *lookup;  /* 0x08 object resolving a name to an index */
};

extern "C" void FUN_000104e0(void *p);
extern "C" void *FUN_000104b0(int size);
extern "C" void FUN_00049194(void);
extern "C" void FUN_000491cc(void);
extern "C" const char *FUN_000301e0(void *tbl, unsigned idx);
extern "C" int FUN_0002fe80(void *obj, const char *name);
extern "C" char *strcpy(char *dst, const char *src);
extern "C" char *FUN_00014d64(char *dst, const char *src);
extern "C" int FUN_00014934(const char *a, const char *b);
extern "C" char DAT_002d0f18[];
extern "C" char DAT_002d0f20[];
extern "C" char DAT_002d0f28[];
extern "C" char DAT_002d0f38[];

/* Build the per-name index table of self->list by looking each name up in tgt. */
extern "C" void FUN_000562d8(Self *self, Tgt *tgt, u8 mode)
{
    if (self->table != 0) {
        FUN_000104e0(self->table);
        self->table = 0;
    }
    if (tgt == 0)
        return;
    if (self->list == 0)
        return;

    FUN_00049194();
    self->lr_mode = mode;

    int count = self->list->count;
    u16 *buf = (u16 *)FUN_000104b0((count + 1) * 2);
    self->table = buf;
    buf[0] = (u16)count;

    for (int i = 0; i < count; i++) {
        char local[256];
        int v;

        strcpy(local, self->list->names != 0 ? FUN_000301e0(self->list->names, i & 0xffff) : 0);

        if (self->lr_mode != 0) {
            if (FUN_00014d64(local, DAT_002d0f18) == local)
                local[5] = 'L';
            else if (FUN_00014d64(local, DAT_002d0f20) == local)
                local[5] = 'R';
        }

        v = tgt->lookup != 0 ? FUN_0002fe80(tgt->lookup, local) : -1;

        if (self->lr_mode != 0 && v < 0) {
            const char *raw = self->list->names != 0 ? FUN_000301e0(self->list->names, i & 0xffff) : 0;
            v = tgt->lookup != 0 ? FUN_0002fe80(tgt->lookup, raw) : -1;
        }

        if (self->lr_mode != 0) {
            if (FUN_00014934(local, DAT_002d0f28) == 0)
                self->idx_a = (u16)v;
            else if (FUN_00014934(local, DAT_002d0f38) == 0)
                self->idx_b = (u16)v;
        }

        self->table[i + 1] = (u16)(v < 0 ? 0xffff : v);
    }

    FUN_000491cc();
}

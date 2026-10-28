/* HSTMATCH module=hstp_trans_main.prx start=0x00056eec end=0x000570d8 symbol=FUN_00056eec lang=c++ */
/* Clone of src/eboot/name_table_build_000562d8.cpp (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); exact match verified; names and types await human review. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Node {
    void *f00;
    int f04;
};

struct Self {
    Node *f00;
    u16 *f04;
    u8 f08;
    u8 f09;
    u16 f0a;
    u16 f0c;
};

struct Tgt {
    char pad[8];
    void *f08;
};

extern "C" void FUN_000104e0(void *p);
extern "C" void *FUN_000104b0(int size);
extern "C" void FUN_00048fb8(void);
extern "C" void FUN_00049020(void);
extern "C" const char *FUN_00030208(void *tbl, unsigned idx);
extern "C" int FUN_0002fea8(void *obj, const char *name);
extern "C" char *strcpy(char *dst, const char *src);
extern "C" char *FUN_00014d64(char *dst, const char *src);
extern "C" int FUN_00014934(const char *a, const char *b);
extern "C" char DAT_00376ba4[];
extern "C" char DAT_00376bac[];
extern "C" char DAT_00376bb4[];
extern "C" char DAT_00376bc4[];

extern "C" void FUN_00056eec(Self *self, Tgt *tgt, u8 mode)
{
    if (self->f04 != 0) {
        FUN_000104e0(self->f04);
        self->f04 = 0;
    }
    if (tgt == 0)
        return;
    if (self->f00 == 0)
        return;

    FUN_00048fb8();
    self->f09 = mode;

    int count = self->f00->f04;
    u16 *buf = (u16 *)FUN_000104b0((count + 1) * 2);
    self->f04 = buf;
    buf[0] = (u16)count;

    for (int i = 0; i < count; i++) {
        char local[256];
        int v;

        strcpy(local, self->f00->f00 != 0 ? FUN_00030208(self->f00->f00, i & 0xffff) : 0);

        if (self->f09 != 0) {
            if (FUN_00014d64(local, DAT_00376ba4) == local)
                local[5] = 'L';
            else if (FUN_00014d64(local, DAT_00376bac) == local)
                local[5] = 'R';
        }

        v = tgt->f08 != 0 ? FUN_0002fea8(tgt->f08, local) : -1;

        if (self->f09 != 0 && v < 0) {
            const char *raw = self->f00->f00 != 0 ? FUN_00030208(self->f00->f00, i & 0xffff) : 0;
            v = tgt->f08 != 0 ? FUN_0002fea8(tgt->f08, raw) : -1;
        }

        if (self->f09 != 0) {
            if (FUN_00014934(local, DAT_00376bb4) == 0)
                self->f0a = (u16)v;
            else if (FUN_00014934(local, DAT_00376bc4) == 0)
                self->f0c = (u16)v;
        }

        self->f04[i + 1] = (u16)(v < 0 ? 0xffff : v);
    }

    FUN_00049020();
}

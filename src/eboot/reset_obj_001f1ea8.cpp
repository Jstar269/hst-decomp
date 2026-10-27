/* HSTMATCH module=EBOOT.BIN start=0x001f1ea8 end=0x001f20d8 symbol=FUN_001f1ea8 lang=c++ data=0x002ee864 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ee864-0x002ee883) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int uint;

struct Obj;

extern "C" {
void FUN_001ef3f8(const char *s, ...);
void FUN_001f4bfc(Obj *self);

extern void *DAT_003313c4;
extern char *DAT_003402a0;
extern void *DAT_003415d4;
extern char DAT_0034179c;
extern char DAT_00341d7d;
extern char DAT_00341d7e;
extern int DAT_0034a678;

void FUN_001b3ea4(void *dat, float f);
void FUN_001f9528(void *self);
void FUN_000114c0(void *dst, int val, int size);
void FUN_0005bbd4(void *dat, float f0, float f1, float f2, float f3, float f4, float f5);
void FUN_0005c7a4(void *dat, int zero, void *dst);
void FUN_001f2f08(void *self);
void *FUN_00219184(void *a, int b);
void FUN_000478d4(int a, int b);
void FUN_001f47a4(void *self);
}

struct Base {
    virtual ~Base();
};

struct ObjInner {
    char pad[144];
    Base *f90; // 144 (0x90)
    char pad2[92];
    float f0[1]; // 240 (0xf0)
};

struct Obj {
    char pad0[68];
    int f44; // 68 (0x44)
    char pad1[12];
    char f54[840]; // 84 (0x54)
    char pad2[372]; // up to 1296 (0x510)
    Base *f510; // 1296 (0x510)
    u8 f514; // 1300 (0x514)
    u8 pad_byte; // 1301
    u8 f516; // 1302 (0x516)
    char pad_b2[5]; // up to 1308 (0x51c)
    int f51c; // 1308 (0x51c)
    char pad3[68]; // up to 1380
    void *f564; // 1380 (0x564)
    char pad4[28]; // up to 1412
    ObjInner *f584; // 1412 (0x584)
    char pad5[8]; // up to 1424
    int f590; // 1424 (0x590)
    char pad_high[31712]; // up to 33140 (0x8174)
    int f8174; // 33140 (0x8174)
};

extern "C" void FUN_001f1ea8(Obj *self) {
    if (self->f44 == 0) {
        self->f8174 = 0;
        FUN_001b3ea4(&DAT_0034179c, 0.5f);
    }

    if (++self->f8174 == 20) {
        FUN_001ef3f8("-------- REMATCH ------------\n");

        int mode = self->f51c + 1;
        self->f51c = mode;
        if (mode > 0x60000000) {
            self->f51c = mode >> 2;
        }

        FUN_001f9528(self);
        FUN_000114c0(self->f54, 0, 840);

        switch (DAT_0034a678) {
        case 42:
            DAT_00341d7d = (char)-1;
            DAT_00341d7e = (char)-1;
            break;
        }
        self->f516 = 1;

        self->f514 = 0;

        ObjInner *inner = self->f584;
        FUN_0005bbd4(DAT_003313c4, 0.0f, 0.0f, 480.0f, 272.0f, 240.0f, 136.0f);
        FUN_0005c7a4(DAT_003313c4, 0, (char *)inner + 240);

        if (DAT_003402a0 != 0) {
            DAT_003402a0[5140] = 1;
            DAT_003402a0[5141] = 1;
        }

        self->f590 = 0;
        FUN_001f2f08(self);

        if (self->f510 != 0) {
            delete self->f510;
            self->f510 = 0;
        }

        if (DAT_003415d4 != 0) {
            delete (Base *)DAT_003415d4;
            DAT_003415d4 = 0;
        }

        inner = self->f584;
        Base *f90 = inner->f90;
        if (f90 != 0) {
            delete f90;
            inner->f90 = 0;
        }

        void *f564 = self->f564;
        if (f564 != 0) {
            FUN_00219184(f564, 1);
            self->f564 = 0;
        }

        FUN_000478d4(1, 0);
    }
    FUN_001f4bfc(self);
    FUN_001f47a4(self);
}

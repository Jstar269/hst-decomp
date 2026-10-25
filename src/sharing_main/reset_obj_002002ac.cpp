/* HSTMATCH module=hstp_trans_main.prx start=0x002002ac end=0x002004dc symbol=FUN_002002ac lang=c++ */
/* Clone of src/eboot/reset_obj_001f1ea8.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int uint;

struct Obj;

extern "C" {
void FUN_001fbc18(const char *s, ...);
void FUN_002031c4(Obj *self);

extern void *DAT_003da704;
extern char *DAT_003e95e0;
extern void *DAT_003ea914;
extern char DAT_003eaad8;
extern char DAT_003eb0b5;
extern char DAT_003eb0b6;
extern int DAT_003f39a8;
extern const char DAT_0039680c;

void FUN_001c2130(void *dat, float f);
void FUN_00207be0(void *self);
void FUN_000114c0(void *dst, int val, int size);
void FUN_0005c85c(void *dat, float f0, float f1, float f2, float f3, float f4, float f5);
void FUN_0005d42c(void *dat, int zero, void *dst);
void FUN_0020139c(void *self);
void *FUN_0022869c(void *a, int b);
void FUN_00047d58(int a, int b);
void FUN_00202d34(void *self);
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

extern "C" void FUN_002002ac(Obj *self) {
    if (self->f44 == 0) {
        self->f8174 = 0;
        FUN_001c2130(&DAT_003eaad8, 0.5f);
    }

    if (++self->f8174 == 20) {
        FUN_001fbc18(&DAT_0039680c);

        int mode = self->f51c + 1;
        self->f51c = mode;
        if (mode > 0x60000000) {
            self->f51c = mode >> 2;
        }

        FUN_00207be0(self);
        FUN_000114c0(self->f54, 0, 840);

        switch (DAT_003f39a8) {
        case 42:
            DAT_003eb0b5 = (char)-1;
            DAT_003eb0b6 = (char)-1;
            break;
        }
        self->f516 = 1;

        self->f514 = 0;

        ObjInner *inner = self->f584;
        FUN_0005c85c(DAT_003da704, 0.0f, 0.0f, 480.0f, 272.0f, 240.0f, 136.0f);
        FUN_0005d42c(DAT_003da704, 0, (char *)inner + 240);

        if (DAT_003e95e0 != 0) {
            DAT_003e95e0[5140] = 1;
            DAT_003e95e0[5141] = 1;
        }

        self->f590 = 0;
        FUN_0020139c(self);

        if (self->f510 != 0) {
            delete self->f510;
            self->f510 = 0;
        }

        if (DAT_003ea914 != 0) {
            delete (Base *)DAT_003ea914;
            DAT_003ea914 = 0;
        }

        inner = self->f584;
        Base *f90 = inner->f90;
        if (f90 != 0) {
            delete f90;
            inner->f90 = 0;
        }

        void *f564 = self->f564;
        if (f564 != 0) {
            FUN_0022869c(f564, 1);
            self->f564 = 0;
        }

        FUN_00047d58(1, 0);
    }
    FUN_002031c4(self);
    FUN_00202d34(self);
}

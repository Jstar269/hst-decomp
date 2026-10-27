/* HSTMATCH module=hstp_trans_main.prx start=0x000a3b70 end=0x000a3d98 symbol=FUN_000a3b70 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/info_setup_000a14e0.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
} __attribute__((aligned(16)));
struct Mat4 {
    Vec4 r0, r1, r2, r3;
};

struct Info {
    char pad0[0x10];
    Vec4 pos;
    char pad20[0x10];
    short id1;
    unsigned char c1;
    char pad33;
    float speed1;
    char pad38[4];
    short id2;
    unsigned char c2;
    char pad3f;
    float speed2;
    char pad44[4];
    int f48;
    int kind;
    unsigned char f50;
    unsigned char f51;
    unsigned char f52;
    unsigned char f53;
    unsigned char f54;
    signed char slot;
    char pad56[2];
    int f58;
};

struct Self {
    char pad0[0x148];
    int id;
    char pad14c[0x1c];
    int f168;
    char pad16c[0x484 - 0x16c];
    int f484;
    char pad488[0x550 - 0x488];
    Mat4 mat;
    Vec4 prev;
};

struct Mgr {
    char pad[0x9c];
    void *table;
    char pada0[8];
    void *slots;
};
struct Flags {
    char pad[0x78];
    unsigned char busy;
};
struct Game {
    char pad[0x80];
    Flags *flags;
};
struct Obj;
struct ObjList {
    Obj **data;
    unsigned size;
};
struct World {
    char pad[0x138c];
    ObjList objs;
};

extern Mgr *DAT_003e19f0;
extern Game *DAT_003e95c4;
extern World *DAT_003e95e0;

extern "C" {
Info *FUN_001230bc(void *table, int id);
Mat4 FUN_0001cdb0(Info *info);
void FUN_000b1470(Self *self, Info *info);
void FUN_000b5760(Self *self, int id1, unsigned char c1, float speed1, int id2, unsigned char c2, float speed2,
                  unsigned char extra, int flag1, int flag2, float add);
void FUN_001c31b4(void *slots, int id, int kind, unsigned char c);
void FUN_000b4e20(Self *self, unsigned char c, int f);
void FUN_00236614(Obj *obj, Vec4 p, int f);
}

extern "C" void FUN_000a3b70(Self *self)
{
    self->prev = self->mat.r3;
    Info *info = FUN_001230bc(DAT_003e19f0->table, self->id);
    if (info != 0) {
        self->f168 = info->f48;
        self->mat = FUN_0001cdb0(info);
        self->mat.r3 = info->pos;
        FUN_000b1470(self, info);
        bool extra = info->f51 != 0 || info->f52 != 0;
        FUN_000b5760(self, info->id1, info->c1, info->speed1, info->id2, info->c2, info->speed2, extra, 0, 0, 0.0f);
        if (info->kind != 0xd0)
            FUN_001c31b4(DAT_003e19f0->slots, self->id, info->kind, info->f50);
        if (info->f54 != 0) {
            if (DAT_003e95c4->flags->busy == 0) {
                self->f484 = info->f58;
                FUN_000b4e20(self, info->f53, 0);
            }
        }
        int slot = info->slot;
        if (slot >= 0) {
            ObjList &l = DAT_003e95e0->objs;
            if ((unsigned)slot < l.size) {
                Obj *o = l.data[slot];
                if (o != 0)
                    FUN_00236614(o, Vec4(0.0f, 0.0f, 0.0f, 0.0f), 1);
            }
        }
    }
}

/* HSTMATCH module=EBOOT.BIN start=0x00287c60 end=0x00287de4 symbol=FUN_00287c60 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Effect-spawn helper: with n < 1 it builds the 0x70-byte effect object (base ctor 0xce8e8, vptr 0x307564 restored to 0x30753c, matrix copy 0x58694) at the position of the mode 2/3/4 owner and submits it through 0x67790; otherwise it queues a 24-byte record through 0x289544 (circular list with the sentinel at +0x68, as in 0x288208). Same Fx layout as 0x28a3f4. The float is declared last (any position after the first int gives the retail prologue; first gives mov.s before the int moves). */
struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { Vec4 r0, r1, r2, r3; };

struct Fx {
  void *vptr;
  int unk4;
  char pad8[8];
  Mat4 m;
  int unk50;
  float unk54;
  float unk58;
  int unk5c;
  unsigned char unk60;
  char pad61[0x70 - 0x61];
};

struct Game { char pad[0x164]; void *effects; /* 0x164 list the effect is submitted to */ };

struct Node {
    Node *next;
    Node *prev;
};

/* 24-byte request record queued when the delay is positive. */
struct Req {
    int type;
    int delay;
    int mode;
    int a;
    int b;
    float f;
};

struct Obj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual int m11();
    char pad[0x60];
    int count;
    Node sentinel;
};

enum { REQ_TYPE_4F = 0x4f }; /* request kind, named by its hex value */

extern "C" {
extern char DAT_0030753c;
extern char DAT_00307564;
extern Mat4 DAT_002bc410;
extern Game *DAT_0034a114;
Fx *FUN_000ce8e8(Fx *);
void FUN_00058694(Mat4 *, Mat4 *);
void FUN_00067790(void *, Fx *);
void FUN_00289544(void *out, void *vec, void *list, void *key);
int *FUN_00288a84(void *);
int *FUN_00288af0(void *);
}

/* With delay below 1 spawn the effect at the owner object's position; otherwise queue a request. */
extern "C" void FUN_00287c60(Obj *self, int a1, int a2, int delay, float dt)
{
    if (delay < 1) {
        Fx fx;
        FUN_000ce8e8(&fx);
        fx.vptr = &DAT_00307564;
        FUN_00058694(&fx.m, &DAT_002bc410);
        fx.unk54 = 1.0f;
        fx.unk50 = 0;
        fx.unk5c = 0;
        fx.unk60 = 0;
        fx.unk58 = 3000.0f;
        char *anchor = 0;
        switch (self->m11()) {
        case 2:
        case 3:
            anchor = *(char **)((char *)FUN_00288a84(self) + 0x58);
            break;
        case 4:
            anchor = *(char **)((char *)FUN_00288af0(self) + 0x70);
            break;
        }
        if (anchor != 0) {
            fx.unk50 = a1;
            fx.m.r3.x = *(float *)(anchor + 0x60);
            fx.m.r3.y = *(float *)(anchor + 0x64);
            fx.m.r3.z = *(float *)(anchor + 0x68);
            fx.m.r3.w = *(float *)(anchor + 0x6c);
            fx.unk54 = dt;
            fx.unk58 = 3500.0f;
            FUN_00067790(DAT_0034a114->effects, &fx);
        }
        fx.vptr = &DAT_0030753c;
    } else {
        Req req;
        Node *out;
        req.type = REQ_TYPE_4F;
        req.mode = 3;
        Node *sentinel = &self->sentinel;
        req.delay = delay;
        req.a = a1;
        req.b = a2;
        req.f = dt;
        FUN_00289544(&out, &self->count, &sentinel, &req);
    }
}

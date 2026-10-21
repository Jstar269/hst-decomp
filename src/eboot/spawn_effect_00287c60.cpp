/* HSTMATCH module=EBOOT.BIN start=0x00287c60 end=0x00287de4 symbol=FUN_00287c60 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Effect-spawn helper: with n < 1 it builds the 0x70-byte effect object (base ctor 0xce8e8, vptr 0x307564 restored to 0x30753c, matrix copy 0x58694) at the position of the mode 2/3/4 owner and submits it through 0x67790; otherwise it queues a 24-byte record through 0x289544 (circular list with the sentinel at +0x68, as in 0x288208). Same Fx layout as 0x28a3f4. The float is declared last (any position after the first int gives the retail prologue; first gives mov.s before the int moves). */
struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { Vec4 r0, r1, r2, r3; };

struct Fx {
  void *vptr;
  int f4;
  char pad8[8];
  Mat4 m;
  int f50;
  float f54;
  float f58;
  int f5c;
  unsigned char f60;
  char pad61[0x70 - 0x61];
};

struct Game { char pad[0x164]; void *f164; };

struct Node {
    Node *next;
    Node *prev;
};

struct Key {
    int type;
    int n;
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

extern "C" void FUN_00287c60(Obj *self, int a1, int a2, int n, float dt)
{
    if (n < 1) {
        Fx fx;
        FUN_000ce8e8(&fx);
        fx.vptr = &DAT_00307564;
        FUN_00058694(&fx.m, &DAT_002bc410);
        fx.f54 = 1.0f;
        fx.f50 = 0;
        fx.f5c = 0;
        fx.f60 = 0;
        fx.f58 = 3000.0f;
        char *h = 0;
        switch (self->m11()) {
        case 2:
        case 3:
            h = *(char **)((char *)FUN_00288a84(self) + 0x58);
            break;
        case 4:
            h = *(char **)((char *)FUN_00288af0(self) + 0x70);
            break;
        }
        if (h != 0) {
            fx.f50 = a1;
            fx.m.r3.x = *(float *)(h + 0x60);
            fx.m.r3.y = *(float *)(h + 0x64);
            fx.m.r3.z = *(float *)(h + 0x68);
            fx.m.r3.w = *(float *)(h + 0x6c);
            fx.f54 = dt;
            fx.f58 = 3500.0f;
            FUN_00067790(DAT_0034a114->f164, &fx);
        }
        fx.vptr = &DAT_0030753c;
    } else {
        Key k;
        Node *out;
        k.type = 0x4f;
        k.mode = 3;
        Node *sent = &self->sentinel;
        k.n = n;
        k.a = a1;
        k.b = a2;
        k.f = dt;
        FUN_00289544(&out, &self->count, &sent, &k);
    }
}

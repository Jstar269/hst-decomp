/* HSTMATCH module=hstp_trans_main.prx start=0x000bb408 end=0x000bb540 symbol=FUN_000bb408 lang=c++ */
/* Clone of src/eboot/FUN_000b8118.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly, byte-exact. The last word was the record-element
   address: `((char *)self + 136) + off` (base plus constant first, integer offset added last) gives
   retail`s `addu v0,v0,s0`; both `24 * k + (int)self` and `(char *)self + off + 136` canonicalise to
   `addu v0,s0,v0`. Names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char u8;

struct M4 { float m[16]; };
struct Big {
  char pad0[512];
  float f200;
  char pad1[16];
  float f214;
  char pad2[704 - 536];
};

struct Self {
  char pad0[60];
  u8 b3c;
  u8 b3d;
  char pad1[2];
  int f40;
  char pad2[12];
  int f50;
  int f54;
  int f58;
  float f5c;
  int f60;
  int f64;
  char pad3[8];
  int f70;
  float f74;
  float f78;
};

extern "C" {
extern void *DAT_003e19f0;
extern u8 DAT_003e19f8;
extern void *DAT_003e1e04;
extern void *DAT_003e1e84;
extern void *DAT_003da704;
extern void FUN_000bb540(struct M4 *m, struct Self *self);
extern void FUN_0005c658(struct Big *b, void *p);
extern float FUN_0000c018(float f);
extern float FUN_0005cfa0(struct Big *b);
extern void FUN_0005c688(struct Big *b, int n);

}

extern "C" void FUN_000bb408(struct Self *self)
{
  self->b3c = 0;
  self->b3d = 0;
  self->f40 = 0;
  self->f50 = 0;
  self->f54 = 0;
  self->f58 = 0;
  self->f5c = 1.0f;
  self->f60 = 0;
  self->f70 = 0;
  self->f74 = 0.0f;
  void *g = DAT_003e19f0;
  if (g != 0) {
    int idx = (DAT_003e19f8 != 0 && DAT_003e1e04 != 0)
                  ? *(int *)((char *)DAT_003e1e04 + 0x198) : 0;
    void **arr = (void **)((char *)g + 112);
    int j = *(int *)((char *)DAT_003e1e84 + 80);
    int a = *(int *)((char *)arr[idx] + 0x144);
    int b = *(int *)((char *)arr[j] + 0x144);
    self->f74 = (a != b) ? 1.0f : 0.0f;
  }
  struct Big big;
  struct M4 m;
  FUN_000bb540(&m, self);
  FUN_0005c658(&big, DAT_003da704);
  unsigned int k = (unsigned int)self->f64;
  int off = (int)k * 24;
  float f1 = *(float *)((char *)((char *)self + 136) + off);
  big.f200 = f1;
  big.f214 = FUN_0000c018(0.008726646f * f1);
  self->f78 = 0.008726646f * FUN_0005cfa0(&big);
  FUN_0005c688(&big, -1);
}

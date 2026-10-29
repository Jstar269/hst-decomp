/* HSTMATCH module=EBOOT.BIN start=0x000ce754 end=0x000ce820 symbol=FUN_000ce754 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float x, y, z, w; };
struct Mat4 { Vec4 r0, r1, r2, r3; };

/* Transient effect request: vtable, an orientation matrix and a few scalars, handed to the submit call. */
struct Fx {
  void *vptr;
  int unk04;
  char pad8[8];
  Mat4 m;
  int unk50;
  float unk54;
  float unk58;
  float unk5c;
  unsigned char unk60;
  char pad61[0x70 - 0x61];
};

extern "C" {
extern char DAT_0030753c;
extern char DAT_00307564;
Fx *FUN_000ce8e8(Fx *);
void FUN_00058694(Mat4 *, Mat4 *);
void FUN_00067790(void *, Fx *);
}

/* Builds a request on the stack from the arguments and submits it to the owner p1; the vtable is switched back to the base one afterwards. */
extern "C" void FUN_000ce754(void *owner, Mat4 *src, int id, float c, float d, int flag, float e)
{
  Fx fx;

  FUN_000ce8e8(&fx);
  fx.vptr = &DAT_00307564;
  FUN_00058694(&fx.m, src);
  fx.unk54 = 1.0f;
  fx.unk58 = 3000.0f;
  fx.unk5c = 0.0f;
  fx.unk50 = id;
  fx.unk60 = (unsigned char)flag;
  fx.unk5c = e;
  fx.unk54 = d;
  fx.unk58 = c;
  FUN_00067790(owner, &fx);
  fx.vptr = &DAT_0030753c;
}

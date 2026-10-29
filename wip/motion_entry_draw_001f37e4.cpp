/* HSTMATCH module=EBOOT.BIN start=0x001f37e4 end=0x001f3a30 symbol=FUN_001f37e4 lang=c++ */
struct Inner {
  char pad0[0x1b4];
  int mode;
};

struct Mode {
  char pad0[0xf0];
  int value;
};

struct Obj {
  char pad0[0x50];
  Inner *inner;
  char pad1[4];
  Mode *mode;
  char pad2[8];
  int handle;
};

struct ObjVt {
  virtual void fn0();
  virtual void fn1();
};

struct Rec {
  char pad0[0xf0];
  short f0;
  unsigned char f2;
};

struct Entry {
  int id;
  float scale;
  char pad0[8];
  unsigned char flags;
};

extern char DAT_002c8e44[];
extern char DAT_002ee8c0[];
extern int DAT_00310fc8;
extern "C" void FUN_00057f30(int, int);
extern "C" void FUN_000931ec(Obj *, int, short *, int);
extern "C" void FUN_00092078(Obj *, int, int, int, float);
extern "C" void FUN_00057b58(int, int, int, float);
extern "C" void FUN_00058ddc(int, int, int);
extern "C" void FUN_00058ec4(int, int, float);
extern "C" void FUN_00058f38(int, int, float);
extern "C" void FUN_0005f110(int, float);
extern "C" void FUN_00059084(int, int);
extern "C" void FUN_001ef3f8(...);

extern "C" void FUN_001f37e4(int base, Obj *obj, int a2, int a3, int idx, int flag)
{
  if (obj == 0) {
    return;
  }
  bool b = false;
  int off = idx * 0x14;
  int handle = obj->handle;
  Entry *e = (Entry *)(DAT_002c8e44 + off);
  int c = e->flags;
  if (obj->inner->mode == 6) {
    c = 0;
  }
  int mode = obj->mode == 0 ? -1 : obj->mode->value;
  if (mode != 6 || idx != 6) {
    if (c != 0) {
      FUN_000931ec(obj, 1, &((Rec *)a2)->f0, ((Rec *)a2)->f2);
    } else {
      FUN_00057f30(handle, 0);
    }
    if (e->id == 1) {
      b = true;
    }
    float f = e->scale;
    if (flag != 0) {
      DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
      f = f + (float)(((unsigned int)DAT_00310fc8 >> 16) & 0x7fff) * 3.0517578e-05f * 5.0f;
    }
    FUN_00092078(obj, idx, b, 0, f);
    if (handle != 0) {
      FUN_00057b58(handle, 0, idx, 0.0f);
      FUN_00058ddc(handle, b, -1);
      FUN_00058ec4(handle, -1, 1.0f);
      *(float *)(handle + 0xc4) = 1.0f;
      FUN_00058f38(handle, -1, f);
      FUN_0005f110(handle, f);
      FUN_00059084(handle, -1);
      *(float *)(handle + 0xd0) = *(float *)(handle + 0xc4);
    }
    ((ObjVt *)obj)->fn1();
  }
  *(unsigned char *)(a3 + base + 0x3e4) = 0;
  FUN_001ef3f8(DAT_002ee8c0, idx);
}
// NEAR MISS 2026-10-22: 144/147 words, 143 differ (ours | retail); whole body shifted by the
// saved-register map: retail uses s0=table, s1=handle, s2=bool, s3=idx, s4=obj, s5=base,
// s6=a3, s7=flag (64-byte frame); ours pushes b and the table pointer into one reg (48-byte).
// Body structure otherwise agrees: guard, table strip (idx*0x14 at 0x2c8e44), mode==6 tests,
// FUN_00057f30 / FUN_000931ec split, xorshift-style DAT_00310fc8 LCG with ext + unsigned->float,
// FUN_00092078(obj,idx,b,0,f), the seven handle setters, the vtable slot-1 call and the
// DAT_002ee8c0 log line. Ruled out: bool via `== 1` (sltiu/xori instead of li 1/bnel),
// `if(id!=1)b=false` form, int-masked rand (gives sll/srl/sra instead of ext).
// Next thing to try: make the bool live across the FUN_00092078 call in its own saved register
// by declaring it before the table pointer.
// sy4 NEAR MISS (147/147 words, 87 differ; older wip 143 differ, 144/147 words). Register map s0..s7 now matches retail and the whole body is the right length; moved: `bool b = false;`
// declared FIRST (before the table pointer, so it gets s2) and set with `if (e->id == 1) b = true;`, `int c = e->flags` (no andi), `if (c != 0) FUN_000931ec(..) else FUN_00057f30(..)`
// (retail's `beqzl c,ELSE` falls into the 931ec call). Still different: retail copies a2 into v1 at entry (`move v1,a2`) and keeps c in a2 with the table-offset temps in a0/a1,
// ours leaves a2 and uses v0/v1/a0 for the same temps; this shifts the first ~35 words after the guard, the rest follows. Ruled out: Rec* parameter, Rec* local, c via ternary, base-struct for the final store.
// improved by lane sy4 (unreviewed): 143 -> 87 differing words

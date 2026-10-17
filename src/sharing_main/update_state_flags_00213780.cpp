/* HSTMATCH module=hstp_trans_main.prx start=0x00213780 end=0x002138e4 symbol=FUN_00213780 lang=c++ */
/* Clone of src/eboot/update_state_flags_00204f18.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: retail has two call sites of FUN_002134f0 (one per arm of the flag test), so both arms spell the call;
   the two Info bytes are read into locals before the test. */
typedef unsigned char u8;

struct Obj0 { virtual void d0(); virtual void v1(); };
struct Info { u8 pad0[12]; u8 b0c; u8 b0d; u8 pad1[0x24 - 14]; u8 b24; };
struct Self {
  Obj0 *obj;
  char pad0[0x54 - 4];
  int id;
  char pad1[0x70 - 0x58];
  int f70;
  u8 flag;
  u8 f75;
  u8 f76;
  u8 f77;
  u8 f78;
};

extern "C" Info *FUN_0019fc84(int);
extern "C" void FUN_002134f0(Obj0 *, u8 *, u8 *, u8 *, int *, u8, u8, u8, u8, u8, int);
extern "C" void FUN_002138e4(Self *, int);
extern "C" void FUN_00213b20(Self *, int, u8);
extern "C" void FUN_00213bdc(Self *, int, u8);
extern "C" void FUN_000942c8(Obj0 *, u8);
extern "C" void FUN_002143bc(Self *, int);
extern "C" void FUN_002143b4(Self *, int);

extern "C" void FUN_00213780(Self *self)
{
  u8 x1 = 0;
  u8 x2 = 0;
  u8 x3 = 0;
  Info *info = FUN_0019fc84(self->id);
  u8 hi = info->b0d;
  u8 lo = info->b0c;
  u8 w = self->f78;
  if (self->flag == 0) {
    FUN_002134f0(self->obj, &x2, &x1, &x3, &self->id, self->f76, self->f77, w, hi, lo, 0);
  } else {
    FUN_002134f0(self->obj, &x2, &x1, &x3, &self->id, self->f76, self->f77, w, hi, lo, 0);
    x2 = 1;
    x1 = 1;
    x3 = 1;
  }
  if (x2 != 0) {
    FUN_002138e4(self, self->id);
  }
  if (x1 != 0) {
    FUN_00213b20(self, 1, w);
  }
  if (x3 != 0) {
    FUN_00213bdc(self, 1, w);
  }
  self->f70 = info->b24;
  FUN_000942c8(self->obj, self->f75);
  self->obj->v1();
  FUN_002143bc(self, 3);
  FUN_002143b4(self, 1);
}

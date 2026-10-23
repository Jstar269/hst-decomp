/* HSTMATCH module=EBOOT.BIN start=0x001c5fc4 end=0x001c6180 symbol=FUN_001c5fc4 lang=c++ */
/* IN PROGRESS 103/111 words. Structure read off the disassembly: FUN_0001ebd4(), a 16-entry iterate-and-
   destroy loop over f40/f44 (`Item **begin`, `int count`, end = begin + count recomputed every pass), the
   per-item `if (obj->v34() == 2 || obj->v34() == 3) { FUN_00286f2c(obj); obj->v0c(); }` short-circuit,
   FUN_0001efac(), the `if (fc8 == 1)` switch on the byte DAT_00341d36 (cases 0/1/2 -> mode 2/1/0 and
   DAT_0034a0fc = 1/2/3, default mode 3), FUN_00292e40(DAT_0034a820, mode), the `fe4 != 0x2a` guard around
   FUN_002930c8(65534.0f, DAT_0034a820, 1), FUN_001b3ea4(0.2f, 0x34179c) and the `fc8 > 6` tail
   (FUN_00234158(&DAT_0034a678, fe4); *(char *)(f15c + 0x65) = 0). Open: retail materialises the
   iterator's `!=` as `xor / sltiu / xori` (an inlined `bool operator!=`) and does NOT fold it to
   `count != 0`; every spelling here folds it, and with the inline iterator the self/begin s-registers
   swap (retail s1 = self, s0 = begin). 8 words short. */
extern "C" void FUN_0001ebd4();
extern "C" void FUN_0001efac();
extern "C" void FUN_00286f2c(void *);
extern "C" void FUN_00292e40(void *, int);
extern "C" void FUN_002930c8(float, void *, int);
extern "C" void FUN_001b3ea4(float, void *);
extern "C" void FUN_00234158(void *, int);

extern "C" unsigned char DAT_00341d36;
extern "C" int DAT_0034a0fc;
extern "C" char DAT_0034a820[];
extern "C" int DAT_0034a678;

struct Item {
  virtual void v08();
  virtual void v0c();
  virtual void v10();
  virtual void v14();
  virtual void v18();
  virtual void v1c();
  virtual void v20();
  virtual void v24();
  virtual void v28();
  virtual void v2c();
  virtual void v30();
  virtual int v34();
};

struct Iter {
  Item **mIt;
  Iter(Item **p) : mIt(p) {}
  bool operator!=(const Iter &o) const { return mIt != o.mIt; }
  Item *operator*() const { return *mIt; }
  Iter &operator++() { mIt++; return *this; }
};

struct Scene {
  char pad0[0x40];
  Item **f40;
  int f44;
  char pad1[0xc8 - 0x48];
  int fc8;
  char pad2[0xe4 - 0xcc];
  int fe4;
  char pad3[0x15c - 0xe8];
  char *f15c;
};

extern "C" void FUN_001c5fc4(Scene *self)
{
  Item *obj;
  int mode;

  FUN_0001ebd4();
  {
    Iter it(self->f40);
    Iter end(self->f40 + self->f44);
    if (it != end) {
      do {
        obj = *it;
        if (obj->v34() == 2 || obj->v34() == 3) {
          FUN_00286f2c(obj);
          obj->v0c();
        }
        ++it;
      } while (it != Iter(self->f40 + self->f44));
    }
  }
  FUN_0001efac();

  if (self->fc8 == 1) {
    mode = 3;
    if (DAT_00341d36 == 0) {
      mode = 2;
      DAT_0034a0fc = 1;
    }
    else if (DAT_00341d36 == 1) {
      mode = 1;
      DAT_0034a0fc = 2;
    }
    else if (DAT_00341d36 == 2) {
      mode = 0;
      DAT_0034a0fc = 3;
    }
    FUN_00292e40(DAT_0034a820,mode);
    if (self->fe4 != 0x2a)
      FUN_002930c8(65534.0f,DAT_0034a820,1);
    FUN_001b3ea4(0.2f,(void *)0x34179c);
  }

  if (self->fc8 > 6) {
    FUN_00234158(&DAT_0034a678,self->fe4);
    *(char *)(self->f15c + 0x65) = 0;
  }
}
// near miss from lane fm7 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x0028be78 end=0x0028c0cc symbol=FUN_0028be78 lang=c++ */
struct ObjVt {
  virtual void fn0();
  virtual void fn1();
  virtual void fn2();
  virtual void fn3();
  virtual void fn4();
  virtual void fn5();
  virtual void fn6();
  virtual void fn7();
  virtual void fn8();
};

struct Sub {
  char pad0[0xf4];
  int *p;
};

struct Obj {
  char pad0[0x30];
  int f30;
  int f34;
  char pad1[0x5b - 0x38];
  unsigned char f5b;
  char pad2[0x70 - 0x5c];
  Sub *f70;
  char pad3[0x1fc - 0x74];
  void *f1fc;
};

struct Rec {
  int f0;
  int f4;
  int f8;
  int fc;
  int f10;
  char pad[0x2e - 0x14];
  char name[0x20];
  char pad2[0x60 - 0x4e];
};

struct Mgr {
  char pad0[0xcc];
  int fcc;
  int fd0;
  char pad1[0x17c - 0xd4];
  int f17c;
};

extern Mgr *DAT_0034a114;
extern char DAT_0034179c[];
extern char DAT_0030ee78[];

extern "C" int FUN_00014a40(char *);
extern "C" void FUN_001b28f0(void *, char *);
extern "C" int FUN_0022cb40(int, int, int, int);
extern "C" void FUN_00055240(int *, int, void *);
extern "C" void FUN_0028c204(int, Rec *, float *, float);
extern "C" int FUN_0022cb04(int, int, int, int, int);
extern "C" void FUN_001c6bec(Mgr *, int, int, int, int, int);
extern "C" void FUN_0028c0cc(char *);
extern "C" void FUN_001c7e80(Mgr *, Obj *, int);

extern "C" int FUN_0028be78(Rec **range, Obj *obj)
{
  Mgr *m = DAT_0034a114;
  Rec *first = range[0];
  int a = m->fcc + 1;
  int b = m->fd0 + 1;
  Rec *last = first + (int)range[1];
  if (first == last) {
    return 0;
  }
  for (; first != last; first++) {
    if (first->f0 != a) {
      continue;
    }
    if (first->f4 != b) {
      continue;
    }
    if (first->fc != obj->f30) {
      continue;
    }
    if (first->f8 != obj->f34) {
      continue;
    }
    ((ObjVt *)obj)->fn8();
    if (FUN_00014a40(first->name) != 0) {
      FUN_001b28f0(DAT_0034179c, first->name);
    }
    float f = 0.0f;
    if (obj != 0 && obj->f70 != 0 && obj->f70->p != 0) {
      f = *(float *)((char *)obj->f70->p + 8);
    }
    Mgr *m2 = DAT_0034a114;
    int rem = first->fc % 100;
    int r = FUN_0022cb40(m2->fcc, m2->fd0, rem, first->f8);
    int flag = r != 0;
    if (!flag) {
      if (first->f10 == 1) {
        flag = obj->f5b == 0;
      }
    }
    if (flag) {
      int buf[20];
      FUN_00055240(buf, (int)obj->f70, obj->f1fc);
      float *src = (float *)((char *)buf + 0x30);
      float *dst = (float *)((char *)buf + 0x40);
      dst[0] = src[0];
      dst[1] = src[1];
      dst[2] = src[2];
      dst[3] = src[3];
      FUN_0028c204(DAT_0034a114->f17c, first, dst, f);
      FUN_0022cb04(DAT_0034a114->fcc, DAT_0034a114->fd0, first->fc % 100, first->f8, 1);
      obj->f5b = 1;
    } else {
      int t = (int)(6.0f + f);
      FUN_001c6bec(DAT_0034a114, -1, -1, -1, t, 0);
      FUN_0028c0cc(DAT_0030ee78);
    }
    FUN_001c7e80(DAT_0034a114, obj, 1);
    return 1;
  }
  return 0;
}
// NEAR MISS 2026-10-22: 145/149 words, 125 differ (ours | retail). Structure is right (guard on the
// 96-byte record range, 4 key compares against manager fields fcc+1/fd0+1, virtual slot 8 on the
// arg object, FUN_00014a40/FUN_001b28f0 name check, float from obj->f70->p+8, %100 + FUN_0022cb40
// gate with the f5b flag, stack temp for FUN_00055240, 16-byte float copy, FUN_0028c204/0022cb04
// pair and FUN_001c6ebec/FUN_0028c0cc else branch, final FUN_001c7e80 and `return 1`).
// Ruled out / still off: MWCC keeps the manager pointer in v1 and our prologue reorders the
// range[1] load; the loop-tail compare is `xor/sltiu/xori` on `first==last` in both, but our
// record pointer IV and the two `Rec*` locals colour differently; the stack frame is 80 bytes
// instead of retail's 128 (buffer layout sp+0x20..0x6c not reproduced exactly).
// near miss from lane fm4 (unreviewed)

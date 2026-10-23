/* HSTMATCH module=EBOOT.BIN start=0x001ca238 end=0x001ca480 symbol=FUN_001ca238 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Notes: the virtual slots are placeholders (av5/av6/av7 hit vtable bytes 0x1c/0x20/0x24, rv29/rv30/rv39 hit
   0x7c/0x80/0xa4); MWCC puts declared slot i at byte offset 4*(i+2) here, so two leading entries are implied.
   Matching idiom: the four Vec4 locals have to be declared in this order for retail's stack slots. */

struct Vec4 {
  float x, y, z, w;
};

struct Item {
  int type;
  int idx;
  char pad00[4];
  short s0c;
  unsigned char b0e;
  char pad0f[1];
  Vec4 v10;
  Vec4 v20;
};

struct Actor {
  virtual void av0();
  virtual void av1();
  virtual void av2();
  virtual void av3();
  virtual void av4();
  virtual void av5(Vec4 *);
  virtual Vec4 *av6();
  virtual void av7(Vec4 *);
};

struct Renderer {
  virtual void rv0();
  virtual void rv1();
  virtual void rv2();
  virtual void rv3();
  virtual void rv4();
  virtual void rv5();
  virtual void rv6();
  virtual void rv7();
  virtual void rv8();
  virtual void rv9();
  virtual void rv10();
  virtual void rv11();
  virtual void rv12();
  virtual void rv13();
  virtual void rv14();
  virtual void rv15();
  virtual void rv16();
  virtual void rv17();
  virtual void rv18();
  virtual void rv19();
  virtual void rv20();
  virtual void rv21();
  virtual void rv22();
  virtual void rv23();
  virtual void rv24();
  virtual void rv25();
  virtual void rv26();
  virtual void rv27();
  virtual void rv28();
  virtual void rv29(Vec4 *);
  virtual void rv30(Vec4 *);
  virtual void rv31();
  virtual void rv32();
  virtual void rv33();
  virtual void rv34();
  virtual void rv35();
  virtual void rv36();
  virtual void rv37();
  virtual void rv38();
  virtual void rv39();
};

extern Renderer *DAT_0034a118;
extern "C" void FUN_00022418(Vec4 *, Vec4 *, Vec4 *);
extern "C" void FUN_001caa90(int);
extern "C" Actor *FUN_001cd30c(int);
extern "C" char *FUN_0022a930();
extern "C" void FUN_00288e50(Actor *, int);
extern "C" void FUN_0028bb2c(float, int *, int *);

extern "C" void FUN_001ca238(int param_1)
{
  Item *it;
  Actor *obj;
  Vec4 m3;
  Vec4 m2;
  Vec4 m0;
  Vec4 m1;
  int n;
  int off;
  int i;
  Vec4 *p;

  n = 0;
  if (0 < *(int *)(FUN_0022a930() + 0xab28)) {
    off = 0;
    do {
      it = (Item *)((char *)(off + (int)FUN_0022a930()) + 0xa210);
      if (it->type == 3) {
        obj = *(Actor **)(*(int *)(param_1 + 0x4c) + it->idx * 4);
        if (obj != 0) {
          obj->av5(&it->v10);
          FUN_00022418(&m0, &it->v10, &it->v20);
          m3 = m0;
          obj->av7(&m3);
          *(unsigned char *)((char *)obj + 0x57) = it->b0e;
          FUN_00288e50(obj, it->s0c);
        }
      } else if (it->type == 2) {
        DAT_0034a118->rv29(&it->v10);
        FUN_00022418(&m1, &it->v10, &it->v20);
        m2 = m1;
        DAT_0034a118->rv30(&m2);
      }
      off += 0x30;
      n++;
    } while (n < *(int *)(FUN_0022a930() + 0xab28));
  }
  if (*(unsigned char *)(FUN_0022a930() + 0xab4d) != 0) {
    FUN_001caa90(param_1);
    obj = FUN_001cd30c(param_1);
    if (obj != 0) {
      p = obj->av6();
      DAT_0034a118->rv30(p);
      DAT_0034a118->rv39();
    }
  } else {
    *(char *)(param_1 + 0xf3) = 0;
  }
  i = *(int *)(param_1 + 0x17c);
  if (i != 0) {
    int *q = (int *)DAT_0034a118;
    if (q != 0)
      q = q + 0x38;
    FUN_0028bb2c(0.75f, (int *)i, q);
  }
}

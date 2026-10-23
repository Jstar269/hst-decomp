/* HSTMATCH module=EBOOT.BIN start=0x001eab84 end=0x001eadb0 symbol=FUN_001eab84 lang=c++ */
struct Obj {
  virtual void f0();
  virtual void f1();
  virtual void f2();
  virtual void f3();
  virtual void f4();
  virtual void set(int);
};

extern "C" {
void FUN_00102e38(void);
void FUN_00104118(void *, const char *, int);
void FUN_00103540(float, void *);
void *FUN_001039d8(void *, int, int);
int FUN_001026b8(void *, int);
void FUN_000ffc3c(void *, int);
extern int DAT_003094a0;
extern char DAT_002ee0c4[];
extern float DAT_002ec1c4;
extern int DAT_002ed32c[];
extern int DAT_002eda10[];
extern int DAT_002ee04c[];
}

extern "C" int *FUN_001eab84(int *p)
{
  int *tbl;
  Obj *obj;
  int *dst;
  int i;
  int odd;

  FUN_00102e38();
  *p = (int)&DAT_003094a0;
  FUN_00104118(p, DAT_002ee0c4, 0);
  FUN_00103540(DAT_002ec1c4, p);

  i = 0;
  do {
    obj = (Obj *)FUN_001039d8(p, DAT_002ed32c[i], 0);
    ((int **)p)[0x15 + i] = (int *)obj;
    obj->set(-2);
    i++;
  } while (i < 7);

  i = 0;
  tbl = DAT_002eda10;
  do {
    obj = (Obj *)FUN_001026b8((void *)p[tbl[0] + 0x15], tbl[1]);
    ((int **)p)[0x1c + i] = (int *)obj;
    if (obj != 0) {
      FUN_000ffc3c(obj, -256);
      tbl[2] = *(int *)((int)((int **)p)[0x1c + i] + 0x24);
    }
    i++;
    tbl += 3;
  } while (i < 0x85);

  i = 0;
  tbl = DAT_002ee04c;
  do {
    obj = *(Obj **)(p[tbl[0] + 0x1c] + 0x20);
    ((int **)p)[0xa1 + i] = (int *)obj;
    obj->set(-16);
    i++;
    tbl++;
  } while (i < 0x1e);

  i = 0;
  tbl = DAT_002eda10;
  dst = p;
  do {
    odd = (i % 2) != 0 ? 2 : 0;
    obj = *(Obj **)((char *)dst + 0x80);
    *(int *)((char *)obj + 0x24) = odd + *(int *)((char *)tbl + 0x38);
    *(int *)((char *)obj + 0x28) = odd + *(int *)((char *)tbl + 0x38);
    i++;
    tbl += 0x42;
    dst += 0x16;
  } while (i < 6);

  p[0xbf] = 1;
  p[0xc0] = 2;
  p[0xc1] = 3;
  p[0xc2] = 4;
  p[0xc3] = 5;
  p[0xc4] = 6;
  p[0xc5] = 2;
  p[0xc6] = 0x18;
  p[0xc7] = 0x2e;
  p[0xc8] = 0x44;
  p[0xc9] = 0x5a;
  p[0xca] = 0x70;
  return p;
}

// NEAR MISS: 137/139 words. Every loop body is right, but mwcc strength-reduces the destination
// `p[0x15 + i]` into a pointer induction variable (`move s1,s0 / sw v0,84(s1)`), while retail keeps
// a byte OFFSET counter and adds it each iteration (`move s1,zero / addu v1,s0,s1 / sw v0,84(v1)`),
// which costs one more word per loop (two loops -> 137 vs 139). Tried: array index p[0x15+i],
// (int)p + off + K, (int)p + K + off, an int base parameter with int arithmetic (143 words, worse).
// Confirmed from this function: the two sub-object helpers are C++ virtual calls (slot 0x1c), so the
// file must be c++ with a class whose vtable has 2 hidden leading slots and 5 virtuals before set(int);
// the 6-iteration loop's `bgez/andi/addiu -2` is `i % 2` on a signed int used as `(i % 2) ? 2 : 0`.
// near miss from lane fm4 (unreviewed)

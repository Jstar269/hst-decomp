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

#pragma opt_strength_reduction off
extern "C" int *FUN_001eab84(int *p)
{
  int i;
  int *tbl;
  int off;
  Obj *obj;
  int *dst;
  int odd;
  int val;

  FUN_00102e38();
  *p = (int)&DAT_003094a0;
  FUN_00104118(p, DAT_002ee0c4, 0);
  FUN_00103540(DAT_002ec1c4, p);

  i = 0;
  tbl = DAT_002ed32c;
  off = 0;
  do {
    (*(Obj **)((char *)p + off + 0x54) = (Obj *)FUN_001039d8(p, *tbl, 0))->set(-2);
    i++;
    tbl++;
    off += 4;
  } while (i < 7);

  i = 0;
  tbl = DAT_002eda10;
  off = 0;
  do {
    obj = (Obj *)FUN_001026b8((void *)p[tbl[0] + 0x15], tbl[1]);
    *(Obj **)((char *)p + off + 0x70) = obj;
    if (obj != 0) {
      FUN_000ffc3c(obj, -256);
      tbl[2] = *(int *)(*(int *)((int)p + off + 0x70) + 0x24);
    }
    i++;
    tbl += 3;
    off += 4;
  } while (i < 0x85);

  i = 0;
  tbl = DAT_002ee04c;
  off = 0;
  do {
    obj = *(Obj **)(p[tbl[0] + 0x1c] + 0x20);
    *(Obj **)((char *)p + off + 0x284) = obj;
    obj->set(-16);
    i++;
    tbl++;
    off += 4;
  } while (i < 0x1e);

  {
    int j;
    int *t4;
    int *d4;
    int odd4;
    int val4;
    Obj *o4;
    j = 0;
    t4 = DAT_002eda10;
    d4 = p;
    do {
      odd4 = (j % 2) != 0 ? 2 : 0;
      val4 = odd4 + *(int *)((char *)t4 + 0x38);
      o4 = *(Obj **)((char *)d4 + 0x80);
      *(int *)((char *)o4 + 0x24) = val4;
      *(int *)((char *)o4 + 0x28) = val4;
      j++;
      t4 += 0x42;
      d4 += 0x16;
    } while (j < 6);
  }

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

// NEAR MISS (sn7 session): 139/139 words, 7 differ, all in loop 3 (the 0x1e-pass `p[0xa1+i]` loop): retail loads tbl[0] into v0 and the store address
// `addu v1,s0,s1`, we colour them the other way round (chain in v1, address in v0). Everything else matches, including the per-loop byte-offset counters.
// What fixed the earlier 137-word form (offset induction variables, 2 words short per loop): `#pragma opt_strength_reduction off` + explicit `i`, `tbl++`, `off += 4`
// (an explicit off alone is folded back into a pointer IV); the reload of the stored slot must be `(int)p + off + 0x70` (int sum, `p` first) or MWCC CSEs it into a
// second saved register; `(Obj *)(slot = F())->set()` as ONE expression in loop 1 puts `move a0,v0` after the vtable load; the loop-4 value `odd + tbl[0x38]` is one
// local (single `lw`), and loop 4's j/t4/d4 as block-scope locals declared j, t4, d4 (i.e. count, table, cursor) with `val4` computed BEFORE `o4` gives a3/a2/t0 exactly.
// Ruled out for loop 3 (all still 7): 840 function-level declaration permutations, block-scope locals in 20 declaration positions, k=tbl[0] split, slot pointer before/after,
// fused `(*(slot) = x)->set()`, `((int**)p)[0x1c+*tbl][8]`, `(int)p + off` address, ordering of statements.
// improved by lane sn7 (unreviewed): 110 -> 7 differing words

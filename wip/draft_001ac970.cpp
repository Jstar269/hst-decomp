/* HSTMATCH module=EBOOT.BIN start=0x001ac970 end=0x001acb5c symbol=FUN_001ac970 lang=c++ */
struct Widget {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void Set(int v);
};

struct Vec {
    int *data;
    unsigned int size;
};

struct Holder1 {
    char pad[0x36c];
    Vec v;
};

struct Holder2 {
    char pad[0x360];
    int *data;
};

#pragma opt_strength_reduction off
extern "C" {
extern void FUN_000ffb3c(int, int);
extern void FUN_00103628(int, int);
extern void FUN_0010b6d4(int, int, int);
extern Holder1 *FUN_0019d474();
extern void FUN_001acb5c(int *, int);
extern void FUN_001acc30(int *, int);
extern void FUN_001acf64(int *, int);
extern void FUN_001ad350(int *, int);
extern void FUN_001ad604(int *, int);
extern void FUN_001ad89c(int *, int);

void FUN_001ac970(int *param_1)
{
  Vec *vA;
  int **vB;
  unsigned int i;
  int off;
  int *p;
  int *piVar4;
  int *q;
  int k;
  int *wb;

  FUN_0010b6d4(param_1[0x245], 0, 5);
  FUN_00103628(*param_1, 0);
  vA = &FUN_0019d474()->v;
  vB = &((Holder2 *)FUN_0019d474())->data;
  i = 0;
  if (vA->size != 0) {
    off = 0;
    p = param_1;
    do {
      if ((*vB)[i] != 6) {
        piVar4 = (int *)((char *)param_1 + (off + 0x78)) + 9;
        q = p + 9;
        if (vA->data[i] != 0) {
          FUN_000ffb3c(*piVar4, 1);
          *(int *)*q = 0x80808080;
        }
        else {
          FUN_000ffb3c(*piVar4, 0);
          *(int *)*q = q[4];
        }
        if ((*vB)[i] == 5) {
          k = 7;
          q = param_1 + 0x15;
          do {
            wb = (int *)((char *)q + 2156);
            if (vA->data[i] != 0) {
              ((Widget *)wb[1])->Set(param_1[0x246]);
            }
            else {
              ((Widget *)wb[1])->Set(param_1[0x247]);
            }
            k++;
            q += 3;
          } while (k <= 12);
        }
      }
      i++;
      off += 0x14;
      p += 5;
    } while (i < vA->size);
  }
  FUN_001acb5c(param_1, 1);
  FUN_001acc30(param_1, 0);
  FUN_001acf64(param_1, 0);
  FUN_001ad350(param_1, 0);
  FUN_001ad604(param_1, 0);
  FUN_001ad89c(param_1, 0);
}
}
// NEAR (lane sx1): 123/123 words, 12 differ (was 120/123, 97 differ). Only the saved-register naming of the i*4 offset temp (ret s1, ours s2) and the
// q / inner-loop-base pointer (ret s2, ours s1) differs. Levers found: lang=c++ with a Widget class (4 dummy virtuals, Set at slot 4 = lw t9,24(t9));
// FUN_00103628(*param_1, 0) has a second argument; the two lists are `Vec*` / `int**` members taken straight from the call results (no Holder locals);
// opt_strength_reduction off (recomputes i*4); `(char*)param_1 + (off + 0x78)) + 9` for the first call's pointer; `k <= 12` (slti at); the widget
// address `(char*)q + 2156` read once per inner pass. Ruled out for the s1/s2 swap: 8 declaration orders of the pointer locals, an explicit `ofs = i*4`
// local in 6 positions (vA/ofs swap instead), removing the q local (86 differ), merging q with the inner-loop pointer.
// near miss from lane sx1 (unreviewed)

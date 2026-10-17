/* HSTMATCH module=EBOOT.BIN start=0x0012dc4c end=0x0012ddd0 symbol=FUN_0012dc4c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v17c) corrected by hand: the 16 copied words are float (DAT globals declared float -> lwc1/swc1, 1.0f literals), typed object with float arrays, virtual slot 7 takes a float pointer (changes the argument setup order); exact match verified; names and types await human review. */
extern "C" {
extern float DAT_002bc410, DAT_002bc414, DAT_002bc418, DAT_002bc41c;
extern float DAT_002bc430, DAT_002bc434, DAT_002bc438, DAT_002bc43c;
extern float DAT_002bc440, DAT_002bc444, DAT_002bc448, DAT_002bc44c;
extern char DAT_00308194;
extern void *DAT_0033b580;
extern int * FUN_000649c0(...);
extern void * FUN_00286790(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(float *); };

struct Obj {
  void *vt;
  char pad[0x70 - 4];
  float a[4], b[4], c[4];
  float f0, f1, f2, f3;
  float d[4];
  float e[4];
  int sub[4];
  int f_e0;
  unsigned char c_e4;
  int f_e8;
  unsigned char c_ec;
  int f_f0, f_f4, f_f8;
  char pad2[0x240 - 0xfc];
  float f240;
};

extern "C" Obj * FUN_0012dc4c(Obj *o)
{
  FUN_00286790();
  o->vt = &DAT_00308194;
  o->a[0] = DAT_002bc440; o->a[1] = DAT_002bc444; o->a[2] = DAT_002bc448; o->a[3] = DAT_002bc44c;
  o->b[0] = DAT_002bc440; o->b[1] = DAT_002bc444; o->b[2] = DAT_002bc448; o->b[3] = DAT_002bc44c;
  o->c[0] = DAT_002bc440; o->c[1] = DAT_002bc444; o->c[2] = DAT_002bc448; o->c[3] = DAT_002bc44c;
  o->f0 = 0; o->f1 = 0; o->f2 = 1.0f; o->f3 = 1.0f;
  o->d[0] = DAT_002bc430; o->d[1] = DAT_002bc434; o->d[2] = DAT_002bc438; o->d[3] = DAT_002bc43c;
  o->e[0] = DAT_002bc410; o->e[1] = DAT_002bc414; o->e[2] = DAT_002bc418; o->e[3] = DAT_002bc41c;
  FUN_000649c0(o->sub);
  o->f_e0 = 0;
  o->c_e4 = 0;
  o->f_e8 = 0;
  o->c_ec = 0;
  o->f_f0 = 0;
  o->f_f4 = 0;
  o->f_f8 = 0;
  o->f240 = 1.0f;
  DAT_0033b580 = o;
  ((VC_0 *)o)->m(&DAT_002bc440);
  return o;
}

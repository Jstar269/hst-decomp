/* HSTMATCH module=hstp_trans_main.prx start=0x0013914c end=0x001392d0 symbol=FUN_0013914c lang=c++ */
/* Clone of src/eboot/ctor_init_floats_from_globals_0012dc4c.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v17c) corrected by hand: the 16 copied words are float (DAT globals declared float -> lwc1/swc1, 1.0f literals), typed object with float arrays, virtual slot 7 takes a float pointer (changes the argument setup order); exact match verified; names and types await human review. */
extern "C" {
extern float DAT_002cc260, DAT_002cc264, DAT_002cc268, DAT_002cc26c;
extern float DAT_002cc280, DAT_002cc284, DAT_002cc288, DAT_002cc28c;
extern float DAT_002cc290, DAT_002cc294, DAT_002cc298, DAT_002cc29c;
extern char DAT_003b1460;
extern void *DAT_003e48c0;
extern int * FUN_00065884(...);
extern void * FUN_00297ebc(...);
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

extern "C" Obj * FUN_0013914c(Obj *o)
{
  FUN_00297ebc();
  o->vt = &DAT_003b1460;
  o->a[0] = DAT_002cc290; o->a[1] = DAT_002cc294; o->a[2] = DAT_002cc298; o->a[3] = DAT_002cc29c;
  o->b[0] = DAT_002cc290; o->b[1] = DAT_002cc294; o->b[2] = DAT_002cc298; o->b[3] = DAT_002cc29c;
  o->c[0] = DAT_002cc290; o->c[1] = DAT_002cc294; o->c[2] = DAT_002cc298; o->c[3] = DAT_002cc29c;
  o->f0 = 0; o->f1 = 0; o->f2 = 1.0f; o->f3 = 1.0f;
  o->d[0] = DAT_002cc280; o->d[1] = DAT_002cc284; o->d[2] = DAT_002cc288; o->d[3] = DAT_002cc28c;
  o->e[0] = DAT_002cc260; o->e[1] = DAT_002cc264; o->e[2] = DAT_002cc268; o->e[3] = DAT_002cc26c;
  FUN_00065884(o->sub);
  o->f_e0 = 0;
  o->c_e4 = 0;
  o->f_e8 = 0;
  o->c_ec = 0;
  o->f_f0 = 0;
  o->f_f4 = 0;
  o->f_f8 = 0;
  o->f240 = 1.0f;
  DAT_003e48c0 = o;
  ((VC_0 *)o)->m(&DAT_002cc290);
  return o;
}

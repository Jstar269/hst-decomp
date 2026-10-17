/* HSTMATCH module=hstp_trans_main.prx start=0x001f870c end=0x001f8878 symbol=FUN_001f870c lang=c99 */
/* Clone of src/eboot/ramp_sub_floats_001ea468.c (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: typed structs, branch order swapped (flag set first), the first sub-object's float read before the flag test, loops over the 8 sub-objects; exact match verified; names and types await human review. */
typedef struct Sub { char pad[0x78]; float f78; } Sub;
typedef struct Obj {
  char pad[0x5c];
  Sub *w[8];
  char pad2[0x3c0];
  unsigned char f43c;
  char pad3[3];
  int f440;
} Obj;

extern float DAT_003951a0;
extern float DAT_003951a4;
extern void FUN_00108a2c(Obj *);
extern void FUN_00108dac(Obj *);
extern void FUN_001f7c00(Obj *);
extern void FUN_001f8124(Obj *, int);

void FUN_001f870c(Obj *o)
{
  float f;
  float t;
  int i;
  float first;
  FUN_001f8124(o, 0);
  first = o->w[0]->f78;
  if (o->f43c != 0) {
    FUN_001f7c00(o);
    f = 1.0f;
    t = (float)o->f440;
    if (t <= DAT_003951a0) {
      f = 0.0f;
    } else if (t <= DAT_003951a4) {
      f = (t - DAT_003951a0) / (DAT_003951a4 - DAT_003951a0);
    }
    if ((float)o->f440 <= DAT_003951a4) {
      for (i = 0; i < 8; i++) {
        o->w[i]->f78 = f;
      }
      FUN_00108dac(o);
    }
  } else {
    if (first != 1.0f) {
      for (i = 0; i < 8; i++) {
        o->w[i]->f78 = 1.0f;
      }
      FUN_00108dac(o);
    }
  }
  FUN_00108a2c(o);
}

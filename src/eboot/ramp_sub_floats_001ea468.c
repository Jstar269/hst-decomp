/* HSTMATCH module=EBOOT.BIN start=0x001ea468 end=0x001ea5d4 symbol=FUN_001ea468 lang=c99 */
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

extern float DAT_002ed274;
extern float DAT_002ed278;
extern void FUN_00103128(Obj *);
extern void FUN_00103480(Obj *);
extern void FUN_001e995c(Obj *);
extern void FUN_001e9e80(Obj *, int);

void FUN_001ea468(Obj *o)
{
  float f;
  float t;
  int i;
  float first;
  FUN_001e9e80(o, 0);
  first = o->w[0]->f78;
  if (o->f43c != 0) {
    FUN_001e995c(o);
    f = 1.0f;
    t = (float)o->f440;
    if (t <= DAT_002ed274) {
      f = 0.0f;
    } else if (t <= DAT_002ed278) {
      f = (t - DAT_002ed274) / (DAT_002ed278 - DAT_002ed274);
    }
    if ((float)o->f440 <= DAT_002ed278) {
      for (i = 0; i < 8; i++) {
        o->w[i]->f78 = f;
      }
      FUN_00103480(o);
    }
  } else {
    if (first != 1.0f) {
      for (i = 0; i < 8; i++) {
        o->w[i]->f78 = 1.0f;
      }
      FUN_00103480(o);
    }
  }
  FUN_00103128(o);
}

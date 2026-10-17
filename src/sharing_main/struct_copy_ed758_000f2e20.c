/* HSTMATCH module=hstp_trans_main.prx start=0x000f2e20 end=0x000f2ed8 symbol=FUN_000f2e20 lang=c99 */
/* Clone of src/eboot/struct_copy_ed758_000ed758.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v2) corrected by hand: typed struct with int words at 16,17,19,20 among floats (lw/sw instead of lwc1/swc1); exact match verified; names and types await human review. */
typedef struct S {
  float f0;
  float f1;
  float f2;
  float f3;
  float f4;
  float f5;
  float f6;
  float f7;
  float f8;
  float f9;
  float f10;
  float f11;
  float f12;
  float f13;
  float f14;
  float f15;
  int f16;
  int f17;
  float f18;
  int f19;
  int f20;
  float f21;
} S;
S *FUN_000f2e20(S *d, S *s)
{
  d->f0 = s->f0;
  d->f1 = s->f1;
  d->f2 = s->f2;
  d->f3 = s->f3;
  d->f4 = s->f4;
  d->f5 = s->f5;
  d->f6 = s->f6;
  d->f7 = s->f7;
  d->f8 = s->f8;
  d->f9 = s->f9;
  d->f10 = s->f10;
  d->f11 = s->f11;
  d->f12 = s->f12;
  d->f13 = s->f13;
  d->f14 = s->f14;
  d->f15 = s->f15;
  d->f16 = s->f16;
  d->f17 = s->f17;
  d->f18 = s->f18;
  d->f19 = s->f19;
  d->f20 = s->f20;
  d->f21 = s->f21;
  return d;
}

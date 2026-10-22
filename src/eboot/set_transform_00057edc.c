/* HSTMATCH module=EBOOT.BIN start=0x00057edc end=0x00057f30 symbol=FUN_00057edc lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
struct Vec4 {
  float x;
  float y;
  float z;
  float w;
};

struct Obj {
  char pad[0x184];
  float f184;
  char pad2[8];
  float f190;
  float f194;
  float f198;
  char pad3[4];
  int f1a0;
  int f1a4;
  unsigned char f1a8;
};

void FUN_00057edc(struct Obj *self, struct Vec4 v, float f, int p4, int p5, unsigned char p6)
{
  self->f184 = f;
  self->f190 = v.x;
  self->f194 = v.y;
  self->f198 = v.z;
  self->f1a0 = p4;
  self->f1a4 = p5;
  self->f1a8 = p6;
}

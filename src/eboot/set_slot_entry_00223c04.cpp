/* HSTMATCH module=EBOOT.BIN start=0x00223c04 end=0x00223db0 symbol=FUN_00223c04 lang=c++ rodata=0x002c99e4 */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the switch is on 'kind - 1' with a 'case -1:' sharing the default body, which gives retail's addiu -1 / addiu +1 table index); names and types await human review. */
struct Obj {
  char pad[0x78];
  int cur;
  int keys[2];
  int ids[2];
  float f8c[2];
  float f94[2];
  float f9c[2];
  unsigned char fa4[2];
};

extern "C" {
extern float DAT_0034a290;
extern float DAT_0034a294;
extern float DAT_0034a2a0;
extern float DAT_002f10e8;
extern float DAT_002f10ec;
void FUN_00223de0(Obj *);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_00223c04(Obj *self, int key, int kind)
{
  int id;
  switch (kind - 1) {
  case 6:
    id = 6;
    break;
  case 5:
    id = 0;
    break;
  case 4:
    id = 1;
    break;
  case 3:
    id = 2;
    break;
  case 2:
    id = 3;
    break;
  case 1:
    id = 4;
    break;
  case 0:
    id = 5;
    break;
  case -1:
  default:
    id = -1;
    break;
  }
  FUN_00223de0(self);
  if (self->cur < 0) {
    self->cur = 0;
    self->keys[0] = 0;
  }
  if (self->keys[self->cur] == key && self->ids[self->cur] == id)
    return;
  self->cur ^= 1;
  self->keys[self->cur] = key;
  self->ids[self->cur] = id;
  self->f8c[self->cur] = DAT_0034a290;
  self->f94[self->cur] = DAT_0034a294;
  self->f9c[self->cur] = Clamp(DAT_0034a2a0, DAT_002f10e8, DAT_002f10ec);
  self->fa4[self->cur] = 0;
}

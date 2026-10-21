/* HSTMATCH module=hstp_trans_main.prx start=0x00233178 end=0x00233324 symbol=FUN_00233178 lang=c++ rodata=0x002d9fa4 */
/* Clone of src/eboot/set_slot_entry_00223c04.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
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
extern float DAT_003f35c0;
extern float DAT_003f35c4;
extern float DAT_003f35d0;
extern float DAT_003994b4;
extern float DAT_003994b8;
void FUN_00233354(Obj *);
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" void FUN_00233178(Obj *self, int key, int kind)
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
  FUN_00233354(self);
  if (self->cur < 0) {
    self->cur = 0;
    self->keys[0] = 0;
  }
  if (self->keys[self->cur] == key && self->ids[self->cur] == id)
    return;
  self->cur ^= 1;
  self->keys[self->cur] = key;
  self->ids[self->cur] = id;
  self->f8c[self->cur] = DAT_003f35c0;
  self->f94[self->cur] = DAT_003f35c4;
  self->f9c[self->cur] = Clamp(DAT_003f35d0, DAT_003994b4, DAT_003994b8);
  self->fa4[self->cur] = 0;
}

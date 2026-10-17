/* HSTMATCH module=EBOOT.BIN start=0x0013076c end=0x0013086c symbol=FUN_0013076c lang=c99 */
/* Clone of src/sharing_main/update_level_flags_0013bd24.c (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Inner {
  char pad0[0x268];
  int f268;
} Inner;
typedef struct {
  char pad0[0x88];
  Inner *f88;
  char pad1[0x10];
  int f9c;
} Game;
typedef struct {
  char pad0[0xf2];
  unsigned char f242;
  unsigned char f243;
  int f244;
  int f248;
  int f24c;
  int f250;
  char pad1[0xc];
  float x, y, z, w;
} Obj;

extern Game *DAT_003386b0;
extern int FUN_001181c0(int);

void FUN_0013076c(Obj *self, const float *v, int level, int a, int b)
{
  int big;
  big = 0;
  if (level >= 31) {
    big = 1;
  }
  if (big) {
    self->f243 = 1;
  }
  if (big && self->f242 == 0) {
    Inner *p;
    int r;
    self->f242 = 1;
    self->f244 = level;
    self->f248 = a;
    self->f24c = b;
    self->f250 = 0;
    self->x = v[0];
    self->y = v[1];
    self->z = v[2];
    self->w = v[3];
    p = DAT_003386b0->f88;
    r = FUN_001181c0(DAT_003386b0->f9c);
    self->f250 = r + p->f268;
  } else if (big) {
    if (self->f248 != a) {
      self->f248 = a;
      self->x = v[0];
      self->y = v[1];
      self->z = v[2];
      self->w = v[3];
    }
    if (self->f24c != b) {
      self->f24c = b;
    }
  }
}

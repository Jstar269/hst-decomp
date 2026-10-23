/* HSTMATCH module=EBOOT.BIN start=0x001178f0 end=0x00117a54 symbol=FUN_001178f0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Ninth-slot ring buffer (entry 0x70 bytes at +0x80): the reset branch must be `if (param_4 != 0) {init}
   else {store}` so that the likely branch jumps to the shared store, and the f60 test is inverted the
   same way (`if (f60 != idx2) f60 = 0; else f60 = (idx2+1)%9;`). */

typedef struct {
  float x, y, z, w;
} Vec4_001178f0;

typedef struct {
  Vec4_001178f0 a;      /* 0x00 */
  Vec4_001178f0 b;      /* 0x10 */
  float c;              /* 0x20 */
  float d;              /* 0x24 */
  float e;              /* 0x28 */
  float f;              /* 0x2c */
  int g;                /* 0x30 */
  short h;              /* 0x34 */
  signed char i;        /* 0x36 */
  signed char j;        /* 0x37 */
  int k;                /* 0x38 */
  char pad_3c[4];
  int f40;              /* 0x40 */
  char pad_44[0x0c];
  int f50;              /* 0x50 */
  int f54;              /* 0x54 */
  int f58;              /* 0x58 */
  int f5c;              /* 0x5c */
  unsigned char b60;    /* 0x60 */
  signed char b61;      /* 0x61 */
  char pad_62[0x0e];
} Entry_001178f0;

typedef struct {
  char pad_00[0x40];
  unsigned char f40;    /* 0x40 */
  char pad_41[0x0b];
  unsigned char f4c;    /* 0x4c */
  char pad_4d[3];
  int f50;              /* 0x50 */
  unsigned char f54;    /* 0x54 */
  char pad_55[3];
  int f58;              /* 0x58 */
  int f5c;              /* 0x5c */
  int f60;              /* 0x60 */
  int f64;              /* 0x64 */
  char pad_68[4];
  int f6c;              /* 0x6c */
  char pad_70[0x10];
  Entry_001178f0 ring[9];  /* 0x80 */
} Obj_001178f0;

extern unsigned char *DAT_003386b0;

void FUN_001178f0(Obj_001178f0 *self, const Entry_001178f0 *src, int param_3, int param_4)
{
  Entry_001178f0 *e;
  int n;
  int idx;
  int idx2;

  if (*(int *)(DAT_003386b0 + 0x3c) == 7) {
    return;
  }
  if (param_4 != 0) {
    self->f4c = 0;
    self->f50 = 0;
    self->f54 = 0;
    self->f58 = 0;
    self->f5c = -1;
    self->f60 = -1;
    self->f64 = -1;
    self->f6c = -1;
    self->f40 = 0;
    self->f54 = param_3;
  }
  else {
    self->f54 = param_3;
  }
  n = self->f5c + 1;
  idx = n % 9;
  self->f5c = n;
  self->f5c = idx;
  e = &self->ring[idx];
  e->b60 = param_3;
  e->b61 = param_4;
  e->a = src->a;
  e->b = src->b;
  e->c = src->c;
  e->d = src->d;
  e->e = src->e;
  e->f = src->f;
  e->g = src->g;
  e->h = src->h;
  e->i = src->i;
  e->j = src->j;
  e->k = src->k;
  e->k = self->f58;
  e->f40 = 0;
  e->f50 = 0;
  e->f54 = 0;
  e->f58 = 0;
  e->f5c = 0;
  idx2 = (self->f5c + 1) % 9;
  self->f64 = idx2;
  if (self->f60 != idx2) {
    self->f60 = 0;
  }
  else {
    self->f60 = (idx2 + 1) % 9;
  }
  self->f6c = 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x00196ef4 end=0x00197208 symbol=FUN_00196ef4 lang=c++ rodata=0x002c28a0 */
/* Hand-written reconstruction from the disassembly; matching idioms: dense 0..13 switch (rodata=0x002c28a0) with case 0 ending in 'continue' (the others 'break'), counter n declared before the loop counter, the sprite slot read as self->spr[n] with 'n++' as the LAST statement of case 7, int (not short) arithmetic in the rect stores; exact match verified; names and types await human review. */
struct Dev {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void m3();
};

struct Spr {
  char pad[4];
  short s4;
  short s6;
  short s8;
  short s10;
};

struct Ent {
  int type;
  int a;
  int b;
  float c;
  float d;
};

struct Self {
  Dev *dev;
  char pad0[0x1c - 4];
  Spr *spr[6];
  char pad1[0xf4 - 0x34];
  Ent ent[10];
  int count;
};

extern "C" {
void FUN_00103628(Dev *, int);
void FUN_00196aac(Self *, int *, int *, int, int, Ent *);
void FUN_00196c6c(Self *, int *, int *, int, Ent *);
void FUN_000ffb3c(Spr *, int);
}

extern "C" void FUN_00196ef4(Self *self)
{
  FUN_00103628(self->dev, 1);
  int l4 = 0;
  int l8 = 0;
  int lc = 0;
  int n = 0;
  int i;
  for (i = 0; i < self->count; i++) {
    Ent *e = &self->ent[i];
    switch (e->type) {
    case 0:
      FUN_00196aac(self, &l4, &l8, 0, 4, e);
      continue;
    case 1:
      FUN_00196aac(self, &l4, &l8, 2, 4, e);
      break;
    case 2:
      FUN_00196aac(self, &l4, &l8, 1, 4, e);
      break;
    case 3:
      FUN_00196aac(self, &l4, &l8, 3, 4, e);
      break;
    case 4:
      FUN_00196aac(self, &l4, &l8, 4, 5, e);
      break;
    case 5:
      FUN_00196aac(self, &l4, &l8, 5, 6, e);
      break;
    case 6:
      FUN_00196c6c(self, &lc, &l8, 10, e);
      break;
    case 7:
      if (n < 6) {
        Spr *o = self->spr[n];
        FUN_000ffb3c(o, 0);
        o->s4 = e->a;
        o->s6 = e->b - 3;
        o->s8 = o->s4 + (int)(20.0f * e->c);
        o->s10 = o->s6 + (int)(20.0f * e->d);
        n++;
      }
      break;
    case 8:
      FUN_00196c6c(self, &lc, &l8, 0, e);
      break;
    case 9:
      FUN_00196c6c(self, &lc, &l8, 3, e);
      break;
    case 10:
      FUN_00196c6c(self, &lc, &l8, 2, e);
      break;
    case 11:
      FUN_00196c6c(self, &lc, &l8, 1, e);
      break;
    case 12:
      FUN_00196aac(self, &l4, &l8, 6, 7, e);
      break;
    case 13:
      FUN_00196aac(self, &l4, &l8, 7, 8, e);
      break;
    }
  }
  if (self->count > 0) self->dev->m3();
  self->count = 0;
}

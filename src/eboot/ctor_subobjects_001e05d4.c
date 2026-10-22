/* HSTMATCH module=EBOOT.BIN start=0x001e05d4 end=0x001e0748 symbol=FUN_001e05d4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_unroll_loops off

typedef struct L3 { char pad0[4]; void *f4; } L3;
typedef struct L2 { char pad0[16]; L3 *f10; } L2;
typedef struct L1 { char pad0[4]; L2 *f4; } L1;
typedef struct L0 { char pad0[4]; L1 *f4; } L0;

typedef struct {
  char pad00[0x3c];
  void *f3c;
  void *f40;
  char pad44[0x48 - 0x44];
  char f48[0xd4 - 0x48];
  void *fd4;
  char pad_d8[0x1f4 - 0xd8];
  void *f1f4;
  char pad1f8[0x810 - 0x1f8];
  void *f810;
  char pad814[0x9b4 - 0x814];
  void *f9b4;
  char pad9b8[0x175c - 0x9b8];
  void *f175c;
  char pad1760[0x1954 - 0x1760];
  void *f1954;
  void *f1958;
  void *f195c;
  char pad1960[0x1adc - 0x1960];
  int g[21];
  char pad1b30[0x1d68 - 0x1b30];
  void *f1d68;
  char pad1d6c[0x21e4 - 0x1d6c];
  void *f21e4;
  char pad21e8[0x235c - 0x21e8];
  void *f235c;
  char pad2360[0x2464 - 0x2360];
  void *f2464;
  char pad2468[0x250c - 0x2468];
  void *f250c;
  char pad2510[0x25b8 - 0x2510];
  void *f25b8;
} Obj;

extern void *FUN_00000bcc(int size);
extern void *FUN_001dd0a4(void *p);
extern void *FUN_001dd28c(void *p);
extern void *FUN_00102e38(void *p);
extern void FUN_00217614(void *p, void *q);
extern void FUN_001e248c(Obj *self);
extern void FUN_001e185c(Obj *self);
extern void FUN_001e1c40(Obj *self);
extern void FUN_001e25c0(Obj *self);

void FUN_001e05d4(Obj *self)
{
  int i;
  void *p;

  self->f3c = 0;
  self->f40 = 0;
  self->fd4 = 0;
  self->f1f4 = 0;
  self->f9b4 = 0;
  self->f810 = 0;
  self->f175c = 0;
  self->f1d68 = 0;
  self->f1958 = 0;
  self->f195c = 0;
  self->f21e4 = 0;
  self->f235c = 0;
  self->f2464 = 0;
  self->f250c = 0;
  self->f25b8 = 0;
  self->f1954 = 0;

  /* matching idiom: the int table at +0x1adc is cleared with a FLAT index that
     steps by 7 (the retail loop counter), which needs the seven stores spelled
     out and the loop kept rolled (#pragma opt_unroll_loops off). */
  for (i = 0; i < 21; i += 7) {
    self->g[i + 0] = 0;
    self->g[i + 1] = 0;
    self->g[i + 2] = 0;
    self->g[i + 3] = 0;
    self->g[i + 4] = 0;
    self->g[i + 5] = 0;
    self->g[i + 6] = 0;
  }

  p = FUN_00000bcc(156);
  if (p != 0) {
    self->f3c = FUN_001dd0a4(p);
  } else {
    self->f3c = p;
  }

  p = FUN_00000bcc(100);
  if (p != 0) {
    p = FUN_001dd28c(p);
    self->f40 = p;
  } else {
    self->f40 = p;
  }

  FUN_00217614(&self->f48[0], ((L0 *)p)->f4->f4->f10->f4);

  p = FUN_00000bcc(84);
  if (p != 0) {
    self->f9b4 = FUN_00102e38(p);
  } else {
    self->f9b4 = p;
  }

  p = FUN_00000bcc(84);
  if (p != 0) {
    self->fd4 = FUN_00102e38(p);
  } else {
    self->fd4 = p;
  }

  p = FUN_00000bcc(84);
  if (p != 0) {
    self->f2464 = FUN_00102e38(p);
  } else {
    self->f2464 = p;
  }

  p = FUN_00000bcc(84);
  if (p != 0) {
    self->f25b8 = FUN_00102e38(p);
  } else {
    self->f25b8 = p;
  }

  FUN_001e248c(self);
  FUN_001e185c(self);
  FUN_001e1c40(self);
  FUN_001e25c0(self);
}

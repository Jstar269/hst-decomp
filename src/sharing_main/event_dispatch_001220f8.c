/* HSTMATCH module=hstp_trans_main.prx start=0x001220f8 end=0x001222a4 symbol=FUN_001220f8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same shape as src/eboot/event_dispatch_00117154.c (EBOOT 0x00117154, only addresses differ): an event
   switch whose labels are written in the reverse of retail's compare order (MWCC tests the labels in
   reverse source order and lays the bodies out in source order). */
typedef struct Game {
  char pad0[0x3c];
  int mode;
} Game;

extern Game *DAT_003e19f0;

typedef struct State {
  char pad0[0x3c];
  int f3c;
  unsigned char f40;
  char pad1[0x4c - 0x41];
  unsigned char f4c;
  char pad2[0x50 - 0x4d];
  int f50;
  unsigned char f54;
  char pad3[0x58 - 0x55];
  int f58;
  int f5c;
  int f60;
  int f64;
  char pad4[0x6c - 0x68];
  int f6c;
} State;

extern void FUN_0001ef24(State *, int, int);
extern void FUN_001222a4(State *, int);
extern void FUN_00122cc4(void);

int FUN_001220f8(State *self, int event)
{
  switch (event) {
  case 0:
    FUN_001222a4(self, 0);
    break;
  case 8:
    FUN_001222a4(self, 1);
    break;
  case 0x14:
    if (DAT_003e19f0->mode != 7)
      self->f50 = self->f58 + 1;
    break;
  case 0xe:
    FUN_00122cc4();
    FUN_001222a4(self, 3);
    break;
  case 0xa:
    FUN_001222a4(self, 2);
    break;
  case 0xb:
    FUN_001222a4(self, 4);
    break;
  case 0xc:
    FUN_001222a4(self, 4);
    break;
  case 0x12:
    self->f4c = 0;
    self->f50 = 0;
    self->f54 = 0;
    self->f58 = 0;
    self->f5c = -1;
    self->f60 = -1;
    self->f64 = -1;
    self->f6c = -1;
    self->f40 = 0;
    FUN_0001ef24(self, 0, 0);
    FUN_0001ef24(self, 1, 0);
    FUN_0001ef24(self, 2, 0);
    break;
  case 0x18:
    self->f3c = 4;
    FUN_0001ef24(self, 0, 1);
    FUN_0001ef24(self, 1, 1);
    FUN_0001ef24(self, 2, 1);
    break;
  }
  return 0;
}

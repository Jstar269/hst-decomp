/* HSTMATCH module=EBOOT.BIN start=0x00117154 end=0x00117300 symbol=FUN_00117154 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The case order is inverted relative to the retail chain: MWCC lays switch bodies out in reverse source
   order, so the cases are listed ascending here to emit retail's descending compare chain. */
extern int DAT_003386b0;

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

extern void FUN_0001f20c(State *, int, int);
extern void FUN_00117300(State *, int);
extern void FUN_00117c74(void);

int FUN_00117154(State *self, int event)
{
  switch (event) {
  case 0:
    FUN_00117300(self, 0);
    break;
  case 8:
    FUN_00117300(self, 1);
    break;
  case 0x14:
    if (*(int *)(DAT_003386b0 + 0x3c) != 7)
      self->f50 = self->f58 + 1;
    break;
  case 0xe:
    FUN_00117c74();
    FUN_00117300(self, 3);
    break;
  case 0xa:
    FUN_00117300(self, 2);
    break;
  case 0xb:
    FUN_00117300(self, 4);
    break;
  case 0xc:
    FUN_00117300(self, 4);
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
    FUN_0001f20c(self, 0, 0);
    FUN_0001f20c(self, 1, 0);
    FUN_0001f20c(self, 2, 0);
    break;
  case 0x18:
    self->f3c = 4;
    FUN_0001f20c(self, 0, 1);
    FUN_0001f20c(self, 1, 1);
    FUN_0001f20c(self, 2, 1);
    break;
  }
  return 0;
}

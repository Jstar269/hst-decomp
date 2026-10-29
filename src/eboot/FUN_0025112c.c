/* HSTMATCH module=EBOOT.BIN start=0x0025112c end=0x00251414 symbol=FUN_0025112c lang=c99 rodata=0x002ca654 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: `unk318_zero = !(v318 != 0)` for the sltu+xori+andi byte test, and the if/else arm order in the 2-or-3 state picks. */
#include "hst/types.h"

extern int DAT_002fbef4;
extern u8 DAT_0034179c;
extern unsigned char DAT_002fbef9;
extern int DAT_002fc560;
extern u32 *DAT_003415a8;
extern void FUN_0010b980();
extern void FUN_00110a78();
extern void FUN_001b1c44(u8 *, int);
extern u32 FUN_001fea10();
extern void FUN_00250f68();
extern void FUN_00251414();
extern void FUN_0025141c();

/* Fields at 0x24 and 0x28 of the record behind unk0c4 are set to the same value. */
typedef struct Rec0c4 {
  char pad00[0x24];
  int unk24;  /* 0x24 */
  int unk28;  /* 0x28 */
} Rec0c4;

typedef struct Player {
  char pad0[0xc4];
  Rec0c4 *unk0c4;          /* 0xc4 */
  char pad1[0x1d4 - 0xc8];
  int unk1d4;              /* 0x1d4 widget handle given to FUN_0010b980 */
  int unk1d8;              /* 0x1d8 handle; when nonzero a string is set on it by FUN_00110a78 */
  char pad2[0x2f8 - 0x1dc];
  int state;               /* 0x2f8 the state passed in */
  char pad3[0x304 - 0x2fc];
  int unk304;              /* 0x304 */
  char pad4[0x30c - 0x308];
  int unk30c;              /* 0x30c */
  unsigned char unk310;    /* 0x310 */
  char pad5[0x314 - 0x311];
  int unk314;              /* 0x314 */
  unsigned char unk318;    /* 0x318 */
  char pad6[0x34c - 0x319];
  int unk34c;              /* 0x34c holds the bit pattern of 101.0f in state 3 */
  char pad7[0x35c - 0x350];
  int unk35c;              /* 0x35c */
} Player;

void FUN_0025112c(Player *self, int state, int flag, int silent)
{
  unsigned char v318;
  unsigned char unk318_zero;
  int n;
  Rec0c4 *rec;
  u32 str;

  self->state = state;
  switch (state) {
  case 0:
  case 5:
  case 6:
    break;
  case 1:
    if (self->unk1d8 != 0) {
      str = FUN_001fea10(0x12, 5, 1);
      FUN_00110a78(self->unk1d8, str, 0);
    }
    if (flag == 0) {
      if (DAT_002fbef9 != 0) {
        FUN_00251414(self, 0);
      }
    }
    v318 = self->unk318;
    unk318_zero = !(v318 != 0);
    FUN_0010b980(self->unk1d4, unk318_zero, 0);
    rec = self->unk0c4;
    n = DAT_002fc560 + 1;
    rec->unk24 = n;
    rec->unk28 = n;
    break;
  case 2:
    if (self->unk1d8 != 0) {
      str = FUN_001fea10(0x12, 5, 2);
      FUN_00110a78(self->unk1d8, str, 0);
    }
    FUN_0025141c(self);
    FUN_00250f68(self, 0xffffffff, 0);
    if (self->unk30c != 0 && DAT_003415a8[0x21b35] == 0) {
      self->unk310 = 1;
      self->unk314 = 0;
      n = 3;
      self->unk304 = 3;
      DAT_002fbef4 = 3;
      if (self->unk30c != 0) {
        n = 3;
      }
      else {
        n = 2;
      }
      FUN_0010b980(self->unk1d4, (n + 2) - self->unk304, 0);
      DAT_003415a8[0x21b35] = 1;
    }
    if (DAT_002fbef9 != 0) {
      FUN_00251414(self, self->unk304 == 3);
    }
    n = self->unk30c;
    if (n != 0) {
      n = 3;
    }
    else {
      n = 2;
    }
    FUN_0010b980(self->unk1d4, (n + 2) - self->unk304, 0);
    rec = self->unk0c4;
    n = DAT_002fc560 + 2;
    rec->unk24 = n;
    rec->unk28 = n;
    break;
  case 3:
    if (self->unk1d8 != 0) {
      str = FUN_001fea10(0x12, 5, 0);
      FUN_00110a78(self->unk1d8, str, 0);
    }
    n = self->unk35c;
    FUN_0010b980(self->unk1d4, n + 6, 0);
    if (flag != 0) {
      self->unk34c = 0x42ca0000;
    }
    if (self->unk304 == 3) {
      FUN_0025141c(self);
    }
    break;
  case 4:
    if (self->unk1d8 != 0) {
      str = FUN_001fea10(0x12, 5, 0);
      FUN_00110a78(self->unk1d8, str, 0);
    }
    break;
  }
  if (silent == 0) {
    if (flag != 0) {
      FUN_001b1c44(&DAT_0034179c, 3);
    }
    else {
      FUN_001b1c44(&DAT_0034179c, 4);
    }
  }
}

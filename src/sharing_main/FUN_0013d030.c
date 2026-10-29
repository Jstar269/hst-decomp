/* HSTMATCH module=hstp_trans_main.prx start=0x0013d030 end=0x0013d10c symbol=FUN_0013d030 lang=c99 rodata=0x002d19a4 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Sub-object reached through the owner's pointer at 0x80. */
typedef struct SelectorSub {
  char pad00[0x90];
  int unk90;        /* 0x90 */
} SelectorSub;

typedef struct SelectorObj {
  char pad00[0x80];
  SelectorSub *unk80; /* 0x80 */
  char pad84[0x90 - 0x84];
  int unk90;        /* 0x90 */
  char pad94[0xb0 - 0x94];
  int unkb0;        /* 0xb0 */
  int unkb4;        /* 0xb4 */
  char padb8[0xd0 - 0xb8];
  int unkd0;        /* 0xd0 */
  char padd4[0x100 - 0xd4];
  int unk100;       /* 0x100 */
} SelectorObj;

enum { UNKB0_LIMIT = 0x32 };

/* Returns the integer value selected by `selector` (0 to 7) from the object; case 6 is the smaller of two offset values. */
int FUN_0013d030(SelectorObj *self,u32 selector)
{
  int result;
  float *smaller;
  float limit_b;
  float limit_a;
  
  switch(selector) {
  case 0:
    result = 0;
    break;
  case 1:
    result = self->unkb0;
    if (UNKB0_LIMIT < result) {
      result = 0;
    }
    break;
  case 2:
    result = self->unk80->unk90;
    break;
  case 3:
    result = self->unkb4;
    break;
  case 4:
    result = self->unk90;
    break;
  case 5:
    result = self->unkd0;
    break;
  case 6:
    limit_a = (float)self->unkb4 - 8.0f;
    limit_b = (float)self->unkd0 - 30.0f;
    if (limit_a < limit_b) {
      smaller = &limit_a;
    }
    else {
      smaller = &limit_b;
    }
    result = (int)*smaller;
    break;
  case 7:
    result = self->unk100;
    break;
  default:
    result = 0;
  }
  return result;
}

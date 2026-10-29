/* HSTMATCH module=EBOOT.BIN start=0x001c7d30 end=0x001c7df0 symbol=FUN_001c7d30 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted readiness guards and typed float/pointer helper arguments; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Setup {
  char pad00[0xc4];
  u32 unkc4;       /* 0xc4 */
  u32 unkc8;       /* 0xc8 */
  char padcc[0xd4 - 0xcc];
  u32 unkd4;       /* 0xd4 */
  u32 unkd8;       /* 0xd8 */
  u32 unkdc;       /* 0xdc */
  u8 unke0;        /* 0xe0 */
  char pade1;
  u8 unke2;        /* 0xe2 */
} Setup;

extern u8 * DAT_0033b574;
extern char DAT_002eaa14[];
extern char DAT_0034179c[];
extern char * FUN_00014d64();
extern void FUN_001b4848(float,void *);
extern void FUN_001b359c(float,void *);
extern u32 FUN_00287418();
extern u32 FUN_00287460();

void FUN_001c7d30(Setup *self,u32 a,u32 b,u32 c, u8 flag)
{
  int result;
  
  self->unkd4 = a;
  self->unkd8 = b;
  self->unkdc = c;
  self->unke2 = flag;
  if (DAT_0033b574 != 0) {
    result = FUN_00287418(DAT_0033b574 + 0x1320);
    if (result != 0) {
      result = FUN_00287460(DAT_0033b574 + 0x1320);
      if (result != 0) {
        result = (int)(FUN_00014d64(result,DAT_002eaa14));
        self->unke0 = result != 0;
      }
    } else {
      self->unke0 = 0;
    }
  } else {
    self->unke0 = 0;
  }
  FUN_001b4848(0.2f,DAT_0034179c);
  FUN_001b359c(0.2f,DAT_0034179c);
  self->unkc4 = 3;
  self->unkc8 = 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x000db64c end=0x000db724 symbol=FUN_000db64c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: model byte +0x45 as a field and route the zero flag to the common initializer call. */
#include "hst/types.h"

extern u8 DAT_003075f8;
extern u8 DAT_003386b8;
extern u8 * DAT_00338ac4;
extern u32 DAT_00338b44;
extern unsigned char DAT_00338b48;
extern u8 DAT_003417b8;
extern u8 DAT_003417b9;
extern unsigned char DAT_003417ba;
extern u32 * FUN_0001f06c();
extern void FUN_000db788();

typedef struct FlagView {
  char padding[0x45];
  unsigned char flag;
} FlagView;

u32 * FUN_000db64c(u32 *param_1)
{
  FUN_0001f06c(param_1);
  *param_1 = (unsigned int)(&DAT_003075f8);
  param_1[0xf] = 5;
  param_1[0x10] = 0;
  *(u8 *)(param_1 + 0x11) = 0;
  *(u8 *)((int)param_1 + 0x45) = 1;
  param_1[0x2d] = 3;
  param_1[0x30] = 2;
  param_1[0x33] = 4;
  DAT_00338b48 = 0;
  ((unsigned char *)param_1)[0x45] = DAT_003417b8 == '\0';
  param_1[0x2d] = (u32)DAT_003417b9;
  param_1[0x30] = (u32)DAT_003417ba;
  if ((DAT_003386b8 != '\0') && (2 < *(int *)(DAT_00338ac4 + 0x194))) {
    ((FlagView *)param_1)->flag = 0;
  }
  FUN_000db788((int)param_1);
  DAT_00338b44 = (unsigned int)(param_1);
  return param_1;
}

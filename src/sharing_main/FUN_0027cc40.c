/* HSTMATCH module=hstp_trans_main.prx start=0x0027cc40 end=0x0027cca4 symbol=FUN_0027cc40 lang=c99 */
/* Clone of src/eboot/FUN_0026bc68.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1a08;
extern int * FUN_0026c924();
extern int * FUN_0026ec7c();
extern int * FUN_00272c44();
extern int * FUN_0027a714();
extern int * FUN_0027c50c();

u32 * FUN_0027cc40(u32 *param_1)
{
  *param_1 = *(u32 *)(DAT_003e1a08 + 0x40);
  FUN_0027a714(param_1 + 1);
  FUN_0026ec7c(param_1 + 0x44);
  FUN_0026c924(param_1 + 0x1bc);
  FUN_00272c44(param_1 + 0x2af);
  FUN_0027c50c(param_1 + 0x2d2);
  param_1[0x2ee] = 0;
  param_1[0x2f2] = 0;
  return param_1;
}

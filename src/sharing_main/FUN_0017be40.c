/* HSTMATCH module=hstp_trans_main.prx start=0x0017be40 end=0x0017be94 symbol=FUN_0017be40 lang=c99 */
/* Clone of src/eboot/FUN_0016fbf4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

extern void FUN_0017788c();
extern void FUN_0017cef0();
extern void FUN_0017d068();

void FUN_0017be40(int param_1)
{
  (**(code **)(param_1 + 0x53c))(*(u32 *)(param_1 + 0xb8));
  FUN_0017788c(*(u32 *)(param_1 + 0xbc));
  FUN_0017cef0(param_1,0);
  if (*(u8 *)(param_1 + 0x3e) != '\0') {
    FUN_0017d068(param_1);
  }
}

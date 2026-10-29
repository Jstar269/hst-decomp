/* HSTMATCH module=hstp_trans_main.prx start=0x000bd848 end=0x000bd8c0 symbol=FUN_000bd848 lang=c99 data=0x0037b524 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002d4c5c-0x002d4d62) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/adhoc_net.h"

extern void FUN_000bd6f0();
extern int FUN_002c7a60();

/* Unloads the net utility modules (common, then ad-hoc); returns 1 when both unloaded. */
u32 FUN_000bd848(void)
{
  int result;
  u32 ok;
  
  result = FUN_002c7a60(UTILITY_MODULE_NET_COMMON);
  if (result < 0) {
    FUN_000bd6f0("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_COMMON) failed(0x%X)\n",result);
    ok = 0;
  }
  else {
    FUN_000bd6f0("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_COMMON) success\n");
    result = FUN_002c7a60(UTILITY_MODULE_NET_ADHOC);
    if (result < 0) {
      FUN_000bd6f0("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_ADHOC) failed(0x%X)\n",result);
      ok = 0;
    }
    else {
      FUN_000bd6f0("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_ADHOC) success\n");
      ok = 1;
    }
  }
  return ok;
}

/* HSTMATCH module=EBOOT.BIN start=0x000ba48c end=0x000ba504 symbol=FUN_000ba48c lang=c99 data=0x002d4b58 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002d4b58-0x002d4c5c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/adhoc_net.h"

extern void FUN_000ba3ac();
extern int FUN_002b7c18();

/* Loads the net utility modules (common, then ad-hoc); returns 1 when both loaded. */
u32 FUN_000ba48c(void)
{
  int result;
  u32 ok;
  
  result = FUN_002b7c18(UTILITY_MODULE_NET_COMMON);
  if (result < 0) {
    FUN_000ba3ac("sceUtilityLoadModule(SCE_UTILITY_MODULE_NET_COMMON) failed (0x%X)\n",result);
    ok = 0;
  }
  else {
    FUN_000ba3ac("sceUtilityLoadModule(SCE_UTILITY_MODULE_NET_COMMON) success\n");
    result = FUN_002b7c18(UTILITY_MODULE_NET_ADHOC);
    if (result < 0) {
      FUN_000ba3ac("sceUtilityLoadModule(SCE_UTILITY_MODULE_NET_ADHOC) failed(0x%X)\n",result);
      ok = 0;
    }
    else {
      FUN_000ba3ac("sceUtilityLoadModule(SCE_UTILITY_MODULE_NET_ADHOC) success\n");
      ok = 1;
    }
  }
  return ok;
}

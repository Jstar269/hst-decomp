/* HSTMATCH module=EBOOT.BIN start=0x001797b4 end=0x001797fc symbol=FUN_001797b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/list_host.h"

extern void FUN_0017ce84();
extern void FUN_00180edc();

void FUN_001797b4(ListHost *host)
{
  u32 value;
  
  if (0 < host->unk6c) {
    value = host->callback();
    FUN_00180edc(host->sub174,value);
    FUN_0017ce84(host->sub178);
  }
}

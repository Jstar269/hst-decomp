/* HSTMATCH module=EBOOT.BIN start=0x000a31b4 end=0x000a31fc symbol=FUN_000a31b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rig_obj.h"

extern int FUN_000b3c68();
extern float FUN_00163e60();

/* Maps the looked-up value (taken to range over 1..10) to 0..1. */
float FUN_000a31b4(RigObj *obj)
{
  u32 key;
  float value;
  
  key = FUN_000b3c68();
  value = (float)FUN_00163e60(key,obj->unk154);
  return (value - 1.0f) / 9.0f;
}

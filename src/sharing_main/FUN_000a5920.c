/* HSTMATCH module=hstp_trans_main.prx start=0x000a5920 end=0x000a5968 symbol=FUN_000a5920 lang=c99 */
/* Clone of src/eboot/FUN_000a31b4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/rig_obj.h"

extern int FUN_000b6e80();
extern float FUN_00170550();

/* Maps the looked-up value (taken to range over 1..10) to 0..1. */
float FUN_000a5920(RigObj *obj)
{
  u32 key;
  float value;
  
  key = FUN_000b6e80();
  value = (float)FUN_00170550(key,obj->unk154);
  return (value - 1.0f) / 9.0f;
}

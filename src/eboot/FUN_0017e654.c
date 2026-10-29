/* HSTMATCH module=EBOOT.BIN start=0x0017e654 end=0x0017e6c0 symbol=FUN_0017e654 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/light_obj.h"

extern u8 DAT_003090d4;
extern void FUN_00000a00();
extern int FUN_0005ba00();

/* Deleting destructor: tear down the two sub-objects (second first) and free when delete_flag > 0. */
LightObj * FUN_0017e654(LightObj *light,short delete_flag)
{
  if (light != (LightObj *)0x0) {
    light->vtable = &DAT_003090d4;
    FUN_0005ba00(light->sub2e0,0xffffffff);
    FUN_0005ba00(light->sub10,0xffffffff);
    if (0 < delete_flag) {
      FUN_00000a00(light);
    }
  }
  return light;
}

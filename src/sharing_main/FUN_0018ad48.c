/* HSTMATCH module=hstp_trans_main.prx start=0x0018ad48 end=0x0018adb4 symbol=FUN_0018ad48 lang=c99 */
/* Clone of src/eboot/FUN_0017e654.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/light_obj.h"

extern u8 DAT_003b23a0;
extern void FUN_00000a00();
extern int FUN_0005c688();

/* Deleting destructor: tear down the two sub-objects (second first) and free when delete_flag > 0. */
LightObj * FUN_0018ad48(LightObj *light,short delete_flag)
{
  if (light != (LightObj *)0x0) {
    light->vtable = &DAT_003b23a0;
    FUN_0005c688(light->sub2e0,0xffffffff);
    FUN_0005c688(light->sub10,0xffffffff);
    if (0 < delete_flag) {
      FUN_00000a00(light);
    }
  }
  return light;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0018afb0 end=0x0018b018 symbol=FUN_0018afb0 lang=c99 */
/* Clone of src/eboot/FUN_0017e8bc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/light_obj.h"

extern CameraPose * DAT_003da704;
extern int FUN_0005c700();
extern void FUN_0005c8e0();
extern void FUN_0018adb4();

/* Apply the light settings, publish the position into the global block and refresh from the sub-object. */
void FUN_0018afb0(LightObj *light)
{
  CameraPose *cam;
  
  FUN_0018adb4();
  cam = DAT_003da704;
  DAT_003da704->pos.x = light->pos.x;
  cam->pos.y = light->pos.y;
  cam->pos.z = light->pos.z;
  cam->pos.w = light->pos.w;
  FUN_0005c8e0(DAT_003da704);
  FUN_0005c700(light->sub10,DAT_003da704);
  return;
}

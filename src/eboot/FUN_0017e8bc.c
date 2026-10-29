/* HSTMATCH module=EBOOT.BIN start=0x0017e8bc end=0x0017e924 symbol=FUN_0017e8bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/light_obj.h"

extern CameraPose * DAT_003313c4;
extern int FUN_0005ba78();
extern void FUN_0005bc58();
extern void FUN_0017e6c0();

/* Apply the light settings, publish the position into the global block and refresh from the sub-object. */
void FUN_0017e8bc(LightObj *light)
{
  CameraPose *cam;
  
  FUN_0017e6c0();
  cam = DAT_003313c4;
  DAT_003313c4->pos.x = light->pos.x;
  cam->pos.y = light->pos.y;
  cam->pos.z = light->pos.z;
  cam->pos.w = light->pos.w;
  FUN_0005bc58(DAT_003313c4);
  FUN_0005ba78(light->sub10,DAT_003313c4);
  return;
}

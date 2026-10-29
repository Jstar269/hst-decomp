/* HSTMATCH module=EBOOT.BIN start=0x0017e598 end=0x0017e654 symbol=FUN_0017e598 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: typed struct with float globals/fields (lwc1/swc1); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/light_obj.h"

extern float DAT_002c2070;
extern float DAT_002c2074;
extern float DAT_002c2078;
extern float DAT_002c207c;
extern u8 DAT_003090d4;
extern CameraPose * DAT_003313c4;
extern int FUN_0005b670();
extern int FUN_0005ba00();
extern int FUN_0005ba78();

/* Constructor: build both sub-objects, set the default position, and seed the camera's look vector. */
LightObj * FUN_0017e598(LightObj *light)
{
  CameraPose *cam;
  u8 temp [LIGHT_SUB_SIZE];
  
  light->vtable = &DAT_003090d4;
  FUN_0005b670(light->sub10);
  FUN_0005b670(light->sub2e0);
  light->pos.x = DAT_002c2070;
  light->pos.y = DAT_002c2074;
  light->pos.z = DAT_002c2078;
  light->pos.w = DAT_002c207c;
  FUN_0005b670(temp);
  FUN_0005ba78(DAT_003313c4,temp);
  cam = DAT_003313c4;
  DAT_003313c4->at.x = 0.0f;
  cam->at.y = 0.0f;
  cam->at.z = -1.0f;
  cam->at.w = 0.0f;
  light->progress = 1.0f;
  light->active = 0;
  FUN_0005ba00(temp,0xffffffff);
  return light;
}

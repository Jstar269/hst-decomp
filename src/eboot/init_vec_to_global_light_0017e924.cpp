/* HSTMATCH module=EBOOT.BIN start=0x0017e924 end=0x0017e9b0 symbol=FUN_0017e924 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/light_obj.h"

/* Light settings; only the value at +8 is read. */
struct Settings_0017e924 {
    char pad0[8];
    float f8;
};
extern "C" {
extern CameraPose *DAT_003313c4;
extern void FUN_0005ba78(void *, CameraPose *);
extern void FUN_0005bc58(CameraPose *);
extern void FUN_0017e6c0(LightObj *, Settings_0017e924 *);
}

/* Apply the light settings, set the light position to (0, f8, 5, 0) and publish it into the global block. */
extern "C" void FUN_0017e924(LightObj *light, Settings_0017e924 *settings)
{
    FUN_0017e6c0(light, settings);
    float height = settings->f8;
    light->pos.x = 0.0f;
    light->pos.y = height;
    light->pos.z = 5.0f;
    light->pos.w = 0.0f;
    CameraPose *cam = DAT_003313c4;
    cam->pos.x = light->pos.x;
    cam->pos.y = light->pos.y;
    cam->pos.z = light->pos.z;
    cam->pos.w = light->pos.w;
    FUN_0005bc58(DAT_003313c4);
    FUN_0005ba78(light->sub10, DAT_003313c4);
}

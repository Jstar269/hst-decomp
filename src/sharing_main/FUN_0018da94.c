/* HSTMATCH module=hstp_trans_main.prx start=0x0018da94 end=0x0018dbb0 symbol=FUN_0018da94 lang=c99 */
/* Clone of src/eboot/FUN_001813a0.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef struct { char pad[4]; short x0; short x1; short y0; short y1; } Rect;
typedef struct { char pad[0x2474]; Rect *rect; } Object;
typedef struct { char pad[0x1d0]; u32 fields[0x11]; } Render;
extern void *DAT_003da704;
extern void *DAT_003ea858;
extern void FUN_0005c85c(void *, float, float, float, float, float, float);
extern void FUN_0005c8e0(Render *);
extern Render *FUN_00185df4(void *);

void FUN_0018da94(Object *self)
{
  Rect *r = self->rect;
  short x = (short)((r->x0 + r->y0) / 2);
  short y = (short)((r->x1 + r->y1) / 2);
  FUN_0005c85c(DAT_003da704, 0.0f, 0.0f, 480.0f, 272.0f,
               (float)x, (float)y);
  Render *obj = FUN_00185df4(DAT_003ea858);
  obj->fields[0x10] = 0xf100;
  obj->fields[0xf] = 0xff10;
  obj->fields[0] = 0;
  obj->fields[1] = 0;
  obj->fields[2] = 0x3f800000;
  obj->fields[3] = 0x3f800000;
  obj->fields[4] = 0;
  obj->fields[5] = 0;
  obj->fields[6] = 0xbf800000;
  obj->fields[7] = 0;
  FUN_0005c85c(obj, 0.0f, 0.0f, 480.0f, 272.0f,
               (float)x, (float)y);
  FUN_0005c8e0(obj);
}

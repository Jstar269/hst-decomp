/* HSTMATCH module=EBOOT.BIN start=0x001813a0 end=0x001814bc symbol=FUN_001813a0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int uint;
typedef struct { char pad[4]; short x0; short x1; short y0; short y1; } Rect;
typedef struct { char pad[0x2474]; Rect *rect; } Object;
typedef struct { char pad[0x1d0]; uint fields[0x11]; } Render;
extern void *DAT_003313c4;
extern void *DAT_00341518;
extern void FUN_0005bbd4(void *, float, float, float, float, float, float);
extern void FUN_0005bc58(Render *);
extern Render *FUN_00179700(void *);

void FUN_001813a0(Object *self)
{
  Rect *r = self->rect;
  short x = (short)((r->x0 + r->y0) / 2);
  short y = (short)((r->x1 + r->y1) / 2);
  FUN_0005bbd4(DAT_003313c4, 0.0f, 0.0f, 480.0f, 272.0f,
               (float)x, (float)y);
  Render *obj = FUN_00179700(DAT_00341518);
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
  FUN_0005bbd4(obj, 0.0f, 0.0f, 480.0f, 272.0f,
               (float)x, (float)y);
  FUN_0005bc58(obj);
}

/* HSTMATCH module=EBOOT.BIN start=0x000ada80 end=0x000adb10 symbol=FUN_000ada80 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Obj { char pad[0x580]; float a; char pad2[0x1c]; float b; };

extern float DAT_003411dc;
extern float DAT_003411d8;

float FUN_000ada80(float x, struct Obj *o, int mode)
{
  float m;
  float v;

  m = o->a * o->b;
  v = x - m;
  switch (mode) {
  case 0:
  case 1:
    break;
  case 2:
    v = v * (DAT_003411d8 * 0.01f);
    break;
  case 3:
  case 4:
    v = v * (DAT_003411dc * 0.01f);
    break;
  }
  return m + v;
}

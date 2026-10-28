/* HSTMATCH module=EBOOT.BIN start=0x001317bc end=0x001318dc symbol=FUN_001317bc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

struct Self { char pad[0x128]; int f128; int f12c; int f130; };
struct Cfg  { char pad[0x50]; int f50; };

extern float DAT_002db1bc;
extern float DAT_002db1c0;
extern float DAT_002db1c4;
extern float DAT_002db1c8;
extern u32 *DAT_003386b0;
extern struct Cfg *DAT_00338b44;

u32 FUN_001317bc(struct Self *param_1,int param_2)
{
  float tbl[4];
  u32 r;
  int off;

  r = 0;
  tbl[0] = DAT_002db1bc;
  tbl[1] = DAT_002db1c0;
  tbl[2] = DAT_002db1c4;
  tbl[3] = DAT_002db1c8;
  switch (param_2) {
  case 5:
    off = param_1->f128 * 4;
    r = *(u32 *)(off + (int)DAT_003386b0 + 0x70);
    break;
  case 6:
    off = param_1->f12c * 4;
    r = *(u32 *)(off + (int)DAT_003386b0 + 0x70);
    break;
  case 7:
    off = DAT_00338b44->f50 * 4;
    r = *(u32 *)(off + (int)DAT_003386b0 + 0x70);
    break;
  case 8:
    off = (int)tbl[DAT_00338b44->f50] * 4;
    r = *(u32 *)(off + (int)DAT_003386b0 + 0x70);
    break;
  case 9:
    off = param_1->f130 * 4;
    r = *(u32 *)(off + (int)DAT_003386b0 + 0x70);
    break;
  }
  return r;
}

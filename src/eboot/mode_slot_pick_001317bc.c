/* HSTMATCH module=EBOOT.BIN start=0x001317bc end=0x001318dc symbol=FUN_001317bc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

struct Self { char pad[0x128]; int unk128; int unk12c; int unk130; };
struct Cfg  { char pad[0x50]; int unk50; };

extern float DAT_002db1bc;
extern float DAT_002db1c0;
extern float DAT_002db1c4;
extern float DAT_002db1c8;
extern u32 *DAT_003386b0;
extern struct Cfg *DAT_00338b44;

/* Returns the entry of the global table at 0x70 indexed by the field chosen by mode (5 to 9), or 0. */
u32 FUN_001317bc(struct Self *self,int mode)
{
  float tbl[4];
  u32 result;
  int off;

  result = 0;
  tbl[0] = DAT_002db1bc;
  tbl[1] = DAT_002db1c0;
  tbl[2] = DAT_002db1c4;
  tbl[3] = DAT_002db1c8;
  switch (mode) {
  case 5:
    off = self->unk128 * 4;
    result = *(u32 *)(off + (int)DAT_003386b0 + 0x70);
    break;
  case 6:
    off = self->unk12c * 4;
    result = *(u32 *)(off + (int)DAT_003386b0 + 0x70);
    break;
  case 7:
    off = DAT_00338b44->unk50 * 4;
    result = *(u32 *)(off + (int)DAT_003386b0 + 0x70);
    break;
  case 8:
    off = (int)tbl[DAT_00338b44->unk50] * 4;
    result = *(u32 *)(off + (int)DAT_003386b0 + 0x70);
    break;
  case 9:
    off = self->unk130 * 4;
    result = *(u32 *)(off + (int)DAT_003386b0 + 0x70);
    break;
  }
  return result;
}

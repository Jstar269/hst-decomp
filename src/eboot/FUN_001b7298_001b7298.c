/* HSTMATCH module=EBOOT.BIN start=0x001b7298 end=0x001b7328 symbol=FUN_001b7298 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/inst_obj.h"

extern int DAT_0034179c;
extern int FUN_001b2af0(int *, int);

void FUN_001b7298(InstObj *self, int mode)
{
  int result = 10;
  int flag = 0;

  if (self->unk90 != 0 && self->unk93 != 0)
    flag = 1;
  switch (mode) {
  case 5:
    result = 9;
    break;
  case 4:
  case 3:
    result = flag ? 9 : 0x18;
    break;
  default:
    break;
  }
  result = FUN_001b2af0(&DAT_0034179c, result);
  self->unk58 = result;
}

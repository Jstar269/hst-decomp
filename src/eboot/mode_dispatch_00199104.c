/* HSTMATCH module=EBOOT.BIN start=0x00199104 end=0x001991cc symbol=FUN_00199104 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/install_flow.h"

extern u8 DAT_00341770;
extern u8 DAT_002e189c;
extern void FUN_001991cc(u8 *, int);
extern void FUN_001991f8(InstallFlow *, int);
extern void FUN_002b7c30(void);
extern int FUN_002b7cd0(void);

/* Per-frame dispatch on the flow mode: in run mode, react to the status the poll returns. */
void FUN_00199104(InstallFlow *self)
{
  int status;

  DAT_00341770 = 0;
  switch (self->mode) {
  case INSTALL_MODE_IDLE:
    break;
  case INSTALL_MODE_RUN:
    status = FUN_002b7cd0();
    if (status != 0) {
      switch (status) {
      case 1:
        break;
      case 2:
        DAT_00341770 = 1;
        break;
      case 3:
        FUN_002b7c30();
        break;
      case 4:
        break;
      default:
        FUN_001991cc(&DAT_002e189c,status);
        break;
      }
    }
    else {
      FUN_001991f8(self,0);
    }
    break;
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x00290c94 end=0x00290da4 symbol=FUN_00290c94 lang=c++ data=0x002ff7a8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002ff7a8-0x002ff830) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/psmf_player.h"

extern bool DAT_0034a80c;
extern char DAT_002ff830[];
extern "C" void FUN_0028fb44(const char *, int);
extern "C" void FUN_002b79b0(int);
extern "C" int FUN_002b7a78(void);
extern "C" int FUN_002b7ea8(void *, int *);
extern "C" int FUN_002b7ec8(void *);
extern "C" int FUN_002b7ee0(void *);


static inline bool Running() { return !DAT_0034a80c; }

/* Video loop: updates the player and fetches video data until the status check fails or the player stops. */
extern "C" int FUN_00290c94(PsmfPlayer *self)
{
  int r;
  int buf[3];
  for (;;) {
    if (!Running()) break;
    r = FUN_002b7ee0(self);
    if (r < 0) { FUN_0028fb44("ERROR: scePsmfPlayerGetCurrentStatus()[2]: 0x%08x\n", r); break; }
    if (r == PSMF_STATUS_STANDBY) break;
    buf[0] = 0x200;
    buf[1] = self->work_buf;
    buf[2] = 0;
    r = FUN_002b7ec8(self);
    if (r != 0) { FUN_0028fb44("ERROR: scePsmfPlayerUpdate(): 0x%08x\n", r); break; }
    r = FUN_002b7ea8(self, buf);
    if (r != (int)0x8061600c && r < 0) { FUN_0028fb44("ERROR: scePsmfPlayerGetVideoData(): 0x%08x\n", r); break; }
    self->unke8 = buf[2];
    r = FUN_002b7a78();
    if (r < 0) { FUN_0028fb44(DAT_002ff830, r); break; }
  }
  FUN_002b79b0(0);
  return 0;
}

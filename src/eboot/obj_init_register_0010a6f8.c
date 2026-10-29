/* HSTMATCH module=EBOOT.BIN start=0x0010a6f8 end=0x0010a7cc symbol=FUN_0010a6f8 lang=c99 data=0x002d8ee4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d8ee4-0x002d8f1a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/utility_params.h"

extern void *FUN_00011090(void *, void *, int);
extern void *FUN_000114c0(void *, int, int);
extern int FUN_0010a4a8(char *, int);
extern void FUN_00199280(void *);
extern int FUN_002b7c48(void *);

/* Net-configuration block together with the ad-hoc parameter it points at. */
struct NetconfObj { NetconfAdhocParam adhoc; NetconfParams cfg; };

/* Start the net-configuration dialog for the given action, optionally with an ad-hoc parameter copied from src. */
int FUN_0010a6f8(struct NetconfObj *o, int action, void *src)
{
  int r;
  FUN_000114c0(&o->cfg, 0, sizeof(NetconfParams));
  o->cfg.base.size = sizeof(NetconfParams);
  o->cfg.base.language = 0;
  o->cfg.base.buttonSwap = 0;
  o->cfg.base.graphicsThread = UTILITY_PRIO_GRAPHICS;
  o->cfg.base.accessThread = UTILITY_PRIO_ACCESS;
  o->cfg.base.fontThread = UTILITY_PRIO_FONT;
  o->cfg.base.soundThread = UTILITY_PRIO_SOUND;
  FUN_00199280(&o->cfg);
  o->cfg.action = action;
  if (src == 0) {
    FUN_000114c0(o, 0, sizeof(NetconfAdhocParam));
  } else {
    FUN_00011090(o, src, sizeof(NetconfAdhocParam));
  }
  o->cfg.adhocParam = &o->adhoc;
  r = FUN_002b7c48(&o->cfg);
  if (r != 0) {
    r = FUN_0010a4a8("ERROR: sceUtilityNetconfInitStart failed. ret = 0x%x\n", r);
  }
  return r;
}

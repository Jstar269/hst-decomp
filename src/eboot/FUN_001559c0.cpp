/* HSTMATCH module=EBOOT.BIN start=0x001559c0 end=0x00155a9c symbol=FUN_001559c0 lang=c++ data=0x002dcb4c */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: modeled the receiver as a virtual object, restored the float input and (float, int) method signature, and used the context pointer for +8 reads; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dcb4c-0x002dcb5d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

extern "C" {
extern unsigned char DAT_003402f0; /* script trace flag */
extern void *DAT_0034a114;
extern unsigned char DAT_003083cc;
extern unsigned char DAT_003085bc;
void *FUN_00000bcc(int);
void FUN_0014d044(ScriptCtx *);
void FUN_0014fd94(char *, int);
void FUN_001cc354(void *, int);
}
struct Allocated {
  virtual ~Allocated();
  virtual int Run(float, ScriptCtx *);
};

/* Script command factory "AppealText": builds the command object and runs it; the object is deleted again when Run reports a failure. */
extern "C" Allocated *FUN_001559c0(ScriptCmd *cmd, float amount, ScriptCtx *ctx)
{
  Allocated *p;
  int result;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("AppealText [%d]\n", cmd->arg0);
  }
  FUN_001cc354(DAT_0034a114, cmd->arg0);
  if ((p = (Allocated *)FUN_00000bcc(4)) != 0) {
    *(void **)p = &DAT_003083cc;
    *(void **)p = &DAT_003085bc;
  }
  result = p->Run(amount, ctx);
  if (result != 0) {
    if (p != 0) {
      delete p;
    }
    return 0;
  }
  return p;
}

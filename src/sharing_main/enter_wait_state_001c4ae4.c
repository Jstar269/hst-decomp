/* HSTMATCH module=hstp_trans_main.prx start=0x001c4ae4 end=0x001c4c28 symbol=FUN_001c4ae4 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/enter_wait_state_001b6e24.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/state_obj.h"

extern StateCtx *DAT_003e1e84;
extern int DAT_003eaad8;
extern int FUN_000e3144(StateCtx *ctx);
extern int FUN_001c0bb0(int *mgr,int kind);
extern void FUN_001c2130(int *mgr,float value);
extern void FUN_001c2280(int *mgr,float a,float b);
extern void FUN_001c2384(int *mgr,float value);
extern void FUN_001c2670(int *mgr,float value);
extern void FUN_001c6408();
extern void FUN_001c64d4(StateObj *obj,int a,int b);
extern void FUN_001c6834(StateObj *obj,u32 event,int arg);

/* Enters the wait state: when the context query returns 0, starts the object and takes a handle (kind 2 or 1,
   depending on which counter is below 2); otherwise sets the flag and runs the sound manager calls. */
void FUN_001c4ae4(StateObj *self)
{
  int status;
  int handle;
  
  FUN_001c6408();
  status = FUN_000e3144(DAT_003e1e84);
  if (status == 0) {
    if (DAT_003e1e84->unka4 < 2) {
      FUN_001c64d4(self,0,0);
      FUN_001c2280(&DAT_003eaad8,0.0f,0.5f);
      handle = FUN_001c0bb0(&DAT_003eaad8,2);
      self->handle54 = handle;
      self->unk84 = self->unk84 + 1;
    }
    else if (DAT_003e1e84->unka0 < 2) {
      FUN_001c64d4(self,0,0);
      FUN_001c2280(&DAT_003eaad8,0.0f,0.5f);
      handle = FUN_001c0bb0(&DAT_003eaad8,1);
      self->handle54 = handle;
      self->unk84 = self->unk84 + 1;
    }
  }
  else {
    self->unk78 = 1;
    FUN_001c2130(&DAT_003eaad8,0.5f);
    FUN_001c2384(&DAT_003eaad8,0.5f);
    FUN_001c2670(&DAT_003eaad8,0.5f);
    FUN_001c6834(self,0x9a,0x18);
  }
}

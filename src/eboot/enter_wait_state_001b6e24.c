/* HSTMATCH module=EBOOT.BIN start=0x001b6e24 end=0x001b6f68 symbol=FUN_001b6e24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a/v4) corrected by hand: corrected helper return and float argument types and used the named data symbol; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/state_obj.h"

extern StateCtx *DAT_00338b44;
extern int DAT_0034179c;
extern int FUN_000def58(StateCtx *ctx);
extern int FUN_001b2af0(int *mgr,int kind);
extern void FUN_001b3ea4(int *mgr,float value);
extern void FUN_001b413c(int *mgr,float a,float b);
extern void FUN_001b4240(int *mgr,float value);
extern void FUN_001b464c(int *mgr,float value);
extern void FUN_001b871c();
extern void FUN_001b87e8(StateObj *obj,int a,int b);
extern void FUN_001b8b48(StateObj *obj,u32 event,int arg);

/* Enters the wait state: when the context query returns 0, starts the object and takes a handle (kind 2 or 1,
   depending on which counter is below 2); otherwise sets the flag and runs the sound manager calls. */
void FUN_001b6e24(StateObj *self)
{
  int status;
  int handle;
  
  FUN_001b871c();
  status = FUN_000def58(DAT_00338b44);
  if (status == 0) {
    if (DAT_00338b44->unka4 < 2) {
      FUN_001b87e8(self,0,0);
      FUN_001b413c(&DAT_0034179c,0.0f,0.5f);
      handle = FUN_001b2af0(&DAT_0034179c,2);
      self->handle54 = handle;
      self->unk84 = self->unk84 + 1;
    }
    else if (DAT_00338b44->unka0 < 2) {
      FUN_001b87e8(self,0,0);
      FUN_001b413c(&DAT_0034179c,0.0f,0.5f);
      handle = FUN_001b2af0(&DAT_0034179c,1);
      self->handle54 = handle;
      self->unk84 = self->unk84 + 1;
    }
  }
  else {
    self->unk78 = 1;
    FUN_001b3ea4(&DAT_0034179c,0.5f);
    FUN_001b4240(&DAT_0034179c,0.5f);
    FUN_001b464c(&DAT_0034179c,0.5f);
    FUN_001b8b48(self,0x9a,0x18);
  }
}

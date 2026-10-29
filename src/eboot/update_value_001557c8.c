/* HSTMATCH module=EBOOT.BIN start=0x001557c8 end=0x00155834 symbol=FUN_001557c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: put the true work in the if body and return false after it. */
#include "hst/types.h"

/* Register reference used by this command: the register number sits at 0x08. */
typedef struct RegRef {
  char pad00[8];
  u32 reg;  /* 0x08 */
} RegRef;

typedef struct Cmd {
  char pad00[4];
  RegRef *src;  /* 0x04 */
} Cmd;

extern void *DAT_0034a114;
extern int *FUN_0014c384(u32, u32);
extern int FUN_001cd190(void *);
extern u32 FUN_001cd29c(void *);

/* Stores the host's value into the register named by the command, unless the host check fails. */
bool FUN_001557c8(Cmd *cmd,u32 *regs)
{
  u32 value;
  u32 *slot;
  u32 bank;
  
  if (FUN_001cd190(DAT_0034a114) == 0) {
    bank = *regs;
    value = FUN_001cd29c(DAT_0034a114);
    slot = (u32 *)FUN_0014c384(bank,cmd->src->reg);
    *slot = value;
    return true;
  }
  return false;
}

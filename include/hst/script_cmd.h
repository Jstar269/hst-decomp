/* Script command handlers of the 0x150000 sources: the command record, the running context and the actor view. */
#ifndef HST_SCRIPT_CMD_H
#define HST_SCRIPT_CMD_H

#include "hst/types.h"

/* Object the context points at; only one flag byte is written. */
typedef struct ScriptActor {
  char pad00[0x5a];
  u8 unk5a;           /* 0x5a */
} ScriptActor;

/* Reference to a script register: the register number sits at 0x0c. */
typedef struct ScriptRegRef {
  char pad00[0xc];
  int reg;            /* 0x0c */
} ScriptRegRef;

/* Command record. The meaning of the arguments depends on the command: for the text commands arg0 is
   the string shown in the trace line and arg1 a register or option number. */
typedef struct ScriptCmd {
  char pad00[4];
  ScriptRegRef *src;  /* 0x04 */
  int arg0;           /* 0x08 */
  int arg1;           /* 0x0c */
  u8 unk10;           /* 0x10 */
} ScriptCmd;

/* Running context passed to every handler. */
typedef struct ScriptCtx {
  u32 regs;           /* 0x00 register bank, indexed through FUN_0014c384 */
  u32 unk04;          /* 0x04 */
  u32 unk08;          /* 0x08 */
  ScriptActor *actor; /* 0x0c */
} ScriptCtx;

#endif

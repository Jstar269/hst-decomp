/* Script command object: only the vtable word is known (the deleting destructors of the command classes use it). */
#ifndef HST_CMD_BASE_H
#define HST_CMD_BASE_H

typedef struct CmdBase {
  const void *vtable;  /* 0x00 */
} CmdBase;

#endif

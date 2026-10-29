/* HSTMATCH module=EBOOT.BIN start=0x0001cb88 end=0x0001cbc8 symbol=FUN_0001cb88 lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); readability pass; exact match verified; names and types await human review. */
/* Clears the loaded, result and +0x100c flags; when the result flag was set it first logs through
   FUN_0001c104. Matching idiom: the flag store is written BEFORE the log call (not after), which is what makes
   MWCC materialise the message address fully before the `jal` and put the store in the delay slot. */
#include "hst/loader_obj.h"

extern char DAT_0030ab9c[];

extern void FUN_0001c104(char *msg);

void FUN_0001cb88(LoaderObj *self)
{
  if (self->result) {
    self->result = 0;
    FUN_0001c104(DAT_0030ab9c);
  }
  self->loaded = 0;
  self->unk100c = 0;
}

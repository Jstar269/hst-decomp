/* HSTMATCH module=EBOOT.BIN start=0x0028686c end=0x00286938 symbol=FUN_0028686c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_actor.h"

extern unsigned char DAT_00309cac;
extern void FUN_000009e4(char *);
extern void FUN_00000a00(CmdActor *);
extern int * FUN_0014c028(void *, int);
extern void FUN_00286cb8(CmdActor *);
extern void FUN_00289434();

/* CmdActor deleting destructor: frees the name, the pair objects and the resource, clears the command list,
   and deletes the actor itself when flag > 0. */
CmdActor * FUN_0028686c(CmdActor *self, short flag)
{
  u32 eraseResult;
  CmdLink *first;
  CmdLink *end;
  char *list;

  if (self != (CmdActor *)0x0) {
    self->vtbl = &DAT_00309cac;
    if (self->name != 0) {
      FUN_000009e4(self->name);
      self->name = 0;
    }
    FUN_00286cb8(self);
    if (self->res != (void *)0x0) {
      FUN_0014c028(self->res,1);
      self->res = 0;
    }
    list = self->alloc64;
    if (((list != (char *)0x0) && (list != (char *)0x0)) && (list != (char *)0x0)) {
      end = &self->head;
      first = self->head.next;
      FUN_00289434(&eraseResult,list,&first,&end);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}

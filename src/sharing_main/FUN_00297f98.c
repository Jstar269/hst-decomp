/* HSTMATCH module=hstp_trans_main.prx start=0x00297f98 end=0x00298064 symbol=FUN_00297f98 lang=c99 */
/* Clone of src/eboot/FUN_0028686c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_actor.h"

extern unsigned char DAT_003b2f94;
extern void FUN_000009e4(char *);
extern void FUN_00000a00(CmdActor *);
extern int * FUN_001579f8(void *, int);
extern void FUN_002983b4(CmdActor *);
extern void FUN_0029abd0();

/* CmdActor deleting destructor: frees the name, the pair objects and the resource, clears the command list,
   and deletes the actor itself when flag > 0. */
CmdActor * FUN_00297f98(CmdActor *self, short flag)
{
  u32 eraseResult;
  CmdLink *first;
  CmdLink *end;
  char *list;

  if (self != (CmdActor *)0x0) {
    self->vtbl = &DAT_003b2f94;
    if (self->name != 0) {
      FUN_000009e4(self->name);
      self->name = 0;
    }
    FUN_002983b4(self);
    if (self->res != (void *)0x0) {
      FUN_001579f8(self->res,1);
      self->res = 0;
    }
    list = self->alloc64;
    if (((list != (char *)0x0) && (list != (char *)0x0)) && (list != (char *)0x0)) {
      end = &self->head;
      first = self->head.next;
      FUN_0029abd0(&eraseResult,list,&first,&end);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}

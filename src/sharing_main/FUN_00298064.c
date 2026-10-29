/* HSTMATCH module=hstp_trans_main.prx start=0x00298064 end=0x002980f8 symbol=FUN_00298064 lang=c99 */
/* Clone of src/eboot/FUN_00286938.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_actor.h"

typedef struct SysGlobals {
  char pad0[0x3c];
  int unk3c;                    /* 0x3c passed to the resource loader */
} SysGlobals;

extern SysGlobals *DAT_003f344c;
extern char DAT_003a78f0[];
extern char *FUN_00000a90(int size);
extern char *FUN_000149a8(char *dst, const char *src);
extern int FUN_00014a40(const char *s);
extern int *FUN_001579f8(void *, int);
extern int FUN_00157c78(void *, char *);
extern void *FUN_0016243c(int, const char *);

/* Replaces the actor's resource by the one loaded from `name` and keeps a copy of the name. */
void FUN_00298064(CmdActor *self, const char *name)
{
  void *res;
  char *copy;
  int len;

  if (self->res != 0) {
    FUN_001579f8(self->res,1);
    self->res = 0;
  }
  res = FUN_0016243c(DAT_003f344c->unk3c,name);
  self->res = res;
  len = FUN_00014a40(name);
  copy = FUN_00000a90(len + 1);
  self->name = copy;
  FUN_000149a8(copy,name);
  if (self->res != 0) {
    self->unk3c = FUN_00157c78(self->res,DAT_003a78f0);
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x00286938 end=0x002869cc symbol=FUN_00286938 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag t0) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_actor.h"

typedef struct SysGlobals {
  char pad0[0x3c];
  int unk3c;                    /* 0x3c passed to the resource loader */
} SysGlobals;

extern SysGlobals *DAT_0034a114;
extern char DAT_002fe9c8[];
extern char *FUN_00000a90(int size);
extern char *FUN_000149a8(char *dst, const char *src);
extern int FUN_00014a40(const char *s);
extern int *FUN_0014c028(void *, int);
extern int FUN_0014c274(void *, char *);
extern void *FUN_00155f34(int, const char *);

/* Replaces the actor's resource by the one loaded from `name` and keeps a copy of the name. */
void FUN_00286938(CmdActor *self, const char *name)
{
  void *res;
  char *copy;
  int len;

  if (self->res != 0) {
    FUN_0014c028(self->res,1);
    self->res = 0;
  }
  res = FUN_00155f34(DAT_0034a114->unk3c,name);
  self->res = res;
  len = FUN_00014a40(name);
  copy = FUN_00000a90(len + 1);
  self->name = copy;
  FUN_000149a8(copy,name);
  if (self->res != 0) {
    self->unk3c = FUN_0014c274(self->res,DAT_002fe9c8);
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x0012de6c end=0x0012e028 symbol=FUN_0012de6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0012de6c.c) corrected by hand: the if/else chain is a switch
   with the 2/3 group written before the 4 case (that is the order MWCC lays the bodies out in), the object's fields are a
   struct, the float-taking setters have their float parameter in signature position, and the pointer table is reached
   through a local int ** so the address add keeps retail's operand order; readability pass; exact match verified; names and types await
   human review. */
#include "hst/stage_obj.h"

extern int DAT_0033b574;  /* table of entry pointers */
extern int DAT_0034a114;
extern char DAT_002bc410[];

extern int FUN_001cd594(int);
extern void FUN_0027be4c(int, int, int);
extern void FUN_00055044(void *, const char *);
extern void FUN_000494d0(void *, float, int, int);
extern void FUN_00058ddc(void *, int, int);
extern void FUN_00058ec4(float, void *, int);
extern void FUN_00058f38(float, void *, int);
extern void FUN_0005f110(void *, float);
extern void FUN_00059084(void *, int);
extern void FUN_0012e7b4(void *, void *);
extern void FUN_0012e898(void *, void *, void *);

/* Entry record reached through the pointer at +0xf8 (only the fields touched here). */
typedef struct Ent {
  char pad[0xc0];
  char unkc0;           /* 0xc0 */
  float unkc4;          /* 0xc4 */
  int pad2[2];
  float unkd0;          /* 0xd0 */
} Ent;

/* Set the mode; for the entry modes prepare the entry chosen by idx, for FORWARD pass idx and arg on to the global object. */
void FUN_0012de6c(StageObj *self, int mode, int idx, int arg)
{
  Ent *e;
  int v;
  void ***t;
  self->mode = mode;
  switch (mode) {
  case STAGE_MODE_ENTRY_A:
  case STAGE_MODE_ENTRY_B:
    t = (void ***)DAT_0033b574;
    self->entry = t[idx + STAGE_ENTRY_TABLE_BASE];
    FUN_00055044(*self->entry, DAT_002bc410);
    FUN_000494d0(self->entry, 65534.0f, 0, 1);
    e = (Ent *)*self->entry;
    FUN_00058ddc(e, 0, -1);
    e->unkc0 = 0;
    e = (Ent *)*self->entry;
    FUN_00058ec4(1.0f, e, -1);
    e->unkc4 = 1.0f;
    e = (Ent *)*self->entry;
    FUN_00058f38(0.0f, e, -1);
    FUN_0005f110(e, 0.0f);
    e = (Ent *)*self->entry;
    FUN_00059084(e, -1);
    e->unkd0 = e->unkc4;
    self->unk240 = 0;
    FUN_0012e7b4(self, self->data100);
    FUN_0012e898(self, self->data150, self->entry);
    break;
  case STAGE_MODE_FORWARD:
    v = FUN_001cd594(DAT_0034a114);
    if (v != 0) {
      v = FUN_001cd594(DAT_0034a114);
      FUN_0027be4c(v, idx, arg);
    }
    break;
  }
  if (mode != STAGE_MODE_FORWARD) {
    v = FUN_001cd594(DAT_0034a114);
    if (v != 0) {
      v = FUN_001cd594(DAT_0034a114);
      *(char *)(v + 100) = 0;
    }
  }
}

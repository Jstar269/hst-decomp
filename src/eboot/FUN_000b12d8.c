/* HSTMATCH module=EBOOT.BIN start=0x000b12d8 end=0x000b13c4 symbol=FUN_000b12d8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/root_state.h"
#include "hst/session_ctx.h"

/* Record of floats: two 4-float groups, two scalars and a trailing word. */
typedef struct FloatRec {
  float groupA[4]; /* 0x00 */
  float groupB[4]; /* 0x10 */
  float unk20;     /* 0x20 */
  float scalarA;   /* 0x24 */
  float scalarB;   /* 0x28 */
  int word;        /* 0x2c */
} FloatRec;

typedef struct Owner {
  char pad0[0x144];
  int unk144; /* 0x144 */
  int unk148; /* 0x148 */
} Owner;

extern RootState *DAT_003386b0;
extern SessionCtx *DAT_00338b44;
extern void FUN_00090144(void *, float *, float *, float, float, int *, int);
extern void FUN_000c8708(void *, int);
extern void FUN_001178f0(int, const float *, int, int);
/* Stack frame layout of the temporaries handed to the callee. */
struct Temps { float groupB[4]; float groupA[4]; int padding[3]; int word; };

void FUN_000b12d8(Owner *self, const FloatRec *rec)
{
  struct Temps temps;
  float scalarA;
  float scalarB;
  int enabled;
  temps.groupA[0] = rec->groupA[0];
  temps.groupA[1] = rec->groupA[1];
  temps.groupA[2] = rec->groupA[2];
  temps.groupA[3] = rec->groupA[3];
  temps.groupB[0] = rec->groupB[0];
  temps.groupB[1] = rec->groupB[1];
  temps.groupB[2] = rec->groupB[2];
  temps.groupB[3] = rec->groupB[3];
  scalarA = rec->scalarA;
  scalarB = rec->scalarB;
  temps.word = rec->word;
  FUN_00090144(DAT_003386b0->unk88, temps.groupA, temps.groupB, scalarA, scalarB, &temps.word, self->unk144);
  FUN_000c8708(DAT_003386b0->unk90, self->unk148);
  if (DAT_003386b0->mode != ROOT_MODE_SPECIAL) {
    enabled = !!DAT_00338b44->unk5c;
    FUN_001178f0(DAT_003386b0->unk9c, (const float *)rec, enabled ^ 1, 0);
  }
}

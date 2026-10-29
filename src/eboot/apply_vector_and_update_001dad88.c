/* HSTMATCH module=EBOOT.BIN start=0x001dad88 end=0x001dadf4 symbol=FUN_001dad88 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the float vector and helper argument order; readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Ctx {
  char pad00[0x5bc];
  int handle;       /* 0x5bc, passed to the vector lookup */
} Ctx;

extern u32 DAT_003386b0;
extern Ctx *FUN_0008882c(u32);
extern float *FUN_00093838(int);
extern void FUN_001daeb4(float, void *, const float *);
extern void FUN_001db1ec(void *);

/* Copy the looked-up four-float vector, apply it to the object, then update the object. */
void FUN_001dad88(void *obj)
{
  Ctx *ctx = FUN_0008882c(DAT_003386b0);
  float *source = FUN_00093838(ctx->handle);
  float vec[4];
  vec[0] = source[0];
  vec[1] = source[1];
  vec[2] = source[2];
  vec[3] = source[3];
  FUN_001daeb4(0.0f, obj, vec);
  FUN_001db1ec(obj);
}

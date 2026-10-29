/* HSTMATCH module=EBOOT.BIN start=0x0009044c end=0x000904dc symbol=FUN_0009044c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct ModeHost {
  char pad00[0x3c];
  int mode;           /* 0x3c */
} ModeHost;

typedef struct FlagRec {
  char pad00[0x78];
  u8 unk78;           /* 0x78 */
} FlagRec;

typedef struct FlagHolder {
  char pad00[0x80];
  FlagRec *rec;       /* 0x80 */
} FlagHolder;

typedef struct PairObj {
  char pad00[0x238];
  u32 unk238;         /* 0x238 */
  u32 unk23c;         /* 0x23c */
} PairObj;

enum { MODE_A = 4, MODE_B = 5, MODE_C = 7 }; /* modes in which the helper runs (MODE_C only while the flag byte is clear) */

extern ModeHost *DAT_003386b0;
extern FlagHolder *DAT_00340284;
extern int FUN_000904dc();
extern void FUN_000b1610();

void FUN_0009044c(PairObj *self,u32 arg)
{
  u32 result;
  int mode;
  
  mode = DAT_003386b0->mode;
  if (((mode == MODE_A) || (mode == MODE_B)) ||
     ((mode == MODE_C && (DAT_00340284->rec->unk78 == '\0')))) {
    result = FUN_000904dc(self);
    FUN_000b1610(result,arg,self->unk238,self->unk23c);
  }
}

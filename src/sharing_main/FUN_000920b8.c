/* HSTMATCH module=hstp_trans_main.prx start=0x000920b8 end=0x00092148 symbol=FUN_000920b8 lang=c99 */
/* Clone of src/eboot/FUN_0009044c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern ModeHost *DAT_003e19f0;
extern FlagHolder *DAT_003e95c4;
extern int FUN_00092148();
extern void FUN_000b45fc();

void FUN_000920b8(PairObj *self,u32 arg)
{
  u32 result;
  int mode;
  
  mode = DAT_003e19f0->mode;
  if (((mode == MODE_A) || (mode == MODE_B)) ||
     ((mode == MODE_C && (DAT_003e95c4->rec->unk78 == '\0')))) {
    result = FUN_00092148(self);
    FUN_000b45fc(result,arg,self->unk238,self->unk23c);
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x001240fc end=0x00124238 symbol=FUN_001240fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v1) corrected by hand: float globals, byte flag, and mode branch; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_owner.h"

typedef struct BlendState {
  char pad0[0x48];
  int unk48;               /* 0x48 */
  char pad4c[0x54 - 0x4c];
  void *unk54;             /* 0x54 object passed to the reset call */
  int unk58;               /* 0x58 */
  char pad5c[4];
  int unk60;               /* 0x60 */
  float unk64;             /* 0x64 */
  char pad68[0x78 - 0x68];
  unsigned char unk78;     /* 0x78 */
  char pad79[0x90 - 0x79];
  int unk90;               /* 0x90 */
} BlendState;

typedef struct IndexBlock {
  char pad0[0x128];
  int index;               /* 0x128 */
  int value;               /* 0x12c */
} IndexBlock;

extern int DAT_002da1ac;
extern float DAT_002da1cc;
extern float DAT_002da1d0;
extern float DAT_002da1d4;
extern float DAT_002da1d8;
extern unsigned char DAT_003386b8;
extern ActiveOwner * DAT_00338ac4;
extern IndexBlock * DAT_00340284;
extern void FUN_0001f1fc();
extern int FUN_001252fc();
extern void FUN_001258bc();
extern signed char * FUN_00132124();
extern void FUN_00216208();

void FUN_001240fc(BlendState *self,int selectA,int selectB)
{
  int idx;
  float picked;
  float table [4];
  int outId;
  
  self->unk60 = 0;
  self->unk64 = 0;
  FUN_00216208(self->unk54);
  idx = 0;
  table[0] = DAT_002da1cc;
  table[1] = DAT_002da1d0;
  table[2] = DAT_002da1d4;
  table[3] = DAT_002da1d8;
  if (DAT_003386b8 != 0) {
    if (DAT_00338ac4 != 0) {
      idx = DAT_00338ac4->slotIndex;
    }
  }
  DAT_00340284->index = idx;
  picked = table[idx];
  idx = 400;
  DAT_00340284->value = (int)picked;
  if (selectA != 0) {
    idx = 500;
  }
  else if (selectB != 0) {
    idx = 600;
  }
  FUN_00132124(idx,&outId);
  idx = FUN_001252fc(self,outId);
  self->unk58 = -1;
  FUN_001258bc(self,idx);
  DAT_002da1ac = idx;
  self->unk90 = 1;
  self->unk64 = 1.0f;
  FUN_0001f1fc(self,1);
  self->unk78 = 1;
  return;
}

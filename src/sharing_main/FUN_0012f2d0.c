/* HSTMATCH module=hstp_trans_main.prx start=0x0012f2d0 end=0x0012f40c symbol=FUN_0012f2d0 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/FUN_001240fc_001240fc.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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

extern int DAT_0038118c;
extern float DAT_003811ac;
extern float DAT_003811b0;
extern float DAT_003811b4;
extern float DAT_003811b8;
extern unsigned char DAT_003e19f8;
extern ActiveOwner * DAT_003e1e04;
extern IndexBlock * DAT_003e95c4;
extern void FUN_0001ef14();
extern int FUN_001304d0();
extern void FUN_00130af0();
extern signed char * FUN_0013d6dc();
extern void FUN_0022520c();

void FUN_0012f2d0(BlendState *self,int selectA,int selectB)
{
  int idx;
  float picked;
  float table [4];
  int outId;
  
  self->unk60 = 0;
  self->unk64 = 0;
  FUN_0022520c(self->unk54);
  idx = 0;
  table[0] = DAT_003811ac;
  table[1] = DAT_003811b0;
  table[2] = DAT_003811b4;
  table[3] = DAT_003811b8;
  if (DAT_003e19f8 != 0) {
    if (DAT_003e1e04 != 0) {
      idx = DAT_003e1e04->slotIndex;
    }
  }
  DAT_003e95c4->index = idx;
  picked = table[idx];
  idx = 400;
  DAT_003e95c4->value = (int)picked;
  if (selectA != 0) {
    idx = 500;
  }
  else if (selectB != 0) {
    idx = 600;
  }
  FUN_0013d6dc(idx,&outId);
  idx = FUN_001304d0(self,outId);
  self->unk58 = -1;
  FUN_00130af0(self,idx);
  DAT_0038118c = idx;
  self->unk90 = 1;
  self->unk64 = 1.0f;
  FUN_0001ef14(self,1);
  self->unk78 = 1;
  return;
}

/* HSTMATCH module=EBOOT.BIN start=0x000ba2a8 end=0x000ba3ac symbol=FUN_000ba2a8 lang=c99 data=0x002d4ab4 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_000ba2a8.c) corrected by hand: inverted the create-result branch; readability pass; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002d4ab4-0x002d4b0a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/adhoc_net.h"

extern u8 DAT_003073f0;
extern u32 * FUN_000114c0();
extern void FUN_000ba3ac();
extern void FUN_000bb9d4();
extern int FUN_002b7890();

/* Constructor: clears the service object and creates its semaphore. */
AdhocNet * FUN_000ba2a8(AdhocNet *self)
{
  int sema;
  int i;
  
  self->vtable = &DAT_003073f0;
  self->unk44 = 0;
  self->unk48 = 0;
  self->unk4c = 0;
  self->unk50 = 0;
  self->unk54 = 0;
  self->unk178 = 0;
  self->matchingId = -1;
  self->unk17c = -1;
  self->unk198 = -1;
  self->unk270 = 0;
  self->unk284 = 0;
  FUN_000bb9d4();
  self->sema = -1;
  sema = FUN_002b7890("AdhocSema",0,1,1,0);
  if (sema > 0) {
    self->sema = sema;
    FUN_000ba3ac("sceKernelCreateSema() success\n");
    self->unk26c = 0;
  } else {
    FUN_000ba3ac("sceKernelCreateSema() failed. ret = 0x%x\n",sema);
    self->unk26c = 0;
  }
  for (i = 0; i < ADHOC_SLOT_COUNT; i++) {
    self->slotAux[i] = 0;
  }
  self->unk278 = 0;
  FUN_000114c0(self->unk27c,0,8);
  return self;
}

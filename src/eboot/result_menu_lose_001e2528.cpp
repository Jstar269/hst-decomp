/* HSTMATCH module=EBOOT.BIN start=0x001e2528 end=0x001e25c0 symbol=FUN_001e2528 lang=c++ data=0x002ec020 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ec020-0x002ec04b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/result_screen.h"

extern "C" void FUN_00104118(void *a, const char *b, int c);
extern "C" void FUN_00103540(void *a, float x);
extern "C" void FUN_001037c8(void *a, int b);
extern "C" void FUN_00216e90(void *a, void *b, const void *c, int d);
extern "C" void FUN_00216f14(void *a, void *b, const void *c, int d);
extern "C" void FUN_00103628(void *a, int b);
extern "C" void FUN_00217704(void *a, void *b);
extern char DAT_002ebc84[];
extern char DAT_002c87bc[];

extern "C" void FUN_001e2528(ResultScreen *self)
{
  FUN_00104118(self->lose_lay, "data/menu/result/result_rank/losebglay.lay", 0);
  FUN_00103540(self->lose_lay, 2800.0f);
  FUN_001037c8(self->lose_lay, -266);
  FUN_00216e90(&self->unk2510, self->lose_lay, DAT_002ebc84, 1);
  FUN_00216f14(self->unk2514, &self->unk2510, DAT_002c87bc, 1);
  FUN_00103628(self->lose_lay, 1);
  FUN_00217704(self->unk252c, self->unk2510);
}

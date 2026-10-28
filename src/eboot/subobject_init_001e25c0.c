/* HSTMATCH module=EBOOT.BIN start=0x001e25c0 end=0x001e2668 symbol=FUN_001e25c0 lang=c99 data=0x002ec04c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ec04c-0x002ec07c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/result_screen.h"

extern void FUN_00104118(void *a0, void *a1, int a2);
extern void FUN_00103540(void *a0, float f12);
extern void FUN_001037c8(void *a0, int a1);
extern void FUN_00216e90(void *a0, void *a1, void *a2, int a3);
extern void FUN_00216f14(void *a0, void *a1, void *a2, int a3);
extern void FUN_00103628(void *a0, int a1);
extern void FUN_00217778(void *a0, void *a1);
extern void FUN_00217614(void *a0, void *a1);

extern char DAT_002ebcb0[];
extern char DAT_002c87e0[];

void FUN_001e25c0(ResultScreen *self)
{
    FUN_00104118(self->overlay_lay, "data/menu/result/result_main/result_overlay.lay", 0);
    FUN_00103540(self->overlay_lay, 3100.0f);
    FUN_001037c8(self->overlay_lay, -1);
    FUN_00216e90(self->unk25bc, self->overlay_lay, DAT_002ebcb0, 5);
    FUN_00216f14(self->unk25d0, self->unk25bc, DAT_002c87e0, 0x17);
    FUN_00103628(self->overlay_lay, 1);
    FUN_00217778(self->unk279c, self->overlay_lay);
    FUN_00217614(self->unk2828, self->unk25f8);
}

/* HSTMATCH module=EBOOT.BIN start=0x001e23ac end=0x001e248c symbol=FUN_001e23ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/result_screen.h"

extern "C" char DAT_002ebfbc;
extern "C" char DAT_002ebc68;
extern "C" char DAT_002c85c4;
extern "C" char DAT_002c8750;
extern "C" char DAT_002c8774;

extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" void FUN_00216e90(void *, void *, void *, int);
extern "C" void FUN_00216f14(void *, void *, void *, int);
extern "C" void FUN_00216fb0(void *, void *, void *, int);
extern "C" void FUN_00217188(void *, void *, void *);
extern "C" void FUN_00217778(void *, void *);

/* Build the exhibition page: load its layout, attach the child objects and cache a value from the 0x2458 object. */
extern "C" void FUN_001e23ac(ResultScreen *self) {
    ResultObj *obj;
    FUN_00104118(self->exhibition_lay, &DAT_002ebfbc, 0);
    FUN_00103540(self->exhibition_lay, 2900.0f);
    FUN_001037c8(self->exhibition_lay, -256);
    FUN_00216e90(self->unk2360, self->exhibition_lay, &DAT_002ebc68, 1);
    FUN_00216f14(self->unk2364, self->unk2360, &DAT_002c85c4, 12);
    FUN_00216fb0(self->unk2454, self->unk2360, &DAT_002c8750, 1);
    FUN_00217188(&self->unk2460, self->unk2360, &DAT_002c8774);
    obj = self->unk2460;
    obj->unkd8 = 0;
    obj->unk114 = 1;
    FUN_00217778(self->unk22c4, self->exhibition_lay);
    self->unk2358 = (int)self->unk2458->unk64;
}

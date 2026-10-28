/* HSTMATCH module=EBOOT.BIN start=0x001e22cc end=0x001e23ac symbol=FUN_001e22cc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/result_screen.h"

extern "C" char DAT_002ebf88;
extern "C" char DAT_002ebc5c;
extern "C" char DAT_002c8430;
extern "C" char DAT_002c857c;
extern "C" char DAT_002c85a0;

extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" void FUN_00216e90(void *, void *, void *, int);
extern "C" void FUN_00216f14(void *, void *, void *, int);
extern "C" void FUN_00216fb0(void *, void *, void *, int);
extern "C" void FUN_00217188(void *, void *, void *);
extern "C" void FUN_00217778(void *, void *);

/* Build the return page: load its layout, attach the child objects and cache a value from the 0x22b8 object. */
extern "C" void FUN_001e22cc(ResultScreen *self) {
    ResultObj *obj;
    FUN_00104118(self->return_lay, &DAT_002ebf88, 0);
    FUN_00103540(self->return_lay, 2900.0f);
    FUN_001037c8(self->return_lay, -256);
    FUN_00216e90(self->unk21e8, self->return_lay, &DAT_002ebc5c, 1);
    FUN_00216f14(self->unk21ec, self->unk21e8, &DAT_002c8430, 10);
    FUN_00216fb0(self->unk22b4, self->unk21e8, &DAT_002c857c, 1);
    FUN_00217188(&self->unk22c0, self->unk21e8, &DAT_002c85a0);
    obj = self->unk22c0;
    obj->unkd8 = 0;
    obj->unk114 = 1;
    FUN_00217778(self->unk22c4, self->return_lay);
    self->unk2358 = (int)self->unk22b8->unk64;
}

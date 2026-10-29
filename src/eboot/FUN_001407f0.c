/* HSTMATCH module=EBOOT.BIN start=0x001407f0 end=0x00140acc symbol=FUN_001407f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/xform_host.h"

extern u8 DAT_00308244;
extern void FUN_00000788();
extern void FUN_00000a00();
extern int * FUN_00049350();
extern int * FUN_0005f688();
extern int * FUN_000e88e4();
extern void FUN_00140d58();
extern int * FUN_001466dc();
extern int * FUN_00146788();
extern int * FUN_001468e4();
extern int * FUN_00146990();
extern int * FUN_00146adc();
extern int * FUN_00146ce0();
extern int * FUN_00147188();
extern int * FUN_001472c8();
extern int * FUN_00147384();
extern int * FUN_001474d0();
extern int * FUN_0014757c();
extern void FUN_00132390();
extern void FUN_00140770();

/* Destroys the sub-objects in reverse order; deletes the object itself when flag > 0. */
XformHost * FUN_001407f0(XformHost *self, short flag)
{
  void *sub;

  if (self != 0) {
    self->vtable = &DAT_00308244;
    FUN_00140d58();
    sub = (void *)&self->entries;
    if (sub != 0 && sub != 0) {
      FUN_0014757c(sub, 0);
    }
    sub = (void *)&self->subc04;
    if (sub != 0 && sub != 0) {
      FUN_001474d0(sub, 0);
    }
    sub = (void *)&self->subaf8;
    if (sub != 0 && sub != 0) {
      FUN_001474d0(sub, 0);
    }
    sub = (void *)&self->sub9ec;
    if (sub != 0 && sub != 0) {
      FUN_001474d0(sub, 0);
    }
    sub = (void *)&self->sub8e0;
    if (sub != 0 && sub != 0) {
      FUN_00147384(sub, 0);
    }
    sub = (void *)&self->sub8d4;
    if (sub != 0 && sub != 0) {
      FUN_001472c8(sub, 0);
    }
    sub = (void *)&self->sub8c8;
    if (sub != 0 && sub != 0) {
      FUN_00147188(sub, 0);
    }
    sub = (void *)&self->sub7bc;
    if (sub != 0 && sub != 0) {
      FUN_00146ce0(sub, 0);
    }
    sub = (void *)&self->sub7b0;
    if (sub != 0 && sub != 0) {
      FUN_000e88e4(sub, 0);
    }
    sub = (void *)&self->sub7a4;
    if (sub != 0 && sub != 0) {
      FUN_00146adc(sub, 0);
    }
    FUN_00049350(self->sub160, 0xffffffff);
    sub = (void *)&self->sub154;
    if (sub != 0 && sub != 0) {
      FUN_00146990(sub, 0);
    }
    sub = (void *)&self->sub148;
    if (sub != 0 && sub != 0) {
      FUN_001468e4(sub, 0);
    }
    sub = (void *)&self->sub13c;
    if (sub != 0 && sub != 0) {
      FUN_001468e4(sub, 0);
    }
    sub = (void *)&self->sub130;
    if (sub != 0 && sub != 0) {
      FUN_001468e4(sub, 0);
    }
    sub = (void *)&self->sub124;
    if (sub != 0 && sub != 0) {
      FUN_001468e4(sub, 0);
    }
    sub = (void *)&self->sub118;
    if (sub != 0 && sub != 0) {
      FUN_001468e4(sub, 0);
    }
    FUN_00000788(self->arrd0, FUN_00132390, 0xc, 6);
    FUN_00000788(self->arr88, FUN_00140770, 0xc, 6);
    FUN_00000788(self->arr40, FUN_00132390, 0xc, 6);
    sub = (void *)&self->sub34;
    if (sub != 0 && sub != 0) {
      FUN_0005f688(sub, 0);
    }
    sub = (void *)&self->sub28;
    if (sub != 0 && sub != 0) {
      FUN_00146788(sub, 0);
    }
    sub = (void *)&self->sub1c;
    if (sub != 0 && sub != 0) {
      FUN_001466dc(sub, 0);
    }
    sub = (void *)&self->sub10;
    if (sub != 0 && sub != 0) {
      FUN_001466dc(sub, 0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}

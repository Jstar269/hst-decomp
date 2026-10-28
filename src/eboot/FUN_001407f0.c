/* HSTMATCH module=EBOOT.BIN start=0x001407f0 end=0x00140acc symbol=FUN_001407f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

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

u32 * FUN_001407f0(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00308244);
    FUN_00140d58();
    puVar1 = param_1 + 0x344;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0014757c(puVar1,0);
    }
    puVar1 = param_1 + 0x301;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001474d0(puVar1,0);
    }
    puVar1 = param_1 + 0x2be;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001474d0(puVar1,0);
    }
    puVar1 = param_1 + 0x27b;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001474d0(puVar1,0);
    }
    puVar1 = param_1 + 0x238;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00147384(puVar1,0);
    }
    puVar1 = param_1 + 0x235;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001472c8(puVar1,0);
    }
    puVar1 = param_1 + 0x232;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00147188(puVar1,0);
    }
    puVar1 = param_1 + 0x1ef;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00146ce0(puVar1,0);
    }
    puVar1 = param_1 + 0x1ec;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_000e88e4(puVar1,0);
    }
    puVar1 = param_1 + 0x1e9;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00146adc(puVar1,0);
    }
    FUN_00049350(param_1 + 0x58,0xffffffff);
    puVar1 = param_1 + 0x55;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00146990(puVar1,0);
    }
    puVar1 = param_1 + 0x52;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001468e4(puVar1,0);
    }
    puVar1 = param_1 + 0x4f;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001468e4(puVar1,0);
    }
    puVar1 = param_1 + 0x4c;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001468e4(puVar1,0);
    }
    puVar1 = param_1 + 0x49;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001468e4(puVar1,0);
    }
    puVar1 = param_1 + 0x46;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001468e4(puVar1,0);
    }
    FUN_00000788(param_1 + 0x34,FUN_00132390,0xc,6);
    FUN_00000788(param_1 + 0x22,FUN_00140770,0xc,6);
    FUN_00000788(param_1 + 0x10,FUN_00132390,0xc,6);
    puVar1 = param_1 + 0xd;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_0005f688(puVar1,0);
    }
    puVar1 = param_1 + 10;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00146788(puVar1,0);
    }
    puVar1 = param_1 + 7;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001466dc(puVar1,0);
    }
    puVar1 = param_1 + 4;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001466dc(puVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

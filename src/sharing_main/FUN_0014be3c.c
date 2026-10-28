/* HSTMATCH module=hstp_trans_main.prx start=0x0014be3c end=0x0014c118 symbol=FUN_0014be3c lang=c99 */
/* Clone of src/eboot/FUN_001407f0.c (hstclone.py tag c28): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b1510;
extern void FUN_00000788();
extern void FUN_00000a00();
extern int * FUN_00049200();
extern int * FUN_00060478();
extern int * FUN_000ed9b8();
extern void FUN_0014c3a4();
extern int * FUN_00151fc4();
extern int * FUN_00152070();
extern int * FUN_001521cc();
extern int * FUN_00152278();
extern int * FUN_001523c4();
extern int * FUN_001525c8();
extern int * FUN_00152a70();
extern int * FUN_00152bb0();
extern int * FUN_00152c6c();
extern int * FUN_00152db8();
extern int * FUN_00152e64();
extern void FUN_0013d980();
extern void FUN_0014bdbc();

u32 * FUN_0014be3c(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b1510);
    FUN_0014c3a4();
    puVar1 = param_1 + 0x344;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00152e64(puVar1,0);
    }
    puVar1 = param_1 + 0x301;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00152db8(puVar1,0);
    }
    puVar1 = param_1 + 0x2be;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00152db8(puVar1,0);
    }
    puVar1 = param_1 + 0x27b;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00152db8(puVar1,0);
    }
    puVar1 = param_1 + 0x238;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00152c6c(puVar1,0);
    }
    puVar1 = param_1 + 0x235;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00152bb0(puVar1,0);
    }
    puVar1 = param_1 + 0x232;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00152a70(puVar1,0);
    }
    puVar1 = param_1 + 0x1ef;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001525c8(puVar1,0);
    }
    puVar1 = param_1 + 0x1ec;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_000ed9b8(puVar1,0);
    }
    puVar1 = param_1 + 0x1e9;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001523c4(puVar1,0);
    }
    FUN_00049200(param_1 + 0x58,0xffffffff);
    puVar1 = param_1 + 0x55;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00152278(puVar1,0);
    }
    puVar1 = param_1 + 0x52;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001521cc(puVar1,0);
    }
    puVar1 = param_1 + 0x4f;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001521cc(puVar1,0);
    }
    puVar1 = param_1 + 0x4c;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001521cc(puVar1,0);
    }
    puVar1 = param_1 + 0x49;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001521cc(puVar1,0);
    }
    puVar1 = param_1 + 0x46;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_001521cc(puVar1,0);
    }
    FUN_00000788(param_1 + 0x34,FUN_0013d980,0xc,6);
    FUN_00000788(param_1 + 0x22,FUN_0014bdbc,0xc,6);
    FUN_00000788(param_1 + 0x10,FUN_0013d980,0xc,6);
    puVar1 = param_1 + 0xd;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00060478(puVar1,0);
    }
    puVar1 = param_1 + 10;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00152070(puVar1,0);
    }
    puVar1 = param_1 + 7;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00151fc4(puVar1,0);
    }
    puVar1 = param_1 + 4;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_00151fc4(puVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

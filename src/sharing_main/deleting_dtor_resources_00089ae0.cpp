/* HSTMATCH module=hstp_trans_main.prx start=0x00089ae0 end=0x00089d58 symbol=FUN_00089ae0 lang=c++ */
/* Clone of src/eboot/deleting_dtor_resources_00088388.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a6, variant v18c) corrected by hand: merged else-branches split back into independent null-checked blocks, the array global read once into a local, the callee prototyped with a float parameter, loop counter declared before the walking pointer; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00089d58;
extern u8 DAT_00089db8;
extern u8 DAT_00089e18;
extern u8 DAT_00089ecc;
extern u8 DAT_0024492c;
extern u8 DAT_003b04a4;
extern u32 DAT_003ba2c4;
extern u32 DAT_003e19f0;
extern u32 DAT_003e1a0c;
extern u32 DAT_003e1a54;
extern void *DAT_003e1df0;
extern u32 DAT_003f39d8;
extern u32 DAT_003f39dc;
extern u32 DAT_003f39e0;
extern u32 DAT_003f39e4;
extern u32 DAT_003f39e8;
extern u32 DAT_003f3b18;
extern void FUN_000006e8(...);
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern u32 * FUN_0001ed28(...);
extern void FUN_000429c8(...);
extern int FUN_000541d8(...);
extern int FUN_0005c688(...);
extern int * FUN_0005e634(...);
extern void FUN_0006f5ec(float);
extern void FUN_000c8b94(...);
extern int FUN_002bd6a8(...);
extern void FUN_00089f2c(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" u32 * FUN_00089ae0(u32 *param_1,short param_2)
{
  int *piVar1;
  unsigned uVar4;
  u32 *puVar3;
  void *p;

  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b04a4);
    uVar4 = 0;
    puVar3 = param_1;
    do {
      piVar1 = (int *)puVar3[0x1c];
      if (piVar1 != (int *)0x0) {
        delete ((VC_0 *)(piVar1));
        puVar3[0x1c] = 0;
      }
      uVar4 = uVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar4 < 4);
    FUN_0006f5ec(2000.0f);
    FUN_000c8b94();
    if ((int *)param_1[0x21] != (int *)0x0) {
      FUN_0005e634((int *)param_1[0x21],1);
      param_1[0x21] = 0;
    }
    if (param_1[0x20] != 0) {
      FUN_000541d8(param_1[0x20],1);
      param_1[0x20] = 0;
    }
    p = DAT_003e1df0;
    if (p != 0) {
      if (p != 0) {
        FUN_00000788(p,FUN_00089f2c,0xc,2);
        FUN_00000a00(p);
      }
      DAT_003e1df0 = 0;
    }
    if (DAT_003f3b18 != 0) {
      FUN_000006e8(DAT_003f3b18,(int)&DAT_00089ecc);
      DAT_003f3b18 = 0;
    }
    if (DAT_003f39d8 != 0) {
      FUN_000006e8(DAT_003f39d8,(int)&DAT_0024492c);
      DAT_003f39d8 = 0;
    }
    if (DAT_003f39dc != 0) {
      FUN_000006e8(DAT_003f39dc,(int)&DAT_0024492c);
      DAT_003f39dc = 0;
    }
    if (DAT_003f39e0 != 0) {
      FUN_000006e8(DAT_003f39e0,(int)&DAT_00089e18);
      DAT_003f39e0 = 0;
    }
    if (DAT_003f39e4 != 0) {
      FUN_000006e8(DAT_003f39e4,(int)&DAT_00089db8);
      DAT_003f39e4 = 0;
    }
    if (DAT_003f39e8 != 0) {
      FUN_000006e8(DAT_003f39e8,(int)&DAT_00089d58);
      DAT_003f39e8 = 0;
    }
    if (param_1[0x29] != 0) {
      FUN_002bd6a8(param_1[0x29],1);
      param_1[0x29] = 0;
    }
    if (DAT_003e1a54 != 0) {
      FUN_0005c688(DAT_003e1a54,1);
      DAT_003e1a54 = 0;
    }
    if (DAT_003e1a0c != 0) {
      FUN_0005c688(DAT_003e1a0c,1);
      DAT_003e1a0c = 0;
    }
    FUN_000429c8(DAT_003ba2c4);
    DAT_003e19f0 = 0;
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

/* HSTMATCH module=EBOOT.BIN start=0x00088388 end=0x00088600 symbol=FUN_00088388 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6, variant v18c) corrected by hand: merged else-branches split back into independent null-checked blocks, the array global read once into a local, the callee prototyped with a float parameter, loop counter declared before the walking pointer; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
typedef unsigned char undefined;

extern "C" {
extern undefined DAT_00088600;
extern undefined DAT_00088660;
extern undefined DAT_000886c0;
extern undefined DAT_00088774;
extern undefined DAT_00234800;
extern undefined DAT_003071d8;
extern undefined4 DAT_00310fc4;
extern undefined4 DAT_003386b0;
extern undefined4 DAT_003386cc;
extern undefined4 DAT_00338714;
extern void *DAT_00338ab0;
extern undefined4 DAT_0034a6a8;
extern undefined4 DAT_0034a6ac;
extern undefined4 DAT_0034a6b0;
extern undefined4 DAT_0034a6b4;
extern undefined4 DAT_0034a6b8;
extern undefined4 DAT_0034a7e8;
extern void FUN_000006e8(...);
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001f0f0(...);
extern void FUN_000429a0(...);
extern int FUN_00053718(...);
extern int FUN_0005ba00(...);
extern int * FUN_0005d818(...);
extern void FUN_0006df50(float);
extern void FUN_000c5110(...);
extern int FUN_002ade80(...);
extern void FUN_000887d4(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_00088388(undefined4 *param_1,short param_2)
{
  int *piVar1;
  unsigned uVar4;
  undefined4 *puVar3;
  void *p;

  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003071d8);
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
    FUN_0006df50(2000.0f);
    FUN_000c5110();
    if ((int *)param_1[0x21] != (int *)0x0) {
      FUN_0005d818((int *)param_1[0x21],1);
      param_1[0x21] = 0;
    }
    if (param_1[0x20] != 0) {
      FUN_00053718(param_1[0x20],1);
      param_1[0x20] = 0;
    }
    p = DAT_00338ab0;
    if (p != 0) {
      if (p != 0) {
        FUN_00000788(p,FUN_000887d4,0xc,2);
        FUN_00000a00(p);
      }
      DAT_00338ab0 = 0;
    }
    if (DAT_0034a7e8 != 0) {
      FUN_000006e8(DAT_0034a7e8,(int)&DAT_00088774);
      DAT_0034a7e8 = 0;
    }
    if (DAT_0034a6a8 != 0) {
      FUN_000006e8(DAT_0034a6a8,(int)&DAT_00234800);
      DAT_0034a6a8 = 0;
    }
    if (DAT_0034a6ac != 0) {
      FUN_000006e8(DAT_0034a6ac,(int)&DAT_00234800);
      DAT_0034a6ac = 0;
    }
    if (DAT_0034a6b0 != 0) {
      FUN_000006e8(DAT_0034a6b0,(int)&DAT_000886c0);
      DAT_0034a6b0 = 0;
    }
    if (DAT_0034a6b4 != 0) {
      FUN_000006e8(DAT_0034a6b4,(int)&DAT_00088660);
      DAT_0034a6b4 = 0;
    }
    if (DAT_0034a6b8 != 0) {
      FUN_000006e8(DAT_0034a6b8,(int)&DAT_00088600);
      DAT_0034a6b8 = 0;
    }
    if (param_1[0x29] != 0) {
      FUN_002ade80(param_1[0x29],1);
      param_1[0x29] = 0;
    }
    if (DAT_00338714 != 0) {
      FUN_0005ba00(DAT_00338714,1);
      DAT_00338714 = 0;
    }
    if (DAT_003386cc != 0) {
      FUN_0005ba00(DAT_003386cc,1);
      DAT_003386cc = 0;
    }
    FUN_000429a0(DAT_00310fc4);
    DAT_003386b0 = 0;
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00060f84 end=0x00061070 symbol=FUN_00060f84 lang=c++ */
/* Clone of src/eboot/fun_00060138.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: switched to MWCC C++ (removed cc=gcc171-Os), added #pragma opt_strength_reduction off for the indexed loop, and restored inline member destructor null check; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_003b033c;
extern undefined DAT_003ba4b0;
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_000506b8(void *, undefined4);
extern "C" void * FUN_000550a0(void *, short);
extern "C" void FUN_00061070(void *, int);

#pragma opt_strength_reduction off

extern "C" undefined4 * FUN_00060f84(undefined4 *param_1, short param_2)
{
  undefined4 *puVar2;
  uint uVar4;
  
  if (param_1 != 0) {
    *param_1 = (undefined4)&DAT_003b033c;
    FUN_00061070(param_1, 0);
    if (param_1[0xd] != 0) {
      FUN_00000a00((void *)param_1[0xd]);
      param_1[0xd] = 0;
    }
    for (uVar4 = 0; uVar4 < (uint)param_1[0xb]; uVar4++) {
      FUN_000506b8(&DAT_003ba4b0, ((undefined4 *)param_1[10])[uVar4]);
      ((undefined4 *)param_1[10])[uVar4] = 0xffffffff;
    }
    puVar2 = param_1 + 10;
    if (puVar2 != 0 && puVar2 != 0) {
      FUN_000550a0(puVar2, 0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

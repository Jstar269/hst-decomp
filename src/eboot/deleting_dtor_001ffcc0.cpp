/* HSTMATCH module=EBOOT.BIN start=0x001ffcc0 end=0x001ffdbc symbol=FUN_001ffcc0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the global tested before FUN_000009e4 is that call's argument (Ghidra dropped it, so retail loads it into a0); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern void *DAT_0034a144;
extern void FUN_000009e4(void *);
extern void FUN_00000a00(...);
extern int FUN_002175d4(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" int FUN_001ffcc0(int param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != 0) {
    if (DAT_0034a144) {
      FUN_000009e4(DAT_0034a144);
      DAT_0034a144 = 0;
    }
    piVar1 = *(int **)(param_1 + 4);
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *(undefined4 *)(param_1 + 4) = 0;
    }
    FUN_002175d4(param_1 + 0xb78,0xffffffff);
    FUN_002175d4(param_1 + 0xaec,0xffffffff);
    FUN_002175d4(param_1 + 0xa60,0xffffffff);
    FUN_002175d4(param_1 + 0x9d4,0xffffffff);
    FUN_002175d4(param_1 + 0x948,0xffffffff);
    FUN_002175d4(param_1 + 0x8bc,0xffffffff);
    FUN_002175d4(param_1 + 0x830,0xffffffff);
    FUN_002175d4(param_1 + 0x7a4,0xffffffff);
    FUN_002175d4(param_1 + 0x718,0xffffffff);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}

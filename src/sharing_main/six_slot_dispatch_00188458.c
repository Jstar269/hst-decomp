/* HSTMATCH module=hstp_trans_main.prx start=0x00188458 end=0x001884d4 symbol=FUN_00188458 lang=c99 */
/* Clone of src/eboot/six_slot_dispatch_0017bd64.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (same six-slot loop as 0x0017bce8, field +0x74); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_00058090();

void FUN_00188458(int param_1,int param_2)
{
  int t = *(int *)(*(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x74);
  if (t != 0) {
    for (int i = 0; i < 6; i++) {
      FUN_00058090(t, i, *(int *)(*(int *)(param_1 + 0x14) + i * 4), 0);
    }
  }
}

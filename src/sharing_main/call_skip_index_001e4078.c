/* HSTMATCH module=hstp_trans_main.prx start=0x001e4078 end=0x001e40e8 symbol=FUN_001e4078 lang=c99 */
/* Clone of src/eboot/call_skip_index_001d6288.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (rolled i*4 dispatch loop kept by pragmas); exact match verified; names and types await human review. */
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

extern void FUN_00105470();

void FUN_001e4078(int param_1,int param_2)
{
  for (int i = 0; i < *(int *)(param_1 + 0x14); i++) {
    FUN_00105470(*(int *)(*(int *)(param_1 + 0x10) + i * 4), i != param_2);
  }
}

/* HSTMATCH module=hstp_trans_main.prx start=0x002b0a08 end=0x002b0a68 symbol=FUN_002b0a08 lang=c99 */
/* Clone of src/eboot/FUN_002a15fc_002a15fc.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: typed the mixed integer and float helper parameters in EABI order; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef float undefined4;

extern void FUN_00058814(int, int, int, float, float, float);
extern uint FUN_000587ac(int, int, uint, float);

void FUN_002b0a08(int param_1,int param_2,uint param_3)
{
  FUN_00058814(param_1,param_2,-1,0.0f,0.0f,0.0f);
  FUN_000587ac(param_1,param_2,param_3,0.0f);
  return;
}

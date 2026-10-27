/* HSTMATCH module=hstp_trans_main.prx start=0x0006f680 end=0x0006f6ec symbol=FUN_0006f680 lang=c99 data=0x0037734c */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037734c-0x00377353) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
typedef unsigned int undefined4;

extern undefined * DAT_003daf6c;
extern char DAT_00377320[];
extern char DAT_00377354[];
extern void FUN_0006f3e0();
extern int FUN_000700a0();

undefined4 * FUN_0006f680(undefined4 *param_1)
{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  if (DAT_003daf6c == 0) {
    FUN_0006f3e0(DAT_00377320,"s_pRes",
                 DAT_00377354,0x7a);
    do {
                    
    } while( true );
  }
  uVar1 = FUN_000700a0(DAT_003daf6c + 0xc);
  param_1[1] = uVar1;
  return param_1;
}

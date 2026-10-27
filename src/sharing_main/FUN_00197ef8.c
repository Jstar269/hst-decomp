/* HSTMATCH module=hstp_trans_main.prx start=0x00197ef8 end=0x00197f88 symbol=FUN_00197ef8 lang=c99 data=0x00388270 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00388270-0x0038827d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined4 DAT_003ea86c;
extern char DAT_00388244[];
extern char DAT_00388280[];
extern int FUN_00000bcc();
extern void FUN_00197f88();
extern undefined4 * FUN_001980f4();

void FUN_00197ef8(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  if (DAT_003ea86c == 0) {
    iVar1 = FUN_00000bcc(0x90);
    if (iVar1 != 0) {
      FUN_001980f4(iVar1,param_1,param_2);
    }
    if (DAT_003ea86c == 0) {
      FUN_00197f88(DAT_00388244,"g_pPreRender",
                   DAT_00388280,0x76);
      do {
                    
      } while( true );
    }
  }
  return;
}

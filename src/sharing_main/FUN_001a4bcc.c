/* HSTMATCH module=hstp_trans_main.prx start=0x001a4bcc end=0x001a4c58 symbol=FUN_001a4bcc lang=c99 data=0x00388f88 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00388f88-0x00388f8e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern char DAT_00388f14[];
extern char DAT_00388f48[];
extern void FUN_001a33a4();
extern void FUN_001a4184();
extern void FUN_001a49ec();

int FUN_001a4bcc(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  undefined1 auStack_400 [1024];
  
  if (param_4 == 0) {
    FUN_001a33a4(DAT_00388f14,"p_dst",
                 DAT_00388f48,0x603);
    do {
                    
    } while( true );
  }
  FUN_001a49ec(param_1,param_2,auStack_400);
  FUN_001a4184(param_1,auStack_400,0,0,param_3,param_4);
  return param_4;
}

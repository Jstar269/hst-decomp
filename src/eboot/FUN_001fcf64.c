/* HSTMATCH module=EBOOT.BIN start=0x001fcf64 end=0x001fcfc0 symbol=FUN_001fcf64 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern undefined4 DAT_0034a13c;
extern int FUN_00000bcc();
extern undefined4 * FUN_001fd180();
extern void FUN_001fd46c();

void FUN_001fcf64(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = FUN_00000bcc(0x1350);
  if (iVar1 != 0) {
    FUN_001fd180(iVar1,param_1);
  }
  FUN_001fd46c(DAT_0034a13c,param_2,0);
  return;
}

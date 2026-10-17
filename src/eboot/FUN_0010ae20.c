/* HSTMATCH module=EBOOT.BIN start=0x0010ae20 end=0x0010aeb0 symbol=FUN_0010ae20 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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

extern char DAT_002d91c0[];
extern char DAT_002d91e8[];
extern void FUN_00012ad0();
extern uint FUN_0004cad0();
extern undefined4 FUN_0010ad1c();

undefined4 FUN_0010ae20(undefined1 *param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 uVar2;
  int local_4;
  
  iVar1 = FUN_0004cad0(param_2,&local_4,0x10,1);
  if (iVar1 == 0) {
    FUN_00012ad0(DAT_002d91c0,param_2);
    uVar2 = 0;
  }
  else if (local_4 < 1) {
    FUN_00012ad0(DAT_002d91e8,param_2);
    uVar2 = 0;
  }
  else {
    *param_1 = 1;
    uVar2 = FUN_0010ad1c(param_1,iVar1);
  }
  return uVar2;
}

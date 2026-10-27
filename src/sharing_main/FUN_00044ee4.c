/* HSTMATCH module=hstp_trans_main.prx start=0x00044ee4 end=0x00044f4c symbol=FUN_00044ee4 lang=c99 data=0x003757c0 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x003757c0-0x003757fd) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern undefined4 DAT_003b927c;
extern undefined * FUN_0000fe3c();
extern void FUN_00042c40();
extern int * FUN_000e3638();
extern void FUN_002ad2dc();

undefined4 FUN_00044ee4(void)
{
  int iVar1;
  undefined4 uVar2;
  
  FUN_002ad2dc();
  DAT_003b927c = (unsigned int)(FUN_000e3638("gf_string_allocator",0x26c00,0,0));
  if (DAT_003b927c == 0) {
    iVar1 = (int)(FUN_0000fe3c());
    FUN_00042c40(*(undefined4 *)(iVar1 + 0xc),"fatal error : can not allocate gfstring\n");
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* HSTMATCH module=EBOOT.BIN start=0x00198278 end=0x001982d8 symbol=FUN_00198278 lang=c99 */
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

extern void FUN_00197834();
extern void FUN_00198098();

undefined4 FUN_00198278(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined1 auStack_400 [1024];
  
  FUN_00198098(param_1,param_2,auStack_400);
  FUN_00197834(param_1,auStack_400,0,0,param_3,param_4);
  return param_4;
}

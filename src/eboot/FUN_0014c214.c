/* HSTMATCH module=EBOOT.BIN start=0x0014c214 end=0x0014c274 symbol=FUN_0014c214 lang=c99 */
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

extern undefined4 * FUN_0014c794();
extern int FUN_0014c820();
extern undefined4 * FUN_0014c914();
extern undefined4 * FUN_0014f528();

undefined4 FUN_0014c214(int param_1,int *param_2,int param_3)
{
  undefined1 auStack_24 [36];
  
  FUN_0014c794(auStack_24,param_2,*(undefined4 *)(*param_2 + param_3 * 8 + 4));
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_0014f528(param_1 + 0x18);
  FUN_0014c914(param_1,auStack_24);
  FUN_0014c820(auStack_24,0xffffffff);
  return 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x00117c24 end=0x00117c74 symbol=FUN_00117c24 lang=c99 */
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

extern undefined4 DAT_00340284;
extern void FUN_00117d70();
extern void FUN_00117dd0();

void FUN_00117c24(int param_1)
{
  FUN_00117d70(param_1,1,0xffffffec,1);
  FUN_00117dd0(param_1);
  *(undefined1 *)(param_1 + 0x4c) = 1;
  *(undefined1 *)(*(int *)(DAT_00340284 + 0x80) + 0x79) = 0;
  return;
}

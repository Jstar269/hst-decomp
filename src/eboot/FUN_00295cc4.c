/* HSTMATCH module=EBOOT.BIN start=0x00295cc4 end=0x00295ccc symbol=FUN_00295cc4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
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

extern void FUN_00113580(float param_1,int param_2);

void FUN_00295cc4(float param_1,int param_2)
{
  FUN_00113580(param_1,*(int *)(param_2 + 100));
  return;
}

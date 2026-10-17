/* HSTMATCH module=EBOOT.BIN start=0x0010b684 end=0x0010b6d4 symbol=FUN_0010b684 lang=c99 */
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

extern void FUN_0010b150();
extern void FUN_0010b368();

void FUN_0010b684(int param_1,undefined4 param_2,undefined1 param_3)
{
  FUN_0010b368(param_1,0);
  *(undefined1 *)(param_1 + 0x114) = param_3;
  *(undefined4 *)(param_1 + 0x118) = param_2;
  FUN_0010b150(param_1);
  return;
}

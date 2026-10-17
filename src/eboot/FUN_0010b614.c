/* HSTMATCH module=EBOOT.BIN start=0x0010b614 end=0x0010b684 symbol=FUN_0010b614 lang=c99 */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern void FUN_0010b150();
extern void FUN_0010b368();

void FUN_0010b614(int param_1)
{
  FUN_0010b368(param_1,1);
  *(undefined2 *)(param_1 + 0xec) =
       *(undefined2 *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0xdc) * 0xc);
  *(undefined2 *)(param_1 + 0xee) =
       *(undefined2 *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0xdc) * 0xc + 2);
  FUN_0010b150(param_1);
  return;
}

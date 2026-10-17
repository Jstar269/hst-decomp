/* HSTMATCH module=EBOOT.BIN start=0x000f3948 end=0x000f397c symbol=FUN_000f3948 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


void FUN_000f3948(int param_1)
{
  *(undefined4 *)(param_1 + 0x1e0) = *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x24);
  *(undefined4 *)(param_1 + 0x1e4) = *(undefined4 *)(*(int *)(param_1 + 300) + 0x24);
  *(undefined4 *)(param_1 + 0x1e8) = *(undefined4 *)(*(int *)(param_1 + 0x138) + 0x24);
  *(undefined4 *)(param_1 + 0x1ec) = *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0x24);
  return;
}

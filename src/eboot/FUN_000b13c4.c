/* HSTMATCH module=EBOOT.BIN start=0x000b13c4 end=0x000b1404 symbol=FUN_000b13c4 lang=c99 */
/* Hand-written reconstruction from the disassembly (range check written as one && condition); exact match verified; names and types await human review. */
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


int FUN_000b13c4(int param_1)
{
  int obj = *(int *)(*(int *)(param_1 + 0x5bc) + 0x58);
  int v = obj ? *(int *)(obj + 0xf0) : -1;
  if (v >= 0x48 && v < 0x4a) return 1;
  return 0;
}

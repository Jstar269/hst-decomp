/* HSTMATCH module=EBOOT.BIN start=0x00093c30 end=0x00093c7c symbol=FUN_00093c30 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: typed the copied argument as a four-float record; exact match verified; names and types await human review. */
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

extern void FUN_000944c8();

typedef struct { float x, y, z, w; } Float4;

void FUN_00093c30(int param_1,Float4 *param_2)
{
  Float4 local;
  local = *param_2;
  FUN_000944c8(param_1 + 0x80,&local,*(undefined4 *)(param_1 + 0x58));
}

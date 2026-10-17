/* HSTMATCH module=EBOOT.BIN start=0x0012c2dc end=0x0012c364 symbol=FUN_0012c2dc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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

extern undefined DAT_002c0e30;
extern void FUN_0012ca4c();

int FUN_0012c2dc(int param_1)
{
  *(undefined **)(param_1 + 0x40) = &DAT_002c0e30;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  if (*(uint *)(param_1 + 0x78) < 10) {
    FUN_0012ca4c(param_1 + 0x70,10);
  }
  if (*(uint *)(param_1 + 0x8c) < 10) {
    FUN_0012ca4c(param_1 + 0x84,10);
  }
  *(undefined4 *)(param_1 + 0x90) = 0x3f800000;
  *(undefined1 *)(param_1 + 0x94) = 0;
  return param_1;
}

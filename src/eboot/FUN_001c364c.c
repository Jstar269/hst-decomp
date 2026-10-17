/* HSTMATCH module=EBOOT.BIN start=0x001c364c end=0x001c36d8 symbol=FUN_001c364c lang=c99 */
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

extern undefined4 DAT_003415d4;
extern void FUN_0015d46c();
extern void FUN_001905b8();
extern void FUN_001ca8f0();
extern void FUN_001cd3d8();
extern void FUN_001cd88c();

void FUN_001c364c(int param_1)
{
  if (*(int *)(param_1 + 8) == 0x1e) {
    if (*(int *)(param_1 + 0xf8) == 1) {
      FUN_0015d46c();
    }
    else {
      FUN_001ca8f0(*(undefined4 *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0xe8) = 1;
      *(undefined1 *)(param_1 + 0xf0) = 0;
      FUN_001905b8(DAT_003415d4,3);
      FUN_001cd88c(param_1,8,1);
      FUN_001cd3d8(*(undefined4 *)(param_1 + 0x18));
    }
  }
  return;
}

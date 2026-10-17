/* HSTMATCH module=EBOOT.BIN start=0x000ae68c end=0x000ae774 symbol=FUN_000ae68c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: control flow, byte and float fields, and bit tests; exact match verified; names and types await human review. */
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

extern undefined * DAT_003386b0;
extern unsigned char DAT_003386b8;
extern void FUN_000a0410();

void FUN_000ae68c(int param_1,int param_2)
{
  if (*(int *)(DAT_003386b0 + 0x3c) != 7) {
    int bVar2 = DAT_003386b8 != 0;
    if (bVar2) {
      bVar2 = *(uchar *)(param_1 + 0x1b4) != 0;
    }
    if (bVar2 == 0) {
      return;
    }
  }
  *(int *)(param_1 + 0x41c) = (int)*(short *)(param_2 + 0x20);
  *(int *)(param_1 + 0x4e4) = ((int)*(char *)(param_2 + 0x22) << 0x1d) >> 0x1d;
  *(int *)(param_1 + 0x4e8) = ((int)*(char *)(param_2 + 0x22) << 0x18) >> 0x1b;
  *(bool *)(param_1 + 0x4cf) = ((int)*(char *)(param_2 + 0x23) << 0x1e) >> 0x1e != 0;
  *(bool *)(param_1 + 0x4d8) = (((int)*(char *)(param_2 + 0x23) << 0x1d) >> 31) != 0;
  *(bool *)(param_1 + 0x4d9) = (((int)*(char *)(param_2 + 0x23) << 0x1c) >> 31) != 0;
  *(bool *)(param_1 + 0x4da) = (((int)*(char *)(param_2 + 0x23) << 0x1b) >> 31) != 0;
  *(int *)(param_1 + 0x4dc) = ((int)*(char *)(param_2 + 0x23) << 0x18) >> 0x1d;
  *(float *)(param_1 + 0x43c) = *(float *)(param_2 + 0x24);
  FUN_000a0410(param_1,*(undefined4 *)(param_1 + 0x4dc));
  return;
}

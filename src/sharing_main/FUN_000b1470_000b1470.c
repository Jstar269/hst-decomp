/* HSTMATCH module=hstp_trans_main.prx start=0x000b1470 end=0x000b1558 symbol=FUN_000b1470 lang=c99 */
/* Clone of src/eboot/FUN_000ae68c_000ae68c.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined * DAT_003e19f0;
extern unsigned char DAT_003e19f8;
extern void FUN_000a2a1c();

void FUN_000b1470(int param_1,int param_2)
{
  if (*(int *)(DAT_003e19f0 + 0x3c) != 7) {
    int bVar2 = DAT_003e19f8 != 0;
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
  FUN_000a2a1c(param_1,*(undefined4 *)(param_1 + 0x4dc));
  return;
}

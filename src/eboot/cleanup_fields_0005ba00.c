/* HSTMATCH module=EBOOT.BIN start=0x0005ba00 end=0x0005ba78 symbol=FUN_0005ba00 lang=c99 */
/* Clone of src/sharing_main/cleanup_fields_0005c688.c (hstclone.py tag u6cr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v16) corrected by hand: simplified field cleanup branches and typed helpers; exact match verified; names and types await human review. */
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

extern void FUN_000009e4(int);
extern void FUN_00000a00(int *);

int FUN_0005ba00(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_000009e4(*(int *)(param_1 + 0x1c));
      *(int *)(param_1 + 0x1c) = 0;
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      FUN_000009e4(*(int *)(param_1 + 0x24));
      *(int *)(param_1 + 0x24) = 0;
    }
    if (param_2 > 0) {
      FUN_00000a00((int *)param_1);
    }
  }
  return param_1;
}

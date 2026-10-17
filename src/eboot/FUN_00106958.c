/* HSTMATCH module=EBOOT.BIN start=0x00106958 end=0x00106a34 symbol=FUN_00106958 lang=c99 */
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

extern void FUN_0027fc70();

void FUN_00106958(int param_1)
{
  if (*(int *)(param_1 + 0xd4) == 2) {
    FUN_0027fc70(param_1 + 0xd8,
                 *(undefined4 *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xd0) * 4),1);
  }
  else if (*(int *)(param_1 + 0xd4) == 3) {
    FUN_0027fc70(param_1 + 0xd8,*(undefined4 *)(*(int *)(param_1 + 0x10) + 4),0);
    FUN_0027fc70(param_1 + 0xd8,*(undefined4 *)(*(int *)(param_1 + 0x10) + 8),1);
  }
  else {
    FUN_0027fc70(param_1 + 0xd8,*(undefined4 *)(*(int *)(param_1 + 0x10) + 4),0);
    FUN_0027fc70(param_1 + 0xd8,*(undefined4 *)(*(int *)(param_1 + 0x10) + 8),0);
    FUN_0027fc70(param_1 + 0xd8,*(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc),0);
    FUN_0027fc70(param_1 + 0xd8,*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10),1);
  }
  return;
}

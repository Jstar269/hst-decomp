/* HSTMATCH module=EBOOT.BIN start=0x00096128 end=0x00096178 symbol=FUN_00096128 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_00096128.c) corrected by hand: materialized the state test as an int and initialized the return local from it before the conditional call; exact match verified; names and types await human review. */
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

extern undefined4 DAT_00338c20;
extern undefined * DAT_003415ac;
extern undefined4 FUN_000fb7b8();

int FUN_00096128(void)
{
  int has_state = ((*(ushort *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) != 0);
  int result = has_state;
  if (has_state != 0) {
    int iVar2 = FUN_000fb7b8(DAT_00338c20);
    result = (iVar2 != 0) ^ 1;
  }
  return result;
}

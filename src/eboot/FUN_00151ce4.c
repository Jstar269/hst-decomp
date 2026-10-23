/* HSTMATCH module=EBOOT.BIN start=0x00151ce4 end=0x00151d68 symbol=FUN_00151ce4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_00151ce4.c) corrected by hand: typed the byte and pointer globals, inverted the message branch, and materialized the post-cleanup zero flag; exact match verified; names and types await human review. */
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

extern undefined DAT_002dc440;
extern undefined DAT_002dc5d8;
extern unsigned char DAT_003402f0;
extern void *DAT_0034a2e0;
extern char DAT_002dc5c0[];
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_00225d54(void *, int, int);
extern void FUN_0022bf40();

undefined4 FUN_00151ce4(int param_1,undefined4 param_2)
{
  undefined *puVar1;
  
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    if (*(uchar *)(param_1 + 8) != 0) {
      puVar1 = &DAT_002dc5d8;
    } else {
      puVar1 = &DAT_002dc440;
    }
    FUN_0014fd94(DAT_002dc5c0,puVar1);
  }
  FUN_0022bf40(0);
  uchar state = *(uchar *)(param_1 + 8);
  int is_zero = ((state != 0) ^ 1);
  FUN_00225d54(DAT_0034a2e0,0,is_zero);
  return 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x001c6bec end=0x001c6cac symbol=FUN_001c6bec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: used a direct nonnegative signed guard; exact match verified; names and types await human review. */
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

extern void FUN_001c25b0();
extern void FUN_001c2714();
extern void FUN_0022bf94();

void FUN_001c6bec(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5, undefined4 param_6)
{
  if (param_2 < 0x11) {
    if (param_2 >= 0) {
      FUN_0022bf94(param_2,param_3);
    }
    if (param_4 < 0) {
      FUN_001c25b0(*(undefined4 *)(param_1 + 0x15c),param_2,param_3,param_5,param_6);
    }
    else {
      FUN_001c2714(*(undefined4 *)(param_1 + 0x15c),param_4,param_2,param_3,param_5,param_6);
    }
    *(undefined4 *)(param_1 + 0x154) = 0xffffffff;
  }
  return;
}

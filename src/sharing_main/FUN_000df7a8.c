/* HSTMATCH module=hstp_trans_main.prx start=0x000df7a8 end=0x000df814 symbol=FUN_000df7a8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern undefined DAT_003e1e88;
extern undefined DAT_003eaaf3;
extern undefined DAT_003eabd3;
extern undefined DAT_003eacf3;
extern void FUN_000df814();
extern void FUN_000df888();

void FUN_000df7a8(int param_1)
{
  if (DAT_003e1e88 != '\0') {
    DAT_003eaaf3 = 0;
    DAT_003eabd3 = 2;
    DAT_003eacf3 = 1;
    *(undefined4 *)(param_1 + 0xb4) = 1;
    *(undefined4 *)(param_1 + 0xc0) = 9;
  }
  FUN_000df814(param_1);
  FUN_000df888(param_1);
  *(undefined1 *)(param_1 + 0xb0) = 0;
  return;
}

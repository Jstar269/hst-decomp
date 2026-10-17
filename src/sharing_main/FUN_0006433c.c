/* HSTMATCH module=hstp_trans_main.prx start=0x0006433c end=0x00064364 symbol=FUN_0006433c lang=c99 */
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

extern undefined DAT_003ba4b0;
extern undefined4 FUN_00050e10();
extern void FUN_00051d38();

void FUN_0006433c(int param_1)
{
  FUN_00051d38(*(undefined4 *)(param_1 + 4));
  FUN_00050e10((int)&DAT_003ba4b0);
  return;
}

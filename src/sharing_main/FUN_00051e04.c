/* HSTMATCH module=hstp_trans_main.prx start=0x00051e04 end=0x00051e18 symbol=FUN_00051e04 lang=c99 */
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
extern undefined4 FUN_00050920();

void FUN_00051e04(int param_1)
{
  FUN_00050920((int)&DAT_003ba4b0,*(undefined4 *)(param_1 + 4),0);
  return;
}

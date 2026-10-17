/* HSTMATCH module=hstp_trans_main.prx start=0x0003cb18 end=0x0003cb28 symbol=FUN_0003cb18 lang=c99 */
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

extern uint FUN_0003d9c0();

void FUN_0003cb18(int param_1)
{
  FUN_0003d9c0(*(undefined4 *)(param_1 + 0x81c),0,0);
  return;
}

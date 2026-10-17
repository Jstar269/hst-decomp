/* HSTMATCH module=hstp_trans_main.prx start=0x000514cc end=0x00051500 symbol=FUN_000514cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
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


void FUN_000514cc(char *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4, undefined1 param_5)
{
  *(undefined1 *)(param_1 + 0x1a0b4) = param_2;
  *(undefined1 *)(param_1 + 0x1a0b5) = param_3;
  *(undefined1 *)(param_1 + 0x1a0b6) = param_4;
  *(undefined1 *)(param_1 + 0x1a0b7) = param_5;
  return;
}

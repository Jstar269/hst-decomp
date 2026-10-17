/* HSTMATCH module=hstp_trans_main.prx start=0x00051d40 end=0x00051d84 symbol=FUN_00051d40 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: expressed the three stores as ascending switch cases; exact match verified; names and types await human review. */
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


void FUN_00051d40(int param_1,int param_2)
{
  switch (param_2) {
    case 0: *(undefined4 *)(param_1 + 0x1c) = 0x10; break;
    case 1: *(undefined4 *)(param_1 + 0x1c) = 0x11; break;
    case 2: *(undefined4 *)(param_1 + 0x1c) = 0x12; break;
  }
}

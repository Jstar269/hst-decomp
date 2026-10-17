/* HSTMATCH module=hstp_trans_main.prx start=0x0001b6e0 end=0x0001b710 symbol=FUN_0001b6e0 lang=c99 */
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

extern undefined4 DAT_003b7ea0;
extern void FUN_0001b5a8();
extern void FUN_002c7718();

undefined4 FUN_0001b6e0(void)
{
  FUN_0001b5a8();
  DAT_003b7ea0 = 0;
  FUN_002c7718(0);
  return 0;
}

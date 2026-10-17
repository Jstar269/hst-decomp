/* HSTMATCH module=hstp_trans_main.prx start=0x001c6408 end=0x001c6440 symbol=FUN_001c6408 lang=c99 */
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

extern undefined DAT_003eaad8;
extern undefined4 FUN_001c0018();

void FUN_001c6408(int param_1)
{
  FUN_001c0018((int)&DAT_003eaad8,param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined1 *)(param_1 + 0x70) = 0;
  return;
}

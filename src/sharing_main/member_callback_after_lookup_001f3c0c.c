/* HSTMATCH module=hstp_trans_main.prx start=0x001f3c0c end=0x001f3c4c symbol=FUN_001f3c0c lang=c99 */
/* Clone of src/eboot/member_callback_after_lookup_001e59f4.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_001f08e8 as receiver-only; exact match verified; names and types await human review. */
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

extern void FUN_001f08e8(int);
extern void FUN_0023212c();

void FUN_001f3c0c(int param_1,undefined4 param_2)
{
  FUN_001f08e8(param_1);
  FUN_0023212c(*(undefined4 *)(param_1 + 0x1954),param_2,1);
  return;
}

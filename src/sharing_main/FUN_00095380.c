/* HSTMATCH module=hstp_trans_main.prx start=0x00095380 end=0x000953a8 symbol=FUN_00095380 lang=c99 */
/* Clone of src/eboot/FUN_00093434.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00055be8();

void FUN_00095380(int param_1,undefined4 *param_2)
{
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_00055be8(*(int *)(param_1 + 0x58),param_2);
  }
  return;
}

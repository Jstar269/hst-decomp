/* HSTMATCH module=hstp_trans_main.prx start=0x000f4528 end=0x000f4560 symbol=FUN_000f4528 lang=c99 */
/* Clone of src/eboot/FUN_000eee60.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_000f4590();
extern void FUN_00109024();

void FUN_000f4528(int param_1)
{
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  FUN_000f4590();
  FUN_00109024(param_1,0);
  return;
}

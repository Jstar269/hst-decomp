/* HSTMATCH module=hstp_trans_main.prx start=0x000f59e4 end=0x000f5a18 symbol=FUN_000f59e4 lang=c99 */
/* Clone of src/eboot/FUN_000f031c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00108f54();

void FUN_000f59e4(int param_1)
{
  FUN_00108f54(param_1,1);
  *(undefined1 *)(param_1 + 0x54) = 1;
  *(undefined4 *)(param_1 + 0x94) = 0;
  return;
}

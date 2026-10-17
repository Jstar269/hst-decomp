/* HSTMATCH module=hstp_trans_main.prx start=0x002a4454 end=0x002a446c symbol=FUN_002a4454 lang=c99 */
/* Clone of src/eboot/FUN_00292e48.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_002a4454(int param_1)
{
  *(undefined1 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 4) = 0x41f00000;
  *(undefined4 *)(param_1 + 8) = 0x41f00000;
  *(undefined4 *)(param_1 + 0x38) = 0;
  return;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00094cb0 end=0x00094ccc symbol=FUN_00094cb0 lang=c99 */
/* Clone of src/eboot/FUN_00092e1c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00094cb0(int param_1)
{
  if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x170) = 1;
  }
  return;
}

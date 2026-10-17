/* HSTMATCH module=hstp_trans_main.prx start=0x00097048 end=0x00097064 symbol=FUN_00097048 lang=c99 */
/* Clone of src/eboot/FUN_0009503c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00097048(int param_1)
{
  *(undefined4 *)(param_1 + 0x1b0) = 6;
  *(undefined4 *)(param_1 + 0x1b4) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x1b8) = 0;
  *(undefined1 *)(param_1 + 0x1ba) = 0;
  return;
}

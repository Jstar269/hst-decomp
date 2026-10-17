/* HSTMATCH module=hstp_trans_main.prx start=0x00200290 end=0x002002ac symbol=FUN_00200290 lang=c99 */
/* Clone of src/eboot/FUN_001f1e8c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00200290(int param_1)
{
  if (*(int *)(param_1 + 0x44) == 0) {
    *(undefined1 *)(param_1 + 0x515) = 1;
  }
  return;
}

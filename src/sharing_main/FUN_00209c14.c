/* HSTMATCH module=hstp_trans_main.prx start=0x00209c14 end=0x00209c3c symbol=FUN_00209c14 lang=c99 */
/* Clone of src/eboot/FUN_001fb4fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003eabf4;

bool FUN_00209c14(int param_1)
{
  return (&DAT_003eabf4)[*(int *)(param_1 + 0x3cc) * 0x120] != '\0';
}

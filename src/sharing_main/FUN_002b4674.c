/* HSTMATCH module=hstp_trans_main.prx start=0x002b4674 end=0x002b46a8 symbol=FUN_002b4674 lang=c99 */
/* Clone of src/eboot/FUN_002a4ee4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001109a8();

void FUN_002b4674(char *param_1)
{
  if (*(int *)(param_1 + 0x5d0) == 2) {
    FUN_001109a8(param_1 + 0x40,(undefined4 *)(param_1 + 0x5d4));
  }
  return;
}

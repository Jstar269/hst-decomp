/* HSTMATCH module=hstp_trans_main.prx start=0x00122d88 end=0x00122dc0 symbol=FUN_00122d88 lang=c99 */
/* Clone of src/eboot/FUN_00117d38.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e19f0;
extern void FUN_0001f4a0();
extern void FUN_0008c348();

void FUN_00122d88(void)
{
  FUN_0008c348(DAT_003e19f0);
  FUN_0001f4a0(DAT_003e19f0,0x16,0,0);
  return;
}

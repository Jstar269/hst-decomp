/* HSTMATCH module=hstp_trans_main.prx start=0x002a2988 end=0x002a29a0 symbol=FUN_002a2988 lang=c99 */
/* Clone of src/eboot/FUN_00291280.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003f3b40;
extern undefined4 DAT_003f3b44;

undefined4 FUN_002a2988(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  DAT_003f3b40 = param_2;
  DAT_003f3b44 = param_3;
  return 1;
}

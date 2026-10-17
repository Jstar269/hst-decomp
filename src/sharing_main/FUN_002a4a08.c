/* HSTMATCH module=hstp_trans_main.prx start=0x002a4a08 end=0x002a4a48 symbol=FUN_002a4a08 lang=c99 */
/* Clone of src/eboot/FUN_002933fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


undefined4 FUN_002a4a08(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((*(uchar *)(param_1 + 0x4d) != '\0') && (*(uchar *)(param_1 + 0x40) == '\0')) &&
     (*(float *)(param_1 + 0x38) <= 31.0f)) {
    uVar1 = 1;
  }
  return uVar1;
}

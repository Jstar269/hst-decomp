/* HSTMATCH module=EBOOT.BIN start=0x0001dce4 end=0x0001dd24 symbol=FUN_0001dce4 lang=c99 */
/* Clone of src/eboot/FUN_0009447c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00000a00();

int FUN_0001dce4(int param_1,short param_2)
{
  if ((param_1 != 0) && (0 < param_2)) {
    FUN_00000a00();
  }
  return param_1;
}

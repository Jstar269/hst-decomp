/* HSTMATCH module=hstp_trans_main.prx start=0x0016646c end=0x00166480 symbol=FUN_0016646c lang=c99 */
/* Clone of src/eboot/FUN_00159ef4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


undefined1 FUN_0016646c(undefined4 *param_1)
{
  undefined1 uVar1;
  
  uVar1 = *(undefined1 *)*param_1;
  *param_1 = (unsigned int)((undefined1 *)*param_1 + 1);
  return uVar1;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0015b03c end=0x0015b050 symbol=FUN_0015b03c lang=c99 */
/* Clone of src/eboot/FUN_0014f028.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


undefined4 FUN_0015b03c(undefined4 *param_1)
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)*param_1;
  *param_1 = (unsigned int)((undefined4 *)*param_1 + 1);
  return uVar1;
}

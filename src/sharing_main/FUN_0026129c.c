/* HSTMATCH module=hstp_trans_main.prx start=0x0026129c end=0x002612ac symbol=FUN_0026129c lang=c99 */
/* Clone of src/eboot/FUN_00250f48.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003a4908;

void FUN_0026129c(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x304) = param_2;
  DAT_003a4908 = param_2;
  return;
}

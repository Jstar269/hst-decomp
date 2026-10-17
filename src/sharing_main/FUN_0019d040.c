/* HSTMATCH module=hstp_trans_main.prx start=0x0019d040 end=0x0019d04c symbol=FUN_0019d040 lang=c99 */
/* Clone of src/eboot/FUN_00190830.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


undefined4 FUN_0019d040(int param_1)
{
  return *(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x280);
}

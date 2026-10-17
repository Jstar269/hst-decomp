/* HSTMATCH module=hstp_trans_main.prx start=0x001a572c end=0x001a5734 symbol=FUN_001a572c lang=c99 */
/* Clone of src/eboot/FUN_00198d28.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_001a572c(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x98) = param_2;
  return;
}

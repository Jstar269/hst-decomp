/* HSTMATCH module=hstp_trans_main.prx start=0x00209fb8 end=0x00209fc8 symbol=FUN_00209fb8 lang=c99 */
/* Clone of src/eboot/FUN_001fb8a0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00209fb8(int param_1)
{
  *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 1;
  return;
}

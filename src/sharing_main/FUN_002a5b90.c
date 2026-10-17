/* HSTMATCH module=hstp_trans_main.prx start=0x002a5b90 end=0x002a5b98 symbol=FUN_002a5b90 lang=c99 */
/* Clone of src/eboot/FUN_00295cc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0011d7f8(float param_1,int param_2);

void FUN_002a5b90(float param_1,int param_2)
{
  FUN_0011d7f8(param_1,*(int *)(param_2 + 100));
  return;
}

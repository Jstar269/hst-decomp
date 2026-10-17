/* HSTMATCH module=hstp_trans_main.prx start=0x002773c8 end=0x002773d4 symbol=FUN_002773c8 lang=c99 */
/* Clone of src/eboot/FUN_002664c0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0005ffd8();

void FUN_002773c8(int param_1)
{
  FUN_0005ffd8(*(int **)(param_1 + 0x70),0);
  return;
}

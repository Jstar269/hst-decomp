/* HSTMATCH module=hstp_trans_main.prx start=0x002bec54 end=0x002bec5c symbol=FUN_002bec54 lang=c99 */
/* Clone of src/eboot/FUN_002af314.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
typedef float undefined4;

extern undefined8 FUN_001ca418(float param_1);

void FUN_002bec54(int param_1)
{
  FUN_001ca418(*(undefined4 *)(param_1 + 0x18));
  return;
}

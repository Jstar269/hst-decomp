/* HSTMATCH module=hstp_trans_main.prx start=0x001aa6dc end=0x001aa704 symbol=FUN_001aa6dc lang=c99 */
/* Clone of src/eboot/FUN_0019d208.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001a9088();

void FUN_001aa6dc(int param_1)
{
  if (*(int *)(param_1 + 0x90) != 0) {
    FUN_001a9088(param_1);
  }
  return;
}

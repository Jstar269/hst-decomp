/* HSTMATCH module=hstp_trans_main.prx start=0x000970ec end=0x00097110 symbol=FUN_000970ec lang=c99 */
/* Clone of src/eboot/FUN_000950e0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


bool FUN_000970ec(int param_1,int param_2)
{
  bool bVar1;
  
  if (*(uint *)(param_1 + 0x1b0) < 3) {
    bVar1 = *(short *)(param_1 + 0x1b8) == param_2;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0020c7e0 end=0x0020c81c symbol=FUN_0020c7e0 lang=c99 */
/* Clone of src/eboot/FUN_001fe010.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0020c384();
extern void FUN_0020c520();
extern void FUN_002100e0();
extern void FUN_00210598();

void FUN_0020c7e0(int param_1)
{
  FUN_0020c520();
  FUN_0020c384(param_1);
  FUN_002100e0(param_1 + 200);
  FUN_00210598(param_1 + 0x1250);
  return;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00105e28 end=0x00105e6c symbol=FUN_00105e28 lang=c99 */
/* Clone of src/eboot/FUN_001004f4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00051e18();

void FUN_00105e28(undefined4 param_1,int param_2)
{
  if ((*(ushort *)(param_2 + 0xe) & 0x600) != 0) {
    FUN_00051e18(param_1,0xd4000000);
    FUN_00051e18(param_1,0xd50441e0);
  }
  return;
}

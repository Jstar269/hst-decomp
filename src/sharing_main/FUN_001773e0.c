/* HSTMATCH module=hstp_trans_main.prx start=0x001773e0 end=0x00177434 symbol=FUN_001773e0 lang=c99 */
/* Clone of src/eboot/FUN_0016b21c.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_00177d4c();

int FUN_001773e0(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_00177d4c();
  if (0 <= param_1 && (param_1 < 0xf)) {
    iVar1 = iVar1 + param_1 * 0x38 + 4;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

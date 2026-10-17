/* HSTMATCH module=hstp_trans_main.prx start=0x001776d4 end=0x001776f8 symbol=FUN_001776d4 lang=c99 */
/* Clone of src/eboot/FUN_0016b510.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

bool FUN_001776d4(void)
{
  int iVar1;
  
  iVar1 = FUN_00177d4c();
  return *(uchar *)(iVar1 + 0x103c) != '\0';
}

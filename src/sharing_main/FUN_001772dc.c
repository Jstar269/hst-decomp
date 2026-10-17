/* HSTMATCH module=hstp_trans_main.prx start=0x001772dc end=0x001772fc symbol=FUN_001772dc lang=c99 */
/* Clone of src/eboot/FUN_0016b118.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

undefined2 FUN_001772dc(void)
{
  int iVar1;
  
  iVar1 = FUN_00177d4c();
  return *(undefined2 *)(iVar1 + 0x1034);
}

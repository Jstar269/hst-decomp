/* HSTMATCH module=hstp_trans_main.prx start=0x00228ee0 end=0x00228f68 symbol=FUN_00228ee0 lang=c99 */
/* Clone of src/eboot/FUN_002199c8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00051e30();
extern void FUN_000522c0();
extern void FUN_0005b540();

void FUN_00228ee0(undefined4 *param_1)
{
  int iVar2;
  int iVar1;
  
  FUN_00051e30(*param_1,0,0,0x1e0,0x110,0,0);
  iVar2 = 0;
  iVar1 = 0;
  do {
    FUN_0005b540(param_1[1] + iVar1,*param_1,0,0);
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0xa0;
  } while (iVar2 < 200);
  FUN_000522c0(*param_1);
  return;
}

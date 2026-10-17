/* HSTMATCH module=hstp_trans_main.prx start=0x002b6160 end=0x002b61d0 symbol=FUN_002b6160 lang=c99 */
/* Clone of src/eboot/FUN_002a69d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003a9b90;
extern undefined4 DAT_003f46a0;
extern void FUN_00111aa4();
extern void FUN_0011988c();
extern undefined * FUN_0020d1e0();

void FUN_002b6160(int param_1,int param_2)
{
  undefined4 uVar1;
  
  FUN_00111aa4(*(undefined4 *)(param_1 + 0x178),param_2,0);
  if (DAT_003f46a0 != 0) {
    uVar1 = (unsigned int)(FUN_0020d1e0(0x12,0x31,*(undefined4 *)(&DAT_003a9b90 + param_2 * 4)));
    FUN_0011988c(DAT_003f46a0,uVar1,0);
  }
  return;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00263a68 end=0x00263b28 symbol=FUN_00263a68 lang=c99 */
/* Clone of src/eboot/FUN_00253630.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003a57dc;
extern char DAT_003a57b8[];
extern int * FUN_00065884();
extern int * FUN_000658cc();
extern undefined4 FUN_00065ab8();
extern undefined4 FUN_00065fa4();
extern int FUN_00066038();

undefined4 * FUN_00263a68(undefined4 *param_1)
{
  int iVar1;
  int iVar2;
  undefined1 auStack_10 [16];
  
  *param_1 = 0;
  FUN_00065884(auStack_10);
  FUN_00065ab8(auStack_10,DAT_003a57b8,0,&DAT_003a57dc);
  param_1[6] = 0;
  iVar2 = 0;
  iVar1 = FUN_00065fa4(auStack_10);
  if (0 < iVar1) {
    do {
      iVar1 = FUN_00066038(auStack_10,iVar2,3);
      if (iVar1 != 0) {
        iVar1 = param_1[6];
        param_1[6] = iVar1 + 1;
        param_1[iVar1 + 7] = iVar2;
      }
      iVar2 = 1 + iVar2;
      iVar1 = FUN_00065fa4(auStack_10);
    } while (iVar2 < iVar1);
  }
  FUN_000658cc(auStack_10,0xffffffff);
  return param_1;
}

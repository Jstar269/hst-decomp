/* HSTMATCH module=hstp_trans_main.prx start=0x00002b60 end=0x00002bf4 symbol=FUN_00002b60 lang=c99 */
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

extern int FUN_00000bcc();
extern void FUN_00002bf4();
extern undefined4 FUN_00002bfc();
extern undefined4 * FUN_00002c3c();
extern undefined4 FUN_00002d3c();
extern int FUN_00002df8();

undefined4 * FUN_00002b60(undefined4 *param_1,undefined4 param_2,undefined1 param_3)
{
  int iVar1;
  undefined1 auStack_8 [8];
  undefined1 local_c [4];
  
  local_c[0] = param_3;
  *param_1 = param_2;
  FUN_00002d3c(auStack_8,param_2,local_c);
  if ((iVar1 = FUN_00000bcc(0x10)) == 0) {
  }
  else {
    FUN_00002c3c(iVar1,param_2,local_c);
  }
  FUN_00002bfc(auStack_8);
  param_1[1] = iVar1;
  FUN_00002bf4(param_1,param_2,param_2);
  FUN_00002df8(auStack_8,0xffffffff);
  return param_1;
}
// Near miss: 6 words differ. The allocation guard and saved pointer now match; retail prepares the cleanup stack argument before jal 0x2bfc and stores the field in that delay slot, while this candidate schedules the field store after the later 0x2bf4 call.
// near miss from lane u4r2-0 (unreviewed)

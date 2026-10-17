/* HSTMATCH module=hstp_trans_main.prx start=0x001bfbd8 end=0x001bfc3c symbol=FUN_001bfbd8 lang=c99 */
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

extern void FUN_000637a8();
extern int FUN_00063930();
extern undefined4 FUN_00063a00();

void FUN_001bfbd8(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 2000) <= 0) return;
  iVar1 = FUN_00063930();
  if (iVar1 == 0) {
    *(undefined4 *)(iVar2 + 2000) = 0xffffffff;
  }
  else {
    iVar1 = FUN_00063a00(*(undefined4 *)(iVar2 + 2000));
    if (iVar1 < 1) {
      FUN_000637a8(*(undefined4 *)(iVar2 + 2000),1);
    }
  }
}

// Near miss: two words remain; retail loads +0x7d0 into a0 and uses blezl a0, while MWCC uses v1.
// The early guard and int helper return are retained; a typed offset-2000 object did not change these words.
// near miss from lane u4r2-2 (unreviewed)

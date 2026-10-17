/* HSTMATCH module=hstp_trans_main.prx start=0x00000788 end=0x000007f4 symbol=FUN_00000788 lang=c99 */
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


void FUN_00000788(int param_1,code *param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = param_1 + param_3 * param_4;
  iVar1 = iVar1 - param_3;
  if (param_4 != 0) {
    do {
      (*param_2)(iVar1,0xffffffff);
      param_4 = param_4 - 1;
      iVar1 = iVar1 - param_3;
    } while (param_4 != 0);
  }
  return;
}
// Near miss: 4 words differ. The start-address addition is scheduled before the zero-count guard and the loop uses a non-likely back edge; moving the addition into the live path was tested but worsened the match.
// near miss from lane u4r2-0 (unreviewed)

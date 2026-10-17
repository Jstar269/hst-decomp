/* HSTMATCH module=hstp_trans_main.prx start=0x0000371c end=0x0000375c symbol=FUN_0000371c lang=c99 */
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

extern undefined4 FUN_00003004();

void FUN_0000371c(undefined4 param_1,int param_2)
{
  byte *pbVar1;
  
  uint value = (uint)param_2 & 0xff;
  pbVar1 = (byte *)FUN_00003004();
  value = (value & 0x7f) << 1;
  *pbVar1 = (*pbVar1 & 0xffffff01) | value;
  return;
}
// Near miss: 4 words differ. The shifted value remains in a1 and the loaded old byte in a0; retail uses a0 for the shifted value and a1 for the old byte.
// near miss from lane u4r2-0 (unreviewed)

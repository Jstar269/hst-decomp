/* HSTMATCH module=hstp_trans_main.prx start=0x0001dbec end=0x0001dc34 symbol=FUN_0001dbec lang=c99 */
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

extern void FUN_0001d9a4();

void FUN_0001dbec(byte *param_1,int param_2,int param_3)
{
  if ((param_2 & 0xff) == (uint)*param_1) return;
  *param_1 = param_2;
  if (param_3 == 0) {
    if (param_2 == 0) {
      FUN_0001d9a4();
    } else {
      *(uint *)(param_1 + 0x84) = 0xffff;
    }
  }
}
// Near miss: retail stores the original parameter from a1; this candidate stores the masked comparison byte from a3.
// Tried signed and unsigned parameter types and a volatile destination.
// near miss from lane u3r2-1 (unreviewed)

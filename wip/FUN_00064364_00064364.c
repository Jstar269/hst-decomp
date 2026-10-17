/* HSTMATCH module=hstp_trans_main.prx start=0x00064364 end=0x00064418 symbol=FUN_00064364 lang=c99 */
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

extern void FUN_00051d40();

void FUN_00064364(int param_1,float param_2,float param_3,float *param_4,float *param_5,undefined4 param_6,undefined1 param_7)
{
  *(float *)(param_1 + 0x20) = param_4[0];
  *(float *)(param_1 + 0x24) = param_4[1];
  *(float *)(param_1 + 0x28) = param_4[2];
  *(float *)(param_1 + 0x2c) = param_4[3];
  *(float *)(param_1 + 0x30) = param_5[0];
  *(float *)(param_1 + 0x34) = param_5[1];
  *(float *)(param_1 + 0x38) = param_5[2];
  *(float *)(param_1 + 0x3c) = param_5[3];
  *(float *)(param_1 + 8) = param_2;
  *(float *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = 0xbf800000;
  FUN_00051d40(*(undefined4 *)(param_1 + 4),param_6);
  *(undefined1 *)(param_1 + 0x40) = param_7;
  *(undefined1 *)(param_1 + 0x41) = 0;
  if (param_3 < 0.0f) {
    param_3 = 4000.0f;
  }
  *(float *)(param_1 + 0x44) = param_3;
  return;
}
// Near miss: two words remain. Retail saves the stack flag before saving $f13 to $f20; this source reverses those independent register moves. Changing the flag type and adding a local flag copy did not change the order.
// near miss from lane u1r2-2 (unreviewed)

/* HSTMATCH module=hstp_trans_main.prx start=0x00064bcc end=0x00064c8c symbol=FUN_00064bcc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: restored the object and float parameter positions from the EABI register evidence; exact match verified; names and types await human review. */
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

void FUN_00064bcc(int param_1,float param_2,int param_3,float param_4)
{
  *(undefined4 *)(param_1 + 0x20) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x24) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x28) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x2c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x30) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x34) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x38) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(float *)(param_1 + 8) = (float)param_3;
  *(float *)(param_1 + 0xc) = (float)param_3;
  *(undefined4 *)(param_1 + 0x10) = 0xbf800000;
  FUN_00051d40(*(undefined4 *)(param_1 + 4),0);
  *(undefined1 *)(param_1 + 0x40) = 1;
  *(undefined1 *)(param_1 + 0x41) = 0;
  if (param_4 < 0.0f) {
    param_4 = 4000.0f;
  }
  *(float *)(param_1 + 0x44) = param_4;
  *(undefined1 *)(param_1 + 0x50) = 0;
  *(undefined1 *)(param_1 + 0x51) = 0;
  *(undefined1 *)(param_1 + 0x52) = 1;
  *(undefined1 *)(param_1 + 0x53) = 1;
  *(float *)(param_1 + 0x54) = param_2;
  return;
}

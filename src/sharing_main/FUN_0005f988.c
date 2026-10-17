/* HSTMATCH module=hstp_trans_main.prx start=0x0005f988 end=0x0005fa04 symbol=FUN_0005f988 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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

extern void FUN_00060020();
extern void FUN_0006037c();

void FUN_0005f988(int param_1)
{
  *(undefined4 *)(param_1 + 0xa0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined1 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0x3f800000;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  if (*(uint *)(param_1 + 0xb0) < 0x40) {
    FUN_0006037c(param_1 + 0xa8,0x40);
  }
  if ((uint)(*(int *)(param_1 + 0xbc) << 5) < 0x40) {
    FUN_00060020(param_1 + 0xb4,0x40);
  }
  return;
}

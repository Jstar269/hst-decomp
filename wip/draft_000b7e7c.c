/* HSTMATCH module=EBOOT.BIN start=0x000b7e7c end=0x000b801c symbol=FUN_000b7e7c lang=c99 */
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

extern int DAT_002d496c;
extern int DAT_002d4970;
extern undefined DAT_003072b8;
extern undefined * DAT_00341ccc;
extern char DAT_002d4974[];
extern int FUN_00000bcc();
extern void FUN_0001ca58();
extern void FUN_0001cb88();
extern undefined4 * FUN_0001f06c();
extern void FUN_000b793c();
extern void FUN_000b9450();
extern undefined4 * FUN_0015e558();

undefined4 * FUN_000b7e7c(undefined4 *param_1)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_003072b8);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0x3f800000;
  param_1[0x1e] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0xc0000000;
  param_1[0x36] = 0;
  param_1[0x3c] = 0x41f00000;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  iVar3 = (int)*(char *)(DAT_00341ccc + 0x1052);
  param_1[0x19] = iVar3;
  iVar1 = DAT_002d496c;
  if (iVar3 < DAT_002d496c) {
    param_1[0x19] = DAT_002d496c;
  }
  else {
    iVar1 = DAT_002d4970;
    if (iVar3 <= DAT_002d4970) {
      iVar1 = iVar3;
    }
    param_1[0x19] = iVar1;
  }
  param_1[0x1a] = iVar1;
  param_1[0x1b] = param_1[0x19];
  param_1[0x1f] = 0;
  param_1[0x20] = 0x41800000;
  param_1[0x21] = 0x421c0000;
  param_1[0x22] = 0x41d00000;
  param_1[0x25] = 0;
  param_1[0x26] = 0x41800000;
  param_1[0x27] = 0x421c0000;
  param_1[0x28] = 0x41d00000;
  param_1[0x2b] = 0xbfa66666;
  param_1[0x2c] = 0x40b33333;
  param_1[0x2d] = 0x40c00000;
  param_1[0x2e] = 0x42040000;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0x3f800000;
  FUN_0001ca58(0x30ebf4,DAT_002d4974);
  FUN_000b9450(param_1,0);
  FUN_0001cb88(0x30ebf4);
  iVar1 = FUN_00000bcc(0xc0);
  if (iVar1 == 0) {
    param_1[0x3e] = 0;
    uVar2 = 0;
  }
  else {
    uVar2 = (unsigned int)(FUN_0015e558(iVar1));
    param_1[0x3e] = uVar2;
  }
  FUN_000b793c(uVar2);
  *(undefined1 *)(param_1 + 0xf) = 0;
  *(undefined1 *)((int)param_1 + 0x3d) = 0;
  param_1[0x10] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0x3f800000;
  param_1[0x18] = 0;
  return param_1;
}
// near miss from lane fm9 (unreviewed)

/* HSTMATCH module=hstp_trans_main.prx start=0x0011678c end=0x00116848 symbol=FUN_0011678c lang=c99 */
/* Clone of src/eboot/FUN_0010ee50.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined DAT_0037ffe4;
extern undefined DAT_003b0cd4;
extern undefined DAT_003b10c0;
extern undefined4 DAT_003ba2c4;
extern void FUN_00042ee8();
extern void FUN_00042fb0();
extern undefined4 * FUN_001096ac();

undefined4 * FUN_0011678c(undefined4 *param_1)
{
  FUN_001096ac(param_1,&DAT_0037ffe4);
  *param_1 = (int)(&DAT_003b0cd4);
  *param_1 = (int)(&DAT_003b10c0);
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  *(undefined2 *)(param_1 + 0x36) = 0;
  param_1[0x37] = 0x3f800000;
  param_1[0x38] = 0x3f800000;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  *(undefined1 *)(param_1 + 0x3b) = 0;
  *(undefined2 *)((int)param_1 + 0xee) = 0;
  *(undefined2 *)(param_1 + 0x3c) = 0;
  *(undefined2 *)((int)param_1 + 0xf2) = 0xffe0;
  *(undefined2 *)(param_1 + 0x3d) = 0x10;
  param_1[0x3e] = 0;
  *(undefined2 *)(param_1 + 0x23f) = 0;
  param_1[0x240] = 0;
  param_1[0x241] = 0;
  *(undefined2 *)(param_1 + 0x242) = 0xffff;
  *(undefined1 *)((int)param_1 + 0x90a) = 1;
  FUN_00042ee8(DAT_003ba2c4);
  FUN_00042fb0(DAT_003ba2c4);
  return param_1;
}

/* HSTMATCH module=EBOOT.BIN start=0x000ea41c end=0x000ea62c symbol=FUN_000ea41c lang=c99 */
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

extern undefined DAT_003076f0;
extern undefined4 * FUN_0001f06c();
extern void FUN_000ea868();

undefined4 * FUN_000ea41c(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4, undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8, undefined4 *puStackX_0)
{
  int iVar1;
  
  FUN_0001f06c(param_1);
  *param_1 = (unsigned int)(&DAT_003076f0);
  param_1[0xf] = param_2;
  FUN_000ea868((int)param_1);
  param_1[0x474] = 0;
  param_1[0x1c] = *param_5;
  param_1[0x1d] = param_5[1];
  param_1[0x1e] = param_5[2];
  param_1[0x1f] = param_5[3];
  iVar1 = param_1[0x474];
  param_1[iVar1 * 0x1c + 0x20] = *param_6;
  param_1[iVar1 * 0x1c + 0x21] = param_6[1];
  param_1[iVar1 * 0x1c + 0x22] = param_6[2];
  param_1[iVar1 * 0x1c + 0x23] = param_6[3];
  iVar1 = param_1[0x474];
  param_1[iVar1 * 0x1c + 0x14] = *param_3;
  param_1[iVar1 * 0x1c + 0x15] = param_3[1];
  param_1[iVar1 * 0x1c + 0x16] = param_3[2];
  param_1[iVar1 * 0x1c + 0x17] = param_3[3];
  iVar1 = param_1[0x474];
  param_1[iVar1 * 0x1c + 0x18] = *param_4;
  param_1[iVar1 * 0x1c + 0x19] = param_4[1];
  param_1[iVar1 * 0x1c + 0x1a] = param_4[2];
  param_1[iVar1 * 0x1c + 0x1b] = param_4[3];
  iVar1 = param_1[0x474];
  param_1[iVar1 * 0x1c + 0x24] = *param_7;
  param_1[iVar1 * 0x1c + 0x25] = param_7[1];
  param_1[iVar1 * 0x1c + 0x26] = param_7[2];
  param_1[iVar1 * 0x1c + 0x27] = param_7[3];
  iVar1 = param_1[0x474];
  param_1[iVar1 * 0x1c + 0x28] = *param_8;
  param_1[iVar1 * 0x1c + 0x29] = param_8[1];
  param_1[iVar1 * 0x1c + 0x2a] = param_8[2];
  param_1[iVar1 * 0x1c + 0x2b] = param_8[3];
  iVar1 = param_1[0x474];
  param_1[iVar1 * 0x1c + 0x2c] = *puStackX_0;
  param_1[iVar1 * 0x1c + 0x2d] = puStackX_0[1];
  param_1[iVar1 * 0x1c + 0x2e] = puStackX_0[2];
  param_1[iVar1 * 0x1c + 0x2f] = puStackX_0[3];
  return param_1;
}
// near miss from lane fm9 (unreviewed)

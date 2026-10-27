/* HSTMATCH module=hstp_trans_main.prx start=0x000bd5ec end=0x000bd6f0 symbol=FUN_000bd5ec lang=c99 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/FUN_000ba2a8.c, same instruction shape: Sharing addresses substituted; its corrections kept: inverted create-result branch, block-scoped cursor and count for the array-clear loop); exact match verified; names and types await human review. */
/* Ad-hoc networking object constructor: vtable DAT_003b06bc, field resets, sceKernelCreateSema("AdhocSema", 0, 1, 1, 0) through FUN_002c7630 with the success/failure log through the next function FUN_000bd6f0. */
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

extern undefined DAT_003b06bc;
extern char DAT_0037b37c[];
extern char DAT_0037b388[];
extern char DAT_0037b3a8[];
extern uint * FUN_000114c0();
extern void FUN_000bd6f0();
extern void FUN_000bee48();
extern int FUN_002c7630();

undefined4 * FUN_000bd5ec(undefined4 *param_1)
{
  int iVar1;
  
  *param_1 = (unsigned int)(&DAT_003b06bc);
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  *(undefined1 *)(param_1 + 0x5e) = 0;
  param_1[0x5b] = 0xffffffff;
  param_1[0x5f] = 0xffffffff;
  param_1[0x66] = 0xffffffff;
  param_1[0x9c] = 0;
  param_1[0xa1] = 0;
  FUN_000bee48();
  param_1[0xd] = 0xffffffff;
  iVar1 = FUN_002c7630(DAT_0037b37c,0,1,1,0);
  if (iVar1 > 0) {
    param_1[0xd] = iVar1;
    FUN_000bd6f0(DAT_0037b388);
    param_1[0x9b] = 0;
  } else {
    FUN_000bd6f0(DAT_0037b3a8,iVar1);
    param_1[0x9b] = 0;
  }
  {
    int count = 0;
    undefined4 *cursor = param_1;
    do {
      cursor[0x8b] = 0;
      cursor[0x8c] = 0;
      cursor[0x8d] = 0;
      cursor[0x8e] = 0;
      cursor[0x8f] = 0;
      cursor[0x90] = 0;
      cursor[0x91] = 0;
      count = count + 8;
      cursor[0x92] = 0;
      cursor = cursor + 8;
    } while (count < 0x10);
  }
  *(undefined1 *)(param_1 + 0x9e) = 0;
  FUN_000114c0(param_1 + 0x9f,0,8);
  return param_1;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x001fb54c end=0x001fb5ec symbol=FUN_001fb54c lang=c99 */
/* Clone of src/eboot/ctor_001ed1dc.c (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: loop counter and pointer declaration order; exact match verified; names and types await human review. */

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

extern undefined DAT_003b27f0;
extern undefined4 * FUN_00061cb0();

undefined4 * FUN_001fb54c(undefined4 *param_1)
{
  uint uVar2;
  undefined4 *puVar1;
  
  FUN_00061cb0();
  *param_1 = (unsigned int)(&DAT_003b27f0);
  param_1[0x24] = 0;
  *(undefined1 *)(param_1 + 0x3a) = 0;
  *(undefined1 *)((int)param_1 + 0xe9) = 0;
  param_1[0x25] = 0;
  *(undefined1 *)(param_1 + 0x26) = 0;
  uVar2 = 0;
  puVar1 = param_1;
  do {
    puVar1[0x27] = 0;
    puVar1[0x28] = 0;
    puVar1[0x29] = 0;
    puVar1[0x2a] = 0x40a00000;
    puVar1[0x2b] = 0x42340000;
    puVar1[0x2c] = 0;
    puVar1[0x2d] = 0x3e4ccccd;
    puVar1[0x2e] = 0x447a0000;
    uVar2 = uVar2 + 1;
    puVar1[0x2f] = 0;
    puVar1 = puVar1 + 9;
  } while (uVar2 < 2);
  param_1[0x39] = 0;
  *(undefined1 *)((int)param_1 + 0xea) = 0;
  return param_1;
}

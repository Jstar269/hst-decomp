/* HSTMATCH module=EBOOT.BIN start=0x000ba2a8 end=0x000ba3ac symbol=FUN_000ba2a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_000ba2a8.c) corrected by hand: inverted the create-result branch and used block-scoped cursor and count locals for the array-clear loop; exact match verified; names and types await human review. */
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

extern undefined DAT_003073f0;
extern char DAT_002d4ab4[];
extern char DAT_002d4ac0[];
extern char DAT_002d4ae0[];
extern uint * FUN_000114c0();
extern void FUN_000ba3ac();
extern void FUN_000bb9d4();
extern int FUN_002b7890();

undefined4 * FUN_000ba2a8(undefined4 *param_1)
{
  int iVar1;
  
  *param_1 = (unsigned int)(&DAT_003073f0);
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
  FUN_000bb9d4();
  param_1[0xd] = 0xffffffff;
  iVar1 = FUN_002b7890(DAT_002d4ab4,0,1,1,0);
  if (iVar1 > 0) {
    param_1[0xd] = iVar1;
    FUN_000ba3ac(DAT_002d4ac0);
    param_1[0x9b] = 0;
  } else {
    FUN_000ba3ac(DAT_002d4ae0,iVar1);
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

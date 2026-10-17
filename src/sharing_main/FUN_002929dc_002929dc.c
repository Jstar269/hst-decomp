/* HSTMATCH module=hstp_trans_main.prx start=0x002929dc end=0x00292bf8 symbol=FUN_002929dc lang=c99 */
/* Clone of src/eboot/FUN_002815c4_002815c4.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: matching idiom: signed-char constants for high-bit byte fields; exact match verified; names and types await human review. */
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

extern undefined DAT_002d10cc;
extern undefined DAT_002d10d0;
extern undefined DAT_002d10d4;
extern void FUN_000133f4();
extern uint FUN_0001342c();
extern uint * FUN_000149a8();
extern undefined1 * FUN_001991d4();
extern int FUN_002c7698();

void FUN_002929dc(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  *(undefined1 *)(param_1 + 0x710) = 0;
  *(undefined1 *)(param_1 + 0x713) = 0;
  *(undefined1 *)(param_1 + 0x711) = 0;
  *(undefined1 *)(param_1 + 0x735) = 0;
  *(undefined1 *)(param_1 + 0x736) = 0;
  *(undefined1 *)(param_1 + 0x737) = 0;
  *(undefined1 *)(param_1 + 0x738) = 0;
  *(undefined4 *)(param_1 + 0x73c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x740) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x744) = 0x40a00000;
  *(undefined1 *)(param_1 + 0x748) = 10;
  *(undefined1 *)(param_1 + 0x749) = 0;
  *(undefined4 *)(param_1 + 0x74c) = 0;
  *(signed char *)(param_1 + 0x714) = (signed char)0xe3;
  *(signed char *)(param_1 + 0x715) = (signed char)0x81;
  *(signed char *)(param_1 + 0x716) = (signed char)0xbf;
  *(signed char *)(param_1 + 0x717) = (signed char)0xe3;
  *(signed char *)(param_1 + 0x718) = (signed char)0x82;
  *(signed char *)(param_1 + 0x719) = (signed char)0x93;
  *(signed char *)(param_1 + 0x71a) = (signed char)0xe3;
  *(signed char *)(param_1 + 0x71b) = (signed char)0x83;
  *(signed char *)(param_1 + 0x71c) = (signed char)0x86;
  *(signed char *)(param_1 + 0x71d) = (signed char)0xe3;
  *(signed char *)(param_1 + 0x71e) = (signed char)0x83;
  *(signed char *)(param_1 + 0x71f) = (signed char)0x8b;
  *(undefined1 *)(param_1 + 0x720) = 0x50;
  *(undefined1 *)(param_1 + 0x830) = 0;
  *(undefined1 *)(param_1 + 0x833) = 0;
  *(undefined1 *)(param_1 + 0x831) = 0;
  *(undefined1 *)(param_1 + 0x855) = 0;
  *(undefined1 *)(param_1 + 0x856) = 0;
  *(undefined1 *)(param_1 + 0x857) = 0;
  *(undefined1 *)(param_1 + 0x858) = 0;
  *(undefined4 *)(param_1 + 0x85c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x860) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x864) = 0x40a00000;
  *(undefined1 *)(param_1 + 0x868) = 10;
  *(undefined1 *)(param_1 + 0x869) = 0;
  *(undefined4 *)(param_1 + 0x86c) = 0;
  *(signed char *)(param_1 + 0x834) = (signed char)0xe3;
  *(signed char *)(param_1 + 0x835) = (signed char)0x81;
  *(signed char *)(param_1 + 0x836) = (signed char)0xbf;
  *(signed char *)(param_1 + 0x837) = (signed char)0xe3;
  *(signed char *)(param_1 + 0x838) = (signed char)0x82;
  *(signed char *)(param_1 + 0x839) = (signed char)0x93;
  *(signed char *)(param_1 + 0x83a) = (signed char)0xe3;
  *(signed char *)(param_1 + 0x83b) = (signed char)0x83;
  *(signed char *)(param_1 + 0x83c) = (signed char)0x86;
  *(signed char *)(param_1 + 0x83d) = (signed char)0xe3;
  *(signed char *)(param_1 + 0x83e) = (signed char)0x83;
  *(signed char *)(param_1 + 0x83f) = (signed char)0x8b;
  *(undefined1 *)(param_1 + 0x840) = 0x50;
  *(undefined1 *)(param_1 + 0x735) = 1;
  *(undefined1 *)(param_1 + 0x855) = 1;
  *(undefined1 *)(param_1 + 0x710) = 1;
  *(undefined1 *)(param_1 + 0x830) = 1;
  iVar1 = (int)(FUN_001991d4(0x13));
  if (*(int *)(iVar1 + 4) == 0) {
    puVar3 = &DAT_002d10d4;
  }
  else if (*(int *)(*(int *)(iVar1 + 8) + 8) < 1) {
    puVar3 = &DAT_002d10d0;
  }
  else if ((*(int **)(iVar1 + 0xc))[1] < 4) {
    puVar3 = &DAT_002d10cc;
  }
  else {
    puVar3 = *(undefined **)(**(int **)(iVar1 + 0xc) + 0xc);
  }
  FUN_000149a8(param_1 + 0x714,puVar3);
  if (*(int *)(iVar1 + 4) == 0) {
    puVar3 = &DAT_002d10d4;
  }
  else if (*(int *)(*(int *)(iVar1 + 8) + 8) < 1) {
    puVar3 = &DAT_002d10d0;
  }
  else if ((*(int **)(iVar1 + 0xc))[1] < 4) {
    puVar3 = &DAT_002d10cc;
  }
  else {
    puVar3 = *(undefined **)(**(int **)(iVar1 + 0xc) + 0xc);
  }
  FUN_000149a8(param_1 + 0x834,puVar3);
  uVar2 = FUN_002c7698();
  FUN_000133f4(uVar2);
  uVar2 = FUN_0001342c();
  *(undefined4 *)(param_1 + 0x74c) = uVar2;
  uVar2 = FUN_0001342c();
  *(undefined4 *)(param_1 + 0x86c) = uVar2;
  return;
}

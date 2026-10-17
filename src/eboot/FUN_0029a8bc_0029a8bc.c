/* HSTMATCH module=EBOOT.BIN start=0x0029a8bc end=0x0029a9a0 symbol=FUN_0029a8bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: shared the owner-field assignment and used an explicit zero allocation case; exact match verified; names and types await human review. */
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

extern undefined DAT_00309e64;
extern undefined4 DAT_0034b328;
extern int FUN_00000bcc();
extern int FUN_00010184();
extern undefined4 * FUN_0001f06c();
extern undefined1 * FUN_0029a9a0();

undefined4 * FUN_0029a8bc(undefined4 *param_1)
{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309e64);
  param_1[0xf] = 0;
  DAT_0034b328 = (unsigned int)(param_1);
  puVar1 = (undefined1 *)FUN_00000bcc(0x2c);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 4) = 0;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0;
    *(undefined4 *)(puVar1 + 0x14) = 0;
    *(undefined4 *)(puVar1 + 0x18) = 0;
    *(undefined4 *)(puVar1 + 0x1c) = 0;
    *(undefined4 *)(puVar1 + 0x20) = 0;
    puVar1[0x24] = 0;
    *(undefined4 *)(puVar1 + 0x28) = 0;
    iVar2 = FUN_00000bcc(0x1583c);
    switch (iVar2) {
    case 0:
      *(undefined4 *)(puVar1 + 0xc) = iVar2;
      break;
    default:
      uVar3 = (unsigned int)(FUN_0029a9a0(iVar2));
      *(undefined4 *)(puVar1 + 0xc) = uVar3;
      break;
    }
    uVar3 = FUN_00000bcc(0x2c4);
    *(undefined4 *)(puVar1 + 0x10) = uVar3;
    uVar3 = FUN_00000bcc(0x50);
    *(undefined4 *)(puVar1 + 0x14) = uVar3;
    uVar3 = FUN_00000bcc(100);
    *(undefined4 *)(puVar1 + 0x18) = uVar3;
    uVar3 = FUN_00010184(0x40,0x216e00);
    *(undefined4 *)(puVar1 + 0x1c) = uVar3;
  }
  param_1[0xf] = (unsigned int)(puVar1);
  return param_1;
}

/* HSTMATCH module=EBOOT.BIN start=0x001eadb0 end=0x001eb000 symbol=FUN_001eadb0 lang=c99 */
// NEAR 147: generated draft only (134 of 148 words). Retail keeps a bool (lbu 69(v0);
// sltu; xori 1; andi 0xff) and walks several 4-byte-stepped arrays of object pointers at
// self+0x58 / +0x54 calling virtual slot 0xc with argument 1 or 0; the frame is 96 bytes
// with 16 saved words of locals. Our draft's three loops are close in shape but the
// induction variables, the bool and the +0x58/+0x54 walk start/stop points all differ.
// Next step: rewrite from the retail disassembly with the loop counters as explicit
// locals declared before the bool, and check the vtable slot with MWCC-NOTES' rule that
// declared virtual i sits at 4*(i+2).

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

extern undefined * DAT_00338b44;
extern undefined DAT_003417b8;
extern undefined4 * FUN_00022498();
extern bool FUN_000def58();
extern void FUN_0010d4a8();
extern void FUN_001eb000();

void FUN_001eadb0(int param_1)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 local_4;
  undefined4 local_8;
  undefined4 local_c;
  undefined4 local_10;
  undefined4 local_14;
  undefined4 local_18;
  undefined4 local_1c;
  undefined4 local_20;
  undefined4 local_24;
  undefined4 local_28;
  undefined4 local_2c;
  undefined4 local_30;
  undefined4 local_34;
  undefined4 local_38;
  undefined4 local_3c;
  undefined4 local_40;
  
  FUN_000def58(DAT_00338b44);
  uVar4 = 1;
  bVar1 = *(char *)(DAT_00338b44 + 0x45) != '\0';
  iVar3 = param_1;
  do {
    (**(code **)(**(int **)(iVar3 + 0x58) + 0xc))(*(int **)(iVar3 + 0x58),1);
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar4 < 7);
  if (bVar1) {
    iVar5 = 1;
    iVar3 = param_1;
    do {
      (**(code **)(**(int **)(iVar3 + 0x58) + 0xc))(*(int **)(iVar3 + 0x58),0);
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar5 < 3);
  }
  else {
    iVar5 = 3;
    iVar3 = param_1 + 0xc;
    do {
      (**(code **)(**(int **)(iVar3 + 0x54) + 0xc))(*(int **)(iVar3 + 0x54),0);
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar5 < 7);
  }
  if (bVar1) {
    iVar5 = 0;
    puVar6 = &DAT_003417b8;
    iVar3 = param_1;
    do {
      iVar2 = *(int *)(iVar3 + 0x284);
      *(undefined1 **)(iVar2 + 0xf8) = puVar6 + 0xe4;
      *(undefined4 *)(iVar2 + 0x138) = 1;
      FUN_0010d4a8();
      iVar2 = *(int *)(iVar3 + 0x284);
      *(undefined4 *)(iVar2 + 0x118) = 0x80808080;
      local_10 = 0x43000000;
      local_c = 0x43000000;
      local_8 = 0x43000000;
      local_4 = 0x43000000;
      FUN_00022498(0x3c03126f,&local_30,&local_10);
      *(undefined4 *)(iVar2 + 0x120) = local_30;
      *(undefined4 *)(iVar2 + 0x124) = local_2c;
      *(undefined4 *)(iVar2 + 0x128) = local_28;
      *(undefined4 *)(iVar2 + 300) = local_24;
      FUN_001eb000(param_1,iVar5,0);
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 4;
      puVar6 = puVar6 + 0x120;
    } while (iVar5 < 2);
  }
  else {
    iVar5 = 0;
    puVar6 = &DAT_003417b8;
    iVar3 = param_1;
    do {
      iVar2 = *(int *)(iVar3 + 0x28c);
      *(undefined1 **)(iVar2 + 0xf8) = puVar6 + 0xe4;
      *(undefined4 *)(iVar2 + 0x138) = 1;
      FUN_0010d4a8();
      iVar2 = *(int *)(iVar3 + 0x28c);
      *(undefined4 *)(iVar2 + 0x118) = 0x80808080;
      local_20 = 0x43000000;
      local_1c = 0x43000000;
      local_18 = 0x43000000;
      local_14 = 0x43000000;
      FUN_00022498(0x3c03126f,&local_40,&local_20);
      *(undefined4 *)(iVar2 + 0x120) = local_40;
      *(undefined4 *)(iVar2 + 0x124) = local_3c;
      *(undefined4 *)(iVar2 + 0x128) = local_38;
      *(undefined4 *)(iVar2 + 300) = local_34;
      FUN_001eb000(param_1,iVar5,1);
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 4;
      puVar6 = puVar6 + 0x120;
    } while (iVar5 < 4);
  }
  return;
}
// near miss from lane fm7 (unreviewed)

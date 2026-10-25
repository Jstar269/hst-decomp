/* HSTMATCH module=EBOOT.BIN start=0x001ff69c end=0x001ffcc0 symbol=FUN_001ff69c lang=c99 */
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

extern undefined4 FUN_002175a4();

int FUN_001ff69c(int param_1)
{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined4 *puVar9;
  
  puVar2 = (undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 8) = 0;
  if (puVar2 < (undefined4 *)(param_1 + 0x30)) {
    uVar7 = (param_1 + 0x30) - (param_1 + 0xcU);
    uVar6 = uVar7 + 3;
    uVar3 = uVar6;
    if ((int)uVar6 < 0) {
      uVar3 = uVar7 + 6;
    }
    uVar4 = ((int)uVar3 >> 2) + 1;
    if (8 < (int)uVar4) {
      bVar1 = false;
      bVar5 = false;
      if (param_1 + 0xcU <= param_1 + 0x30U) {
        bVar8 = true;
        if (((uVar7 & 0x80000000) == 0) && ((uVar6 & 0x80000000) != 0)) {
          bVar8 = false;
        }
        if (bVar8) {
          bVar5 = true;
        }
      }
      if (bVar5) {
        bVar5 = true;
        if ((((int)uVar3 >> 2 & 0x80000000U) == 0) && ((uVar4 & 0x80000000) != 0)) {
          bVar5 = false;
        }
        if (bVar5) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        *puVar2 = 0;
        while( true ) {
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
          puVar2[4] = 0;
          puVar2[5] = 0;
          puVar2[6] = 0;
          puVar2[7] = 0;
          puVar2 = puVar2 + 8;
          if ((undefined4 *)(param_1 + 0x10) <= puVar2) break;
          *puVar2 = 0;
        }
      }
    }
    if ((undefined4 *)(param_1 + 0x30) <= puVar2) {
      *(undefined4 *)(param_1 + 0x30) = 0;
      goto LAB_001ff7c4;
    }
    *puVar2 = 0;
    while (puVar2 = puVar2 + 1, puVar2 < (undefined4 *)(param_1 + 0x30)) {
      *puVar2 = 0;
    }
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
LAB_001ff7c4:
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x44);
  puVar9 = (undefined4 *)(param_1 + 0x648);
  *(undefined4 *)(param_1 + 0x40) = 0;
  if (puVar2 < puVar9) {
    uVar4 = (int)puVar9 - (param_1 + 0x44);
    uVar7 = uVar4 + 0x13;
    uVar3 = (int)uVar7 / 0x14;
    uVar6 = uVar3 + 1;
    if (8 < (int)uVar6) {
      bVar1 = false;
      bVar5 = false;
      if ((undefined4 *)(param_1 + 0x44) <= puVar9) {
        bVar8 = true;
        if (((uVar4 & 0x80000000) == 0) && ((uVar7 & 0x80000000) != 0)) {
          bVar8 = false;
        }
        if (bVar8) {
          bVar5 = true;
        }
      }
      if (bVar5) {
        bVar5 = true;
        if (((uVar3 & 0x80000000) == 0) && ((uVar6 & 0x80000000) != 0)) {
          bVar5 = false;
        }
        if (bVar5) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        *puVar2 = 0;
        while( true ) {
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
          puVar2[4] = 0;
          puVar2[5] = 0;
          puVar2[6] = 0;
          puVar2[7] = 0;
          puVar2[8] = 0;
          puVar2[9] = 0;
          puVar2[10] = 0;
          puVar2[0xb] = 0;
          puVar2[0xc] = 0;
          puVar2[0xd] = 0;
          puVar2[0xe] = 0;
          puVar2[0xf] = 0;
          puVar2[0x10] = 0;
          puVar2[0x11] = 0;
          puVar2[0x12] = 0;
          puVar2[0x13] = 0;
          puVar2[0x14] = 0;
          puVar2[0x15] = 0;
          puVar2[0x16] = 0;
          puVar2[0x17] = 0;
          puVar2[0x18] = 0;
          puVar2[0x19] = 0;
          puVar2[0x1a] = 0;
          puVar2[0x1b] = 0;
          puVar2[0x1c] = 0;
          puVar2[0x1d] = 0;
          puVar2[0x1e] = 0;
          puVar2[0x1f] = 0;
          puVar2[0x20] = 0;
          puVar2[0x21] = 0;
          puVar2[0x22] = 0;
          puVar2[0x23] = 0;
          puVar2[0x24] = 0;
          puVar2[0x25] = 0;
          puVar2[0x26] = 0;
          puVar2[0x27] = 0;
          puVar2 = puVar2 + 0x28;
          if ((undefined4 *)(param_1 + 0x5a8) <= puVar2) break;
          *puVar2 = 0;
        }
      }
    }
    if (puVar2 < (undefined4 *)(param_1 + 0x648)) {
      *puVar2 = 0;
      while( true ) {
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        puVar2[4] = 0;
        puVar2 = puVar2 + 5;
        if ((undefined4 *)(param_1 + 0x648) <= puVar2) break;
        *puVar2 = 0;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x648) = 0;
  *(undefined4 *)(param_1 + 0x64c) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x654);
  puVar9 = (undefined4 *)(param_1 + 0x6e4);
  *(undefined4 *)(param_1 + 0x650) = 0;
  if (puVar2 < puVar9) {
    uVar4 = (int)puVar9 - (param_1 + 0x654);
    uVar7 = uVar4 + 0xb;
    uVar3 = (int)uVar7 / 0xc;
    uVar6 = uVar3 + 1;
    if (8 < (int)uVar6) {
      bVar1 = false;
      bVar5 = false;
      if ((undefined4 *)(param_1 + 0x654) <= puVar9) {
        bVar8 = true;
        if (((uVar4 & 0x80000000) == 0) && ((uVar7 & 0x80000000) != 0)) {
          bVar8 = false;
        }
        if (bVar8) {
          bVar5 = true;
        }
      }
      if (bVar5) {
        bVar5 = true;
        if (((uVar3 & 0x80000000) == 0) && ((uVar6 & 0x80000000) != 0)) {
          bVar5 = false;
        }
        if (bVar5) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        *puVar2 = 0;
        while( true ) {
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
          puVar2[4] = 0;
          puVar2[5] = 0;
          puVar2[6] = 0;
          puVar2[7] = 0;
          puVar2[8] = 0;
          puVar2[9] = 0;
          puVar2[10] = 0;
          puVar2[0xb] = 0;
          puVar2[0xc] = 0;
          puVar2[0xd] = 0;
          puVar2[0xe] = 0;
          puVar2[0xf] = 0;
          puVar2[0x10] = 0;
          puVar2[0x11] = 0;
          puVar2[0x12] = 0;
          puVar2[0x13] = 0;
          puVar2[0x14] = 0;
          puVar2[0x15] = 0;
          puVar2[0x16] = 0;
          puVar2[0x17] = 0;
          puVar2 = puVar2 + 0x18;
          if ((undefined4 *)(param_1 + 0x684) <= puVar2) break;
          *puVar2 = 0;
        }
      }
    }
    if (puVar2 < (undefined4 *)(param_1 + 0x6e4)) {
      *puVar2 = 0;
      while( true ) {
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2 = puVar2 + 3;
        if ((undefined4 *)(param_1 + 0x6e4) <= puVar2) break;
        *puVar2 = 0;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x6e4) = 0;
  *(undefined4 *)(param_1 + 0x6e8) = 0;
  puVar2 = (undefined4 *)(param_1 + 0x6f0);
  puVar9 = (undefined4 *)(param_1 + 0x708);
  *(undefined4 *)(param_1 + 0x6ec) = 0;
  if (puVar2 < puVar9) {
    uVar4 = (int)puVar9 - (param_1 + 0x6f0);
    uVar7 = uVar4 + 0xb;
    uVar3 = (int)uVar7 / 0xc;
    uVar6 = uVar3 + 1;
    if (8 < (int)uVar6) {
      bVar1 = false;
      bVar5 = false;
      if ((undefined4 *)(param_1 + 0x6f0) <= puVar9) {
        bVar8 = true;
        if (((uVar4 & 0x80000000) == 0) && ((uVar7 & 0x80000000) != 0)) {
          bVar8 = false;
        }
        if (bVar8) {
          bVar5 = true;
        }
      }
      if (bVar5) {
        bVar5 = true;
        if (((uVar3 & 0x80000000) == 0) && ((uVar6 & 0x80000000) != 0)) {
          bVar5 = false;
        }
        if (bVar5) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        *puVar2 = 0;
        while( true ) {
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
          puVar2[4] = 0;
          puVar2[5] = 0;
          puVar2[6] = 0;
          puVar2[7] = 0;
          puVar2[8] = 0;
          puVar2[9] = 0;
          puVar2[10] = 0;
          puVar2[0xb] = 0;
          puVar2[0xc] = 0;
          puVar2[0xd] = 0;
          puVar2[0xe] = 0;
          puVar2[0xf] = 0;
          puVar2[0x10] = 0;
          puVar2[0x11] = 0;
          puVar2[0x12] = 0;
          puVar2[0x13] = 0;
          puVar2[0x14] = 0;
          puVar2[0x15] = 0;
          puVar2[0x16] = 0;
          puVar2[0x17] = 0;
          puVar2 = puVar2 + 0x18;
          if ((undefined4 *)(param_1 + 0x6a8) <= puVar2) break;
          *puVar2 = 0;
        }
      }
    }
    if (puVar2 < (undefined4 *)(param_1 + 0x708)) {
      *puVar2 = 0;
      while( true ) {
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2 = puVar2 + 3;
        if ((undefined4 *)(param_1 + 0x708) <= puVar2) break;
        *puVar2 = 0;
      }
    }
  }
  FUN_002175a4(param_1 + 0x718);
  FUN_002175a4(param_1 + 0x7a4);
  FUN_002175a4(param_1 + 0x830);
  FUN_002175a4(param_1 + 0x8bc);
  FUN_002175a4(param_1 + 0x948);
  FUN_002175a4(param_1 + 0x9d4);
  FUN_002175a4(param_1 + 0xa60);
  FUN_002175a4(param_1 + 0xaec);
  FUN_002175a4(param_1 + 0xb78);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x70c) = 0;
  *(undefined4 *)(param_1 + 0x710) = 0;
  return param_1;
}
// near miss from lane fm11 (unreviewed)

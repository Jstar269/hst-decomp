/* HSTMATCH module=EBOOT.BIN start=0x001bf1cc end=0x001bf62c symbol=FUN_001bf1cc lang=c99 */
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


void FUN_001bf1cc(undefined4 *param_1,undefined4 *param_2,undefined1 *param_3,int param_4, undefined1 *param_5,int param_6,int param_7,int param_8,int iStackX_0,int iStackX_4 ,int iStackX_8,int iStackX_c)
{
  bool bVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  *param_1 = *param_2;
  iVar5 = 0;
  if (0 < param_4) {
    if (param_4 < 9) {
LAB_001bf2c8:
      bVar1 = iVar5 < param_4;
    }
    else {
      bVar1 = false;
      if ((-1 < param_4) && (param_4 < 0x7fffffff)) {
        bVar1 = true;
      }
      puVar2 = param_1;
      puVar3 = param_3;
      if (bVar1) {
        do {
          iVar5 = iVar5 + 8;
          *(undefined1 *)(puVar2 + 1) = *puVar3;
          puVar2[2] = *(undefined4 *)(puVar3 + 4);
          *(undefined1 *)(puVar2 + 0xf) = puVar3[0x38];
          puVar2[0x10] = *(undefined4 *)(puVar3 + 0x3c);
          *(undefined1 *)(puVar2 + 0x1d) = puVar3[0x70];
          puVar2[0x1e] = *(undefined4 *)(puVar3 + 0x74);
          *(undefined1 *)(puVar2 + 0x2b) = puVar3[0xa8];
          puVar2[0x2c] = *(undefined4 *)(puVar3 + 0xac);
          *(undefined1 *)(puVar2 + 0x39) = puVar3[0xe0];
          puVar2[0x3a] = *(undefined4 *)(puVar3 + 0xe4);
          *(undefined1 *)(puVar2 + 0x47) = puVar3[0x118];
          puVar2[0x48] = *(undefined4 *)(puVar3 + 0x11c);
          *(undefined1 *)(puVar2 + 0x55) = puVar3[0x150];
          puVar2[0x56] = *(undefined4 *)(puVar3 + 0x154);
          *(undefined1 *)(puVar2 + 99) = puVar3[0x188];
          puVar2[100] = *(undefined4 *)(puVar3 + 0x18c);
          puVar2 = puVar2 + 0x70;
          puVar3 = puVar3 + 0x1c0;
        } while (iVar5 < param_4 + -8);
        goto LAB_001bf2c8;
      }
      bVar1 = 0 < param_4;
    }
    if (bVar1) {
      param_3 = param_3 + iVar5 * 0x38;
      puVar2 = param_1 + iVar5 * 0xe;
      do {
        iVar5 = iVar5 + 1;
        *(undefined1 *)(puVar2 + 1) = *param_3;
        puVar2[2] = *(undefined4 *)(param_3 + 4);
        param_3 = param_3 + 0x38;
        puVar2 = puVar2 + 0xe;
      } while (iVar5 < param_4);
    }
  }
  iVar5 = 0;
  if (0 < param_6) {
    if (param_6 < 9) {
LAB_001bf3a8:
      bVar1 = iVar5 < param_6;
    }
    else {
      bVar1 = false;
      if ((-1 < param_6) && (param_6 < 0x7fffffff)) {
        bVar1 = true;
      }
      puVar2 = param_1;
      puVar3 = param_5;
      if (bVar1) {
        do {
          iVar5 = iVar5 + 8;
          *(undefined1 *)(puVar2 + 0xd3) = *puVar3;
          *(undefined1 *)((int)puVar2 + 0x34e) = puVar3[2];
          *(undefined1 *)(puVar2 + 0xd4) = puVar3[4];
          *(undefined1 *)((int)puVar2 + 0x352) = puVar3[6];
          *(undefined1 *)(puVar2 + 0xd5) = puVar3[8];
          *(undefined1 *)((int)puVar2 + 0x356) = puVar3[10];
          *(undefined1 *)(puVar2 + 0xd6) = puVar3[0xc];
          *(undefined1 *)((int)puVar2 + 0x35a) = puVar3[0xe];
          puVar2 = puVar2 + 4;
          puVar3 = puVar3 + 0x10;
        } while (iVar5 < param_6 + -8);
        goto LAB_001bf3a8;
      }
      bVar1 = 0 < param_6;
    }
    if (bVar1) {
      param_5 = param_5 + iVar5 * 2;
      iVar4 = (int)param_1 + iVar5 * 2;
      do {
        iVar5 = iVar5 + 1;
        *(undefined1 *)(iVar4 + 0x34c) = *param_5;
        param_5 = param_5 + 2;
        iVar4 = iVar4 + 2;
      } while (iVar5 < param_6);
    }
  }
  iVar5 = 0;
  if (0 < param_8) {
    if (param_8 < 9) {
LAB_001bf470:
      bVar1 = iVar5 < param_8;
    }
    else {
      bVar1 = false;
      if ((-1 < param_8) && (param_8 < 0x7fffffff)) {
        bVar1 = true;
      }
      iVar4 = iVar5;
      if (bVar1) {
        do {
          puVar3 = (undefined1 *)(param_7 + iVar4);
          iVar5 = iVar4 + 8;
          *(undefined1 *)((int)param_1 + iVar4 + 0x84c) = *puVar3;
          *(undefined1 *)((int)param_1 + iVar4 + 0x84d) = puVar3[1];
          *(undefined1 *)((int)param_1 + iVar4 + 0x84e) = puVar3[2];
          *(undefined1 *)((int)param_1 + iVar4 + 0x84f) = puVar3[3];
          *(undefined1 *)((int)param_1 + iVar4 + 0x850) = puVar3[4];
          *(undefined1 *)((int)param_1 + iVar4 + 0x851) = puVar3[5];
          *(undefined1 *)((int)param_1 + iVar4 + 0x852) = puVar3[6];
          *(undefined1 *)((int)param_1 + iVar4 + 0x853) = puVar3[7];
          iVar4 = iVar5;
        } while (iVar5 < param_8 + -8);
        goto LAB_001bf470;
      }
      bVar1 = 0 < param_8;
    }
    if (bVar1) {
      do {
        iVar4 = iVar5 + 1;
        *(undefined1 *)((int)param_1 + iVar5 + 0x84c) = *(undefined1 *)(param_7 + iVar5);
        iVar5 = iVar4;
      } while (iVar4 < param_8);
    }
  }
  iVar5 = 0;
  if (0 < iStackX_4) {
    if (iStackX_4 < 9) {
LAB_001bf530:
      bVar1 = iVar5 < iStackX_4;
    }
    else {
      bVar1 = false;
      if ((-1 < iStackX_4) && (iStackX_4 < 0x7fffffff)) {
        bVar1 = true;
      }
      iVar4 = iVar5;
      if (bVar1) {
        do {
          puVar3 = (undefined1 *)(iStackX_0 + iVar4);
          iVar5 = iVar4 + 8;
          *(undefined1 *)((int)param_1 + iVar4 + 0xacc) = *puVar3;
          *(undefined1 *)((int)param_1 + iVar4 + 0xacd) = puVar3[1];
          *(undefined1 *)((int)param_1 + iVar4 + 0xace) = puVar3[2];
          *(undefined1 *)((int)param_1 + iVar4 + 0xacf) = puVar3[3];
          *(undefined1 *)((int)param_1 + iVar4 + 0xad0) = puVar3[4];
          *(undefined1 *)((int)param_1 + iVar4 + 0xad1) = puVar3[5];
          *(undefined1 *)((int)param_1 + iVar4 + 0xad2) = puVar3[6];
          *(undefined1 *)((int)param_1 + iVar4 + 0xad3) = puVar3[7];
          iVar4 = iVar5;
        } while (iVar5 < iStackX_4 + -8);
        goto LAB_001bf530;
      }
      bVar1 = 0 < iStackX_4;
    }
    if (bVar1) {
      do {
        iVar4 = iVar5 + 1;
        *(undefined1 *)((int)param_1 + iVar5 + 0xacc) = *(undefined1 *)(iStackX_0 + iVar5);
        iVar5 = iVar4;
      } while (iVar4 < iStackX_4);
    }
  }
  iVar5 = 0;
  if (iStackX_c < 1) {
    return;
  }
  if (8 < iStackX_c) {
    bVar1 = false;
    if ((-1 < iStackX_c) && (iStackX_c < 0x7fffffff)) {
      bVar1 = true;
    }
    iVar4 = iVar5;
    if (!bVar1) {
      bVar1 = 0 < iStackX_c;
      goto LAB_001bf5f4;
    }
    do {
      puVar3 = (undefined1 *)(iStackX_8 + iVar4);
      iVar5 = iVar4 + 8;
      *(undefined1 *)((int)param_1 + iVar4 + 0xd4c) = *puVar3;
      *(undefined1 *)((int)param_1 + iVar4 + 0xd4d) = puVar3[1];
      *(undefined1 *)((int)param_1 + iVar4 + 0xd4e) = puVar3[2];
      *(undefined1 *)((int)param_1 + iVar4 + 0xd4f) = puVar3[3];
      *(undefined1 *)((int)param_1 + iVar4 + 0xd50) = puVar3[4];
      *(undefined1 *)((int)param_1 + iVar4 + 0xd51) = puVar3[5];
      *(undefined1 *)((int)param_1 + iVar4 + 0xd52) = puVar3[6];
      *(undefined1 *)((int)param_1 + iVar4 + 0xd53) = puVar3[7];
      iVar4 = iVar5;
    } while (iVar5 < iStackX_c + -8);
  }
  bVar1 = iVar5 < iStackX_c;
LAB_001bf5f4:
  if (bVar1) {
    do {
      iVar4 = iVar5 + 1;
      *(undefined1 *)((int)param_1 + iVar5 + 0xd4c) = *(undefined1 *)(iStackX_8 + iVar5);
      iVar5 = iVar4;
    } while (iVar4 < iStackX_c);
  }
  return;
}
// near miss from lane fm11 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x001f10ec end=0x001f14a4 symbol=FUN_001f10ec lang=c99 */
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

extern undefined * DAT_002cfc8c;
extern int DAT_002ee858;
extern undefined4 DAT_002ee85c;
extern undefined DAT_0034179c;
extern int FUN_001b1c44();
extern int FUN_001b2af0();
extern void FUN_001e09dc();
extern void FUN_001e28e0();
extern void FUN_001e2990();
extern void FUN_001e5f50();
extern void FUN_001e611c();
extern void FUN_001e6ffc();
extern void FUN_001e70e0();
extern undefined4 FUN_001e70e8();
extern undefined4 FUN_001e7140();
extern void FUN_001f0fb4();
extern void FUN_001f44ec();
extern void FUN_001f4584();
extern void FUN_001f47a4();
extern void FUN_001f4bfc();
extern void FUN_001f4e40();

void FUN_001f10ec(int param_1)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x44) == 0) {
    *(undefined4 *)(param_1 + 0x12dc) = 1;
    *(undefined4 *)(param_1 + 0x1360) = 0;
    FUN_001f4584(param_1,0);
    FUN_001f4e40(param_1,*(int *)(param_1 + 0x3c4));
    FUN_001e09dc(*(int *)(param_1 + 0x510),2);
    FUN_001e2990(*(int *)(param_1 + 0x510));
    if (*(int *)(*(int *)(param_1 + 0x135c) * 0xc + param_1 + 0x12e0) == 5) {
      *(undefined1 *)(param_1 + 0x1364) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x1364) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x135c) * 0xc + param_1;
    FUN_001e5f50(*(int *)(param_1 + 0x510),*(undefined4 *)(iVar2 + 0x12e0),
                 *(undefined4 *)(iVar2 + 0x12e4),(uint)*(byte *)(iVar2 + 0x12e8));
    FUN_001e6ffc(*(int *)(param_1 + 0x510),
                 *(int *)(*(int *)(param_1 + 0x135c) * 0xc + param_1 + 0x12e0));
    if (*(char *)(*(int *)(param_1 + 0x135c) * 0xc + param_1 + 0x12e8) == '\0') {
      iVar2 = FUN_001b2af0((int *)&DAT_0034179c,0xc);
      *(int *)(param_1 + 0x5b8) = iVar2;
    }
    else {
      iVar2 = FUN_001b2af0((int *)&DAT_0034179c,0xd);
      *(int *)(param_1 + 0x5b8) = iVar2;
    }
  }
  if (*(int *)(param_1 + 0x12dc) != 2) {
    if (*(int *)(param_1 + 0x12dc) == 1) {
      iVar2 = *(int *)(param_1 + 0x1360) + 1;
      *(int *)(param_1 + 0x1360) = iVar2;
      if (iVar2 == 5) {
        FUN_001e611c(*(int *)(param_1 + 0x510),(uint)*(byte *)(param_1 + 0x1364));
      }
      if (0x1e < *(int *)(param_1 + 0x1360)) {
        *(undefined4 *)(param_1 + 0x12dc) = 2;
        *(undefined4 *)(param_1 + 0x1360) = 0;
      }
    }
    goto LAB_001f1484;
  }
  iVar3 = *(int *)(param_1 + 0x1360) + 1;
  *(int *)(param_1 + 0x1360) = iVar3;
  iVar2 = DAT_002ee858;
  if ((DAT_002ee858 <= iVar3) && (iVar2 = DAT_002ee85c, iVar3 <= DAT_002ee85c)) {
    iVar2 = iVar3;
  }
  *(int *)(param_1 + 0x1360) = iVar2;
  if (iVar2 == 6) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x510) + 0x1b30);
    if (iVar2 == 3) {
      bVar1 = true;
    }
    else if ((iVar2 == 2) || (iVar2 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_001e70e0(*(int *)(param_1 + 0x510));
      goto LAB_001f12f8;
    }
    iVar2 = *(int *)(param_1 + 0x1360);
  }
  else {
LAB_001f12f8:
    iVar2 = *(int *)(param_1 + 0x1360);
  }
  if (iVar2 == 10) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x510) + 0x1b30);
    if (iVar2 == 3) {
      bVar1 = true;
    }
    else if ((iVar2 == 2) || (iVar2 == 1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      FUN_001e28e0(*(int *)(param_1 + 0x510));
    }
    iVar2 = *(int *)(param_1 + 0x510);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x510);
  }
  iVar3 = *(int *)(iVar2 + 0x1b30);
  if (iVar3 == 3) {
    bVar1 = true;
  }
  else if ((iVar3 == 2) || (iVar3 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    iVar2 = FUN_001e7140(iVar2);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x1360);
    }
    else {
      FUN_001f44ec(param_1,0);
      iVar2 = *(int *)(param_1 + 0x1360);
    }
    if ((10 < iVar2) && (iVar2 = FUN_001e70e8(*(int *)(param_1 + 0x510)), iVar2 != 0)) {
      FUN_001e28e0(*(int *)(param_1 + 0x510));
      if (*(char *)(param_1 + 0x58c) == '\0') {
        bVar1 = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_001b1c44((int *)&DAT_0034179c,3);
        FUN_001f0fb4(param_1);
      }
    }
  }
  else if (10 < *(int *)(param_1 + 0x1360)) {
    if (*(char *)(param_1 + 0x58c) == '\0') {
      bVar1 = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_001b1c44((int *)&DAT_0034179c,3);
      FUN_001f0fb4(param_1);
    }
  }
LAB_001f1484:
  FUN_001f4bfc();
  FUN_001f47a4(param_1);
  return;
}
// near miss from lane fm11 (unreviewed)

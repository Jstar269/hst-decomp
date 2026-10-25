/* HSTMATCH module=EBOOT.BIN start=0x002182a0 end=0x0021869c symbol=FUN_002182a0 lang=c99 */
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

extern undefined * DAT_00341508;
extern uint FUN_00165004();

void FUN_002182a0(undefined4 *param_1,int param_2,int param_3,int param_4)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  
  if (param_4 == 0) {
    iVar2 = (int)*(short *)(*(int *)(DAT_00341508 + param_3 * 0x18 + 0xc) + param_2 * 2);
  }
  else {
    iVar2 = FUN_00165004(DAT_00341508 + param_3 * 0x18,param_4);
  }
  iVar3 = *(int *)(DAT_00341508 + param_3 * 0x18);
  *param_1 = 0xff;
  param_1[1] = 0xff;
  param_1[2] = 0xff;
  param_1[3] = 0xff;
  iVar3 = iVar3 + iVar2 * 0x22c;
  bVar1 = *(char *)(iVar3 + 0x21c) == '\x01';
  if (bVar1) {
    *param_1 = 0;
  }
  uVar4 = (uint)bVar1;
  if (*(char *)(iVar3 + 0x21d) == '\x01') {
    param_1[uVar4] = 1;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x21e);
  if (cVar5 == '\x01') {
    param_1[uVar4] = 2;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x21f);
  if (cVar5 == '\x01') {
    if ((((*(char *)(iVar3 + 0x220) == '\x01') && (*(char *)(iVar3 + 0x221) == '\x01')) &&
        (*(char *)(iVar3 + 0x222) == '\x01')) && (*(char *)(iVar3 + 0x223) == '\x01')) {
      param_1[uVar4] = 3;
      uVar4 = uVar4 + 1;
    }
    cVar5 = *(char *)(iVar3 + 0x224);
  }
  else {
    cVar5 = *(char *)(iVar3 + 0x224);
  }
  if (cVar5 == '\x01') {
    param_1[uVar4] = 4;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x225);
  if (cVar5 == '\x01') {
    param_1[uVar4] = 5;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x226);
  if (cVar5 == '\x01') {
    param_1[uVar4] = 6;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x227);
  if (cVar5 == '\x01') {
    param_1[uVar4] = 7;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x228);
  if (cVar5 == '\x01') {
    param_1[uVar4] = 8;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x229);
  if (cVar5 == '\x01') {
    if ((*(char *)(iVar3 + 0x22a) == '\x01') && (*(char *)(iVar3 + 0x22b) == '\x01')) {
      param_1[uVar4] = 0xc;
      uVar4 = uVar4 + 1;
    }
    cVar5 = *(char *)(iVar3 + 0x21c);
  }
  else {
    cVar5 = *(char *)(iVar3 + 0x21c);
  }
  if (cVar5 == -1) {
    param_1[uVar4] = 0xe;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x21d);
  if (cVar5 == -1) {
    param_1[uVar4] = 0xf;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x21e);
  if (cVar5 == -1) {
    param_1[uVar4] = 0x10;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x21f);
  if (cVar5 == -1) {
    if (((*(char *)(iVar3 + 0x220) == -1) && (*(char *)(iVar3 + 0x221) == -1)) &&
       ((*(char *)(iVar3 + 0x222) == -1 && (*(char *)(iVar3 + 0x223) == -1)))) {
      param_1[uVar4] = 0x11;
      uVar4 = uVar4 + 1;
    }
    cVar5 = *(char *)(iVar3 + 0x224);
  }
  else {
    cVar5 = *(char *)(iVar3 + 0x224);
  }
  if (cVar5 == -1) {
    param_1[uVar4] = 0x12;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x225);
  if (cVar5 == -1) {
    param_1[uVar4] = 0x13;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x226);
  if (cVar5 == -1) {
    param_1[uVar4] = 0x14;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x227);
  if (cVar5 == -1) {
    param_1[uVar4] = 0x15;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x228);
  if (cVar5 == -1) {
    param_1[uVar4] = 0x16;
    uVar4 = uVar4 + 1;
  }
  cVar5 = *(char *)(iVar3 + 0x229);
  if (((cVar5 == -1) && (*(char *)(iVar3 + 0x22a) == -1)) && (*(char *)(iVar3 + 0x22b) == -1)) {
    param_1[uVar4] = 0x1a;
  }
  return;
}
// near miss from lane fm11 (unreviewed)

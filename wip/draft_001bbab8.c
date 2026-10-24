/* HSTMATCH module=EBOOT.BIN start=0x001bbab8 end=0x001bbc58 symbol=FUN_001bbab8 lang=c99 */
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

extern undefined * DAT_003415a8;
extern undefined4 DAT_0034a77c;
extern int FUN_0024dd40(float param_1,int param_2);
extern undefined4 FUN_0024de88();

void FUN_001bbab8(byte *param_1)
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  
  if ((((DAT_003415a8 != 0) && (*param_1 - 4 < 2)) &&
      (iVar7 = (int)*(short *)(param_1 + 2), iVar7 != 0)) && (iVar7 != 0x32)) {
    iVar2 = FUN_0024dd40(*(float *)(param_1 + 4),DAT_0034a77c);
    uVar3 = FUN_0024de88(DAT_0034a77c,5,iVar2);
    uVar4 = FUN_0024de88(DAT_0034a77c,0x10,iVar2);
    iVar6 = (iVar7 / 10) * 10;
    iVar2 = iVar6 + 1;
    if (iVar2 < 0) {
      pbVar5 = (byte *)0x0;
    }
    else if (iVar2 < 0x280) {
      pbVar5 = (byte *)(DAT_003415a8 + 0x80 + iVar2 * 2 + 0x34c);
    }
    else {
      pbVar5 = (byte *)0x0;
    }
    bVar1 = *pbVar5 - 4 < 2;
    if (iVar6 < 0) {
      pbVar5 = (byte *)0x0;
    }
    else if (iVar6 < 0x280) {
      pbVar5 = (byte *)(DAT_003415a8 + 0x80 + (iVar7 / 10) * 0x14 + 0x34c);
    }
    else {
      pbVar5 = (byte *)0x0;
    }
    if ((uVar4 & 0xff) == 0) {
      if ((((uVar3 & 0xff) != 0) && (bVar1)) && (iVar2 < iVar7)) {
        *(short *)(param_1 + 2) = (short)iVar2;
      }
    }
    else if ((*pbVar5 - 4 < 2) && (iVar6 < iVar7)) {
      *(short *)(param_1 + 2) = (short)iVar6;
    }
    else if ((bVar1) && (iVar2 < iVar7)) {
      *(short *)(param_1 + 2) = (short)iVar2;
    }
  }
  return;
}
// near miss from lane fm9 (unreviewed)

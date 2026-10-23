/* HSTMATCH module=EBOOT.BIN start=0x00254908 end=0x00254b58 symbol=FUN_00254908 lang=c99 */
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

extern char DAT_003417b8;
extern int DAT_0034a79c;
extern undefined DAT_0034b340;
extern void FUN_0005743c();
extern void FUN_000575fc();
extern uint FUN_00057b58();
extern void FUN_00058ddc();
extern void FUN_00058ec4();
extern void FUN_00058f38();
extern void FUN_00059084();
extern void FUN_0005f110();
extern void FUN_00091c48();
extern void FUN_00092078(float param_1,int param_2,int param_3,undefined4 param_4,int param_5);

void FUN_00254908(int param_1,int param_2)
{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *row;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  row = (char *)&DAT_003417b8 + param_2 * 0x120;
  piVar5 = (int *)(&DAT_0034b340 + param_2 * 4);
  iVar7 = DAT_0034a79c;
  iVar3 = *(int *)(*piVar5 + 0x50) != 0 ? *(int *)(*(int *)(*piVar5 + 0x50) + 0x1b4) : 0;
  if (iVar3 < 0xf) {
    iVar6 = DAT_0034a79c + (iVar3 + 0xf) * 0x10;
    *(undefined1 *)(param_2 + param_1 + 0x5c) = 0;
    cVar1 = *(row + 0x7e);
    iVar7 = iVar7 + iVar3 * 0x10;
  }
  else {
    if (*(char *)(iVar4 + 0x3417f4) == '\0') {
      iVar7 = DAT_0034a79c + 0x1e0;
      iVar6 = DAT_0034a79c + 0x1f0;
    }
    else {
      iVar7 = DAT_0034a79c + 0x200;
      iVar6 = DAT_0034a79c + 0x210;
    }
    *(undefined1 *)(param_2 + param_1 + 0x5c) = 1;
    cVar1 = *(row + 0x7e);
  }
  bVar2 = cVar1 == '\x02';
  FUN_0005743c(*(undefined4 *)(*piVar5 + 0x58),0,iVar7,1);
  FUN_0005743c(*(undefined4 *)(*piVar5 + 0x58),1,iVar6,1);
  FUN_000575fc(*(int *)(*piVar5 + 0x58),0,bVar2);
  FUN_000575fc(*(int *)(*piVar5 + 0x58),1,bVar2);
  FUN_00092078(-1.0f,*piVar5,0,1,0);
  FUN_00091c48(*piVar5,-1);
  iVar4 = *(int *)(*piVar5 + 100);
  if (iVar4 != 0) {
    FUN_0005743c(iVar4,0,iVar7,1);
    FUN_0005743c(iVar4,1,iVar6,1);
    FUN_000575fc(iVar4,0,bVar2);
    FUN_000575fc(iVar4,1,bVar2);
    FUN_00057b58(0,iVar4,0,0);
    FUN_00058ddc(iVar4,1,-1);
    FUN_00058ec4(0x3f800000,iVar4,-1);
    *(undefined4 *)(iVar4 + 0xc4) = 0x3f800000;
    FUN_00058f38(0xbf800000,iVar4,-1);
    FUN_0005f110(0xbf800000,iVar4);
    FUN_00059084(iVar4,-1);
    *(undefined4 *)(iVar4 + 0xd0) = *(undefined4 *)(iVar4 + 0xc4);
  }
  return;
}
// near miss from lane fm7 (unreviewed)

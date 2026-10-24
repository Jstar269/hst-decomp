/* HSTMATCH module=EBOOT.BIN start=0x00092e50 end=0x00092ff8 symbol=FUN_00092e50 lang=c99 */
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

extern undefined4 DAT_00338b08;
extern char DAT_002d29b4[];
extern uint * FUN_000149a8(uint *param_1,uint *param_2);
extern char * FUN_00014b74(char *param_1,char *param_2,uint param_3);
extern int FUN_00014cfc(int param_1,int param_2);
extern void FUN_0005ec14(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5, undefined4 param_6,undefined4 param_7,undefined4 param_8);
extern void FUN_00093094(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, int param_5);
extern int FUN_000d8c24(int param_1,int param_2,uint param_3);

void FUN_00092e50(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5,int param_6)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined1 auStack_3f [63];
  undefined1 uStack_40;
  undefined1 auStack_80 [64];
  
  if (*(int *)(param_1 + 0x50) != 0) {
    uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x1b4);
    iVar2 = FUN_000d8c24((int)(DAT_00338b08),(int)(0),(uint)(uVar4));
    if (iVar2 != 0) {
      bVar1 = false;
      pcVar6 = (char *)0x0;
      if (param_6 != 0) {
        pcVar6 = DAT_002d29b4;
      }
      if (((int)*(char *)(iVar2 + 0x62) << 0x1c) >> 0x1c == 0) {
        if (param_6 == 0) {
          bVar1 = true;
        }
        else if (*(int *)(param_1 + 0x70) == 0) {
          bVar1 = true;
        }
        else {
          iVar2 = **(int **)(*(int *)(param_1 + 0x70) + 4);
          if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 4), iVar2 != 0)) {
            iVar3 = FUN_00014cfc((int)(iVar2),(int)(0x3a));
            iVar5 = iVar2;
            if (iVar3 != 0) {
              iVar5 = iVar3 + 1;
            }
            iVar2 = FUN_00014cfc((int)(iVar2),(int)(0x5f));
            if (iVar2 != 0) {
              iVar2 = (iVar2 + 1) - iVar5;
              FUN_00014b74((char *)(&uStack_40),(char *)(iVar5),(uint)(iVar2));
              auStack_3f[iVar2 + -1] = 0;
              FUN_000149a8((uint *)(auStack_80),(uint *)(&uStack_40));
              bVar1 = true;
            }
          }
        }
      }
      else {
        FUN_00093094((undefined4)(param_1),(undefined4)(&uStack_40),(undefined4)(auStack_80),(undefined4)(uVar4),(int)((int)*(short *)(*(int *)(param_1 + 0x50) + 0x1b8)));
        bVar1 = true;
      }
      if (bVar1) {
        FUN_0005ec14((int)(*(undefined4 *)(param_1 + 0x50)),(uint)(param_2),(int)(param_3),(undefined4)(param_4),(undefined4)(param_5),(undefined4)(pcVar6),(undefined4)(&uStack_40),(undefined4)(auStack_80));
      }
    }
  }
  return;
}
// near miss from lane fm9 (unreviewed)

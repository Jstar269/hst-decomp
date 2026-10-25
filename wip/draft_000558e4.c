/* HSTMATCH module=EBOOT.BIN start=0x000558e4 end=0x00055b54 symbol=FUN_000558e4 lang=c99 */
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

extern int DAT_002bc440;
extern int DAT_002bc444;
extern int DAT_002bc448;
extern int DAT_002bc44c;
extern undefined4 * FUN_00022418();
extern undefined4 * FUN_00022434();
extern undefined4 * FUN_00022498(float, int, int);
extern bool FUN_0004c66c(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5, undefined4 param_6,undefined4 param_7,undefined4 param_8,int iStackX_0, char cStackX_4);
extern void FUN_0004d6a0(undefined4 *param_1,int param_2,undefined4 *param_3);

undefined4 FUN_000558e4(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4, undefined4 param_5,undefined4 param_6,undefined4 param_7)
{
  undefined4 uVar1;
  int iVar2;
  float fVar3;
  int local_4;
  int local_8;
  int local_c;
  int local_10;
  int local_14;
  int local_18;
  int local_1c;
  int local_20;
  int local_24;
  int local_28;
  int local_2c;
  int local_30;
  int local_34;
  int local_38;
  int local_3c;
  int local_40;
  undefined4 local_44;
  undefined4 local_48;
  undefined4 local_4c;
  undefined4 local_50;
  undefined4 local_54;
  undefined4 local_58;
  undefined4 local_5c;
  undefined4 local_60;
  undefined4 local_64;
  undefined4 local_68;
  undefined4 local_6c;
  undefined4 local_70;
  
  if (param_1[0x23] == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1[0x23] + 0x10);
  }
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    local_40 = param_1[0xc];
    local_3c = param_1[0xd];
    local_38 = param_1[0xe];
    local_34 = param_1[0xf];
    local_30 = param_1[0x10];
    local_2c = param_1[0x11];
    local_28 = param_1[0x12];
    local_24 = param_1[0x13];
    local_20 = param_1[0x14];
    local_1c = param_1[0x15];
    local_18 = param_1[0x16];
    local_14 = param_1[0x17];
    local_10 = param_1[0x18];
    local_c = param_1[0x19];
    local_8 = param_1[0x1a];
    local_4 = param_1[0x1b];
    local_60 = *param_3;
    local_5c = param_3[1];
    local_58 = param_3[2];
    local_54 = param_3[3];
    local_50 = param_3[4];
    local_4c = param_3[5];
    local_48 = param_3[6];
    local_44 = param_3[7];
    FUN_00022434(&local_60,&local_60,&local_10);
    local_54 = param_3[3];
    local_10 = DAT_002bc440;
    local_c = DAT_002bc444;
    local_8 = DAT_002bc448;
    local_4 = DAT_002bc44c;
    fVar3 = (float)param_1[0x22];
    FUN_00022498((float)(1.0f / fVar3),(int)(&local_60),(int)(&local_60));
    FUN_00022498((float)(1.0f / fVar3),(int)(&local_50),(int)(&local_50));
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
    iVar2 = FUN_0004c66c((undefined4 *)(iVar2),(int)(param_2),(undefined4)(&local_60),(undefined4)(&local_40),(int)(uVar1),(undefined4)(param_1),(undefined4)(param_4),(undefined4)(param_5),(int)(param_6),(char)(param_7));
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      FUN_0004d6a0((undefined4 *)(&local_70),(int)(param_2),(undefined4 *)(param_3));
      *param_2 = local_70;
      param_2[1] = local_6c;
      param_2[2] = local_68;
      param_2[3] = local_64;
      FUN_00022498((float)(param_1[0x22]),(int)(param_2 + 4),(int)(param_2 + 4));
      FUN_00022418(param_2 + 4,param_2 + 4,param_1 + 0x18);
      param_2[7] = 0x3f800000;
      uVar1 = 1;
    }
  }
  return uVar1;
}
// near miss from lane fm11 (unreviewed)

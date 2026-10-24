/* HSTMATCH module=EBOOT.BIN start=0x000e82c0 end=0x000e8458 symbol=FUN_000e82c0 lang=c99 */
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

extern undefined4 DAT_003313c4;
extern void FUN_00055044();
extern void FUN_00055798();
extern undefined4 * FUN_0005ba78();
extern void FUN_0005c76c(undefined4, undefined4, undefined4, float, undefined4 *);
extern void FUN_0005c854(int param_1,int param_2,float *param_3,undefined4 *param_4);
extern void FUN_0005cbac();

void FUN_000e82c0(int param_1,undefined4 *param_2)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uStack_4;
  undefined4 uStack_8;
  undefined4 uStack_c;
  undefined4 uStack_10;
  undefined4 local_24;
  undefined4 local_28;
  undefined4 local_2c;
  undefined4 local_30;
  undefined4 local_34;
  undefined4 local_38;
  undefined4 local_3c;
  undefined4 local_50 [5];
  undefined4 local_54;
  undefined4 local_58;
  undefined4 local_5c;
  undefined4 local_60;
  undefined4 local_64;
  undefined4 local_68;
  undefined4 local_6c;
  undefined4 local_70;
  undefined4 local_74;
  undefined4 local_78;
  undefined4 local_7c;
  undefined4 local_80;
  undefined4 local_84;
  undefined4 local_88;
  undefined4 local_8c;
  float local_b0 [9];
  
  puVar3 = local_50;
  iVar2 = 8;
  do {
    uVar1 = param_2[1];
    iVar2 = iVar2 + -1;
    *puVar3 = *param_2;
    puVar3[1] = uVar1;
    param_2 = param_2 + 2;
    puVar3 = puVar3 + 2;
  } while (0 < iVar2);
  FUN_0005ba78((undefined4 *)(param_1 + 0x50),DAT_003313c4);
  FUN_0005cbac((undefined4 *)(param_1 + 0x50),&uStack_4,&uStack_8,&uStack_c,&uStack_10);
  FUN_0005c76c((undefined4)(*(undefined4 *)(param_1 + 0x380)),(undefined4)(*(undefined4 *)(param_1 + 900)),(undefined4)(*(undefined4 *)(param_1 + 0x388)),(float)(*(float *)(param_1 + 0x40) * *(float *)(param_1 + 0x390)),(undefined4 *)((undefined4 *)(param_1 + 0x50)));
  local_b0[6] = -1.0f;
  local_b0[4] = 0.0f;
  local_b0[5] = 0.0f;
  local_b0[7] = 0.0f;
  FUN_0005c854(param_1 + 0x50,0,local_b0 + 4,(undefined4 *)(param_1 + 0x380));
  local_b0[2] = 1.0f;
  local_b0[0] = 0.0f;
  local_b0[1] = 0.0f;
  local_b0[3] = 0.0f;
  FUN_0005c854(param_1 + 0x50,1,local_b0,(undefined4 *)(param_1 + 0x380));
  local_b0[8] = (float)local_50[0];
  local_8c = local_50[1];
  local_88 = local_50[2];
  local_84 = local_50[3];
  local_80 = local_50[4];
  local_7c = local_3c;
  local_78 = local_38;
  local_74 = local_34;
  local_70 = local_30;
  local_6c = local_2c;
  local_68 = local_28;
  local_64 = local_24;
  local_60 = *(undefined4 *)(param_1 + 800);
  local_5c = *(undefined4 *)(param_1 + 0x324);
  local_58 = *(undefined4 *)(param_1 + 0x328);
  local_54 = *(undefined4 *)(param_1 + 0x32c);
  FUN_00055044(*(int *)(param_1 + 0x3c),local_b0 + 8);
  FUN_00055798(*(int **)(param_1 + 0x3c),param_1 + 0x50);
  return;
}
// near miss from lane fm9 (unreviewed)

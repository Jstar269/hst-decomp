/* HSTMATCH module=EBOOT.BIN start=0x0001d164 end=0x0001d3ac symbol=FUN_0001d164 lang=c99 */
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

extern undefined4 * FUN_000224f8();
extern undefined4 * FUN_00022518();

void FUN_0001d164(float *param_1,float *param_2)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float local_4;
  float local_8;
  float local_c;
  float local_10;
  float local_14;
  float local_18;
  float local_1c;
  float local_20;
  undefined4 local_24;
  float local_28;
  float local_2c;
  float local_30;
  float local_34;
  float local_38;
  float local_3c;
  float local_40;
  undefined4 local_44;
  undefined4 local_48;
  undefined4 local_4c;
  undefined4 local_50;
  undefined4 local_54;
  float local_58;
  float local_5c;
  float local_60;
  undefined4 local_64;
  float local_68;
  float local_6c;
  float local_70;
  float local_74;
  float local_78;
  float local_7c;
  float local_80;
  undefined4 local_84;
  undefined4 local_88;
  undefined4 local_8c;
  undefined4 local_90;
  
  fVar6 = param_2[1];
  fVar7 = *param_2;
  fVar5 = param_2[2];
  fVar4 = param_2[3];
  fVar1 = fVar4 * fVar4 + fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6;
  fVar2 = 0.0f;
  if (0.0f < fVar1) {
    fVar2 = 2.0f / fVar1;
  }
  local_4 = 1.0f;
  fVar3 = fVar6 * fVar2;
  local_14 = 0.0f;
  local_24 = 0;
  local_34 = 0.0f;
  local_8 = 0.0f;
  fVar1 = fVar5 * fVar2;
  local_c = 0.0f;
  local_10 = 0.0f;
  local_1c = fVar4 * fVar7 * fVar2;
  fVar2 = fVar7 * fVar7 * fVar2;
  local_40 = 1.0f - (fVar6 * fVar3 + fVar5 * fVar1);
  local_2c = 1.0f - (fVar2 + fVar5 * fVar1);
  local_18 = 1.0f - (fVar2 + fVar6 * fVar3);
  local_3c = fVar7 * fVar3 - fVar4 * fVar1;
  local_30 = fVar7 * fVar3 + fVar4 * fVar1;
  local_38 = fVar7 * fVar1 + fVar4 * fVar3;
  local_20 = fVar7 * fVar1 - fVar4 * fVar3;
  local_28 = fVar6 * fVar1 - local_1c;
  local_1c = fVar6 * fVar1 + local_1c;
  FUN_00022518(&local_60,&local_40);
  local_40 = local_60;
  local_3c = local_5c;
  local_38 = local_58;
  local_54 = 0;
  local_34 = 0.0f;
  FUN_000224f8(&local_90,&local_40,&local_30);
  local_48 = local_88;
  local_50 = local_90;
  local_4c = local_8c;
  local_44 = local_84;
  FUN_00022518(&local_70,&local_50);
  local_20 = local_70;
  local_1c = local_6c;
  local_18 = local_68;
  local_64 = 0;
  local_14 = 0.0f;
  FUN_000224f8(&local_80,&local_20,&local_40);
  *param_1 = local_40;
  param_1[1] = local_3c;
  param_1[2] = local_38;
  param_1[3] = local_34;
  param_1[4] = local_80;
  param_1[5] = local_7c;
  param_1[6] = local_78;
  param_1[7] = local_74;
  param_1[8] = local_20;
  param_1[9] = local_1c;
  param_1[10] = local_18;
  param_1[0xb] = local_14;
  param_1[0xc] = local_10;
  param_1[0xd] = local_c;
  param_1[0xe] = local_8;
  param_1[0xf] = local_4;
  return;
}
// near miss from lane fm11 (unreviewed)

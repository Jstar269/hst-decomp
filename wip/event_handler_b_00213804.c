/* HSTMATCH module=EBOOT.BIN start=0x00213804 end=0x00213b78 symbol=FUN_00213804 lang=c99 */
// NOT MATCHED (216/221 words, 218 differ, measured from the generated baseline): 840-byte dispatch function; a same-shape dispatch over a different object, needs a full rebuild. Rebuilding it needs the whole case table transcribed from the disassembly.
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

extern undefined4 DAT_00338b44;
extern uint FUN_0001342c();
extern undefined4 * FUN_00022450();
extern void FUN_000ac04c();
extern undefined4 FUN_000ddd64(int param_1,float *param_2,int param_3);

void FUN_00213804(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,float *param_5, undefined4 *param_6,undefined4 *param_7)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 local_4;
  float local_8;
  undefined4 local_c;
  float local_10;
  undefined1 auStack_20 [16];
  undefined1 auStack_30 [16];
  undefined4 local_34;
  undefined4 local_38;
  undefined4 local_3c;
  undefined4 local_40;
  undefined4 local_44;
  float local_48;
  undefined4 local_4c;
  float local_50;
  undefined4 local_54;
  float local_58;
  undefined4 local_5c;
  float local_60;
  
  *param_6 = 0;
  *param_7 = 0;
  fVar6 = 0.0f;
  if (0.0f <= param_5[3]) {
    fVar5 = 3.4028235e+38f;
    iVar3 = -1;
    do {
      *(float *)(param_3 + 0xa8) = (float)iVar3;
      FUN_000ac04c(auStack_20,param_2,param_3,param_4,param_6,param_7);
      FUN_00022450(&local_50,auStack_20,param_2 + 0x5a0);
      local_c = local_4c;
      local_10 = local_50;
      local_8 = local_48;
      local_4 = local_44;
      fVar4 = param_5[2] - local_48;
      if (ABS(fVar4) < fVar5) {
        local_10 = 0.0f;
        iVar1 = FUN_000ddd64(DAT_00338b44,&local_10,0);
        if (iVar1 != 0) {
          fVar6 = (float)iVar3;
          fVar5 = ABS(fVar4);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    fVar5 = 3.4028235e+38f;
    *(float *)(param_3 + 0xa8) = fVar6;
    fVar6 = 0.0f;
    iVar3 = -1;
    do {
      *(float *)(param_3 + 0xa0) = (float)iVar3;
      FUN_000ac04c(auStack_30,param_2,param_3,param_4,param_6,param_7);
      FUN_00022450(&local_60,auStack_30,param_2 + 0x5a0);
      local_8 = local_58;
      local_10 = local_60;
      local_c = local_5c;
      local_4 = local_54;
      fVar4 = ABS(*param_5 - local_60);
      if (fVar4 < fVar5) {
        local_8 = 5.9435997f;
        iVar1 = FUN_000ddd64(DAT_00338b44,&local_10,0);
        if (iVar1 != 0) {
          fVar6 = (float)iVar3;
          fVar5 = fVar4;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    *(float *)(param_3 + 0xa0) = fVar6;
  }
  else {
    uVar2 = FUN_0001342c();
    fVar5 = (float)(int)(uVar2 & 0xfffff800) * 4.656613e-10f - 0.2f;
    if (fVar5 < fVar6) {
      *(undefined4 *)(param_3 + 0xa0) = 0xbf800000;
    }
    else if (fVar5 - 0.2f < fVar6) {
      *(undefined4 *)(param_3 + 0xa0) = 0x3f800000;
    }
    uVar2 = FUN_0001342c();
    fVar6 = (float)(int)(uVar2 & 0xfffff800) * 4.656613e-10f - 0.3f;
    if (fVar6 < 0.0f) {
      *(undefined4 *)(param_3 + 0xa8) = 0x3f800000;
    }
    else if (fVar6 - 0.1f < 0.0f) {
      *(undefined4 *)(param_3 + 0xa8) = 0xbf800000;
    }
  }
  FUN_000ac04c(&local_40,param_2,param_3,param_4,param_6,param_7);
  *param_1 = local_40;
  param_1[1] = local_3c;
  param_1[2] = local_38;
  param_1[3] = local_34;
  return;
}
// near miss from lane ds1 (unreviewed)

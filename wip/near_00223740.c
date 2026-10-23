/* HSTMATCH module=EBOOT.BIN start=0x00223740 end=0x002239ec symbol=FUN_00223740 lang=c99 */
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

extern int DAT_002eff90;
extern float DAT_002f0f48;
extern float DAT_002f1008;
extern float DAT_002f100c;
extern undefined4 DAT_0034a268;
extern undefined4 DAT_0034a26c;
extern float FUN_0000bc34(float param_1);
extern void FUN_000edec0(float param_1,float param_2,float param_3,float param_4,float param_5,int param_6, uint *param_7,int param_8,int param_9);
extern void FUN_001031e8();
extern void FUN_00222098();
extern void FUN_002224f8();

typedef struct SubList {
  char pad0[0x10];
  int *items;
  int count;
} SubList;
typedef struct Core {
  char pad0[0x58];
  unsigned char enabled;
  char pad59[7];
  int index;
  char pad64[4];
  int *thing;
  char pad6c[8];
  uint *output;
  int *items;
  char pad7c[0x20];
  int *state;
  char padA0[4];
  SubList *sublist;
  char padA8[4];
  int frameIndex;
  char padB0;
  unsigned char useRows;
  char padB2[10];
  float low;
  float high;
} Core;

void FUN_00223740(Core *param_1)
{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float angleDelta;
  
  if (param_1->enabled != 0) return;
    angleDelta = (float)(param_1->index - DAT_002eff90);
    angleDelta = 180.0f * angleDelta;
    fVar5 = angleDelta / DAT_002f0f48;
    fVar6 = DAT_002f1008;
    if (!(fVar5 < DAT_002f1008)) {
      fVar6 = DAT_002f100c;
      if (!(fVar5 > DAT_002f100c)) {
        fVar6 = fVar5;
      }
    }
    fVar5 = FUN_0000bc34(fVar6 * 0.017453292f);
    fVar5 = -fVar5;
    iVar1 = (int)param_1->items;
    fVar7 = (param_1->low + param_1->high) / 2.0f;
    fVar8 = (param_1->high - param_1->low) / 2.0f;
    fVar6 = fVar8 * ABS(fVar5);
    *(short *)(iVar1 + 4) = (short)(int)(fVar7 - fVar6);
    *(short *)(iVar1 + 8) = (short)(int)(fVar7 + fVar6);
    *(uint *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x28) + (0.0f < fVar5 ^ 1);
    if (param_1->useRows != 0) {
      iVar1 = 0;
      if (0 < param_1->sublist->count) {
        fVar6 = (fVar8 - 20.0f) * ABS(fVar5);
        iVar4 = (int)param_1->sublist->items;
        while( true ) {
          iVar4 = *(int *)(iVar4 + iVar1 * 4);
          if (fVar5 > 0.0f) {
            *(short *)(iVar4 + 4) = (short)(int)(fVar7 - fVar6);
            *(short *)(iVar4 + 8) = (short)(int)(fVar7 + fVar6);
          }
          else {
            *(short *)(iVar4 + 4) = (short)(int)fVar7;
            *(short *)(iVar4 + 8) = (short)(int)fVar7;
          }
          iVar1 = iVar1 + 1;
          if (param_1->sublist->count <= iVar1) break;
          iVar4 = (int)param_1->sublist->items;
        }
      }
    }
    FUN_001031e8(param_1);
    if ((param_1->state != 0) && (fVar5 > 0.0f)) {
      iVar1 = param_1->state[2];
      puVar2 = param_1->output;
      iVar4 = (int)param_1->thing;
      iVar3 = param_1->frameIndex;
      *puVar2 = (int)(*(float *)(iVar4 + 0x78) * 128.0f) << 0x18 | 0x808080;
      FUN_000edec0(*(float *)(iVar4 + 0x60),*(float *)(iVar4 + 100),1.0f,fVar5,1.0f,
                   (int)param_1->state,puVar2,iVar3 % (iVar1 / 64) << 6,
                   (iVar3 / (iVar1 / 64)) * 0x55);
    }
    FUN_00222098(DAT_0034a268);
    FUN_002224f8(DAT_0034a26c);
  return;
}

// NEAR: 182/171 words, 162 differ. Typing the signed tick global, byte flags,
// and state fields reduced the draft by 32 differing words. Retail still has a
// different float register schedule for the angle calculation, branch layout
// in the low/high clamp, and the loop over sub-rows. Tried GCC 131/171 profiles,
// signed and unsigned source forms, nested clamp comparisons, and typed Core
// fields; the default MWCC C99 compile is the closest verified version.
// near miss from lane km4 (unreviewed)

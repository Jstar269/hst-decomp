/* HSTMATCH module=EBOOT.BIN start=0x0028bb2c end=0x0028bd5c symbol=FUN_0028bb2c lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern float DAT_002fee74;
struct Vec3 { float x,y,z; } __attribute__((aligned(16)));
struct Iter { int *p; };
static inline bool operator!=(Iter a,Iter b) { return !(a.p == b.p); }
struct State {
  char pad0[0x7c];
  int *items;
  int count;
  char pad84[0x48];
  int fieldCC;
  int fieldD0;
};
extern State *DAT_0034a114;
struct VObj {
  virtual void F0();
  virtual void F1();
  virtual void F2();
  virtual void F3();
  virtual void F4();
  virtual void F5();
  virtual Vec3 *F6();
  virtual void F7();
  virtual void F8(int,int);
  virtual void F9();
  virtual void F10();
  virtual int F11();
};
struct FalseTag {};
extern "C" void FUN_00022434(Vec3 *,Vec3 *,Vec3 *);
extern "C" void FUN_0005743c(void *,int,int,int);
extern "C" void FUN_00058f38(void *,float,int);
extern "C" void FUN_0005f110(void *,float);
extern "C" int FUN_0022cad0(int,int,int);
extern "C" int *FUN_00288b2c(void *);

extern "C" void FUN_0028bb2c(float param_1,undefined4 param_2,int *param_3,FalseTag)
{
  int *piVar6;
  int *piVar7;
  int *piVar2;
  Vec3 *uVar3;
  Vec3 *uVar4;
  float fVar5;
  int iVar5;
  Vec3 local_20;
  
  Iter begin;
  Iter end;
  piVar6 = DAT_0034a114->items;
  piVar7 = (int *)&DAT_0034a114->items;
  begin.p = piVar6;
  end.p = piVar6 + piVar7[1];
  if (!(begin != end)) {
    return;
  }
  param_1 = param_1 * param_1;
  do {
    VObj *obj = (VObj *)*piVar6;
    if (obj == (VObj *)0x0) {
      iVar5 = piVar7[1];
    }
    else {
      iVar5 = obj->F11();
      if (iVar5 == 5) {
        piVar2 = (int *)FUN_00288b2c(obj);
        iVar5 = FUN_0022cad0(DAT_0034a114->fieldCC,DAT_0034a114->fieldD0,piVar2[0x22]);
        if (iVar5 != 0) {
          uVar3 = ((VObj *)param_3)->F6();
          uVar4 = obj->F6();
          FUN_00022434(&local_20,uVar4,uVar3);
          if ((local_20.x * local_20.x + local_20.z * local_20.z < param_1) &&
             (ABS(local_20.y) < DAT_002fee74)) {
            int *subObj;
            iVar5 = piVar2[0x24];
            if (iVar5 == 2) {
              subObj = (int *)piVar2[0x1d];
            }
            else {
              if (iVar5 != 1) {
                if (iVar5 == 0) {
                  *(undefined1 *)(piVar2 + 0x15) = 0;
                }
                goto LAB_0028bd08;
              }
              subObj = (int *)piVar2[0x1d];
            }
            if (piVar2[0x1c] != subObj[0x23]) {
              ((VObj *)subObj)->F1();
            }
            iVar5 = piVar2[0x1d];
            FUN_0005743c((void *)iVar5,0,piVar2[0x1f],0);
            ((VObj *)piVar2)->F8(0,0);
            *(undefined1 *)(piVar2 + 0x3b) = 1;
            iVar5 = piVar2[0x1d];
            if (*(int **)(iVar5 + 0xf4) == (int *)0x0) {
              fVar5 = 0.0f;
            }
            else {
              fVar5 = *(float *)(**(int **)(iVar5 + 0xf4) + 8);
            }
            FUN_00058f38((void *)iVar5,fVar5,0xffffffff);
            FUN_0005f110((void *)iVar5,fVar5);
          }
        }
      }
LAB_0028bd08:
      iVar5 = piVar7[1];
    }
    piVar6 = piVar6 + 1;
    if (piVar6 == (int *)(*piVar7 + piVar7[1] * 4)) {
      return;
    }
  } while( true );
}

// NEAR: 144/140 words, 100 differ. The t9 virtual calls and 80-byte frame
// match. The entry iterator colors still differ (retail data s0/address s1,
// source data s3/address s0), which shifts the current object pointer from s3
// to s1. The float square also remains in-place in this source. Tried raw C
// function pointers, State and iterator forms, loop scopes, switch lowering,
// float helper/operand variants, and the empty by-value frame tag.
// near miss from lane km4 (unreviewed)

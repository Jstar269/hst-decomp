/* HSTMATCH module=EBOOT.BIN start=0x002a8de4 end=0x002a8fbc symbol=FUN_002a8de4 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_00309f18;
extern void FUN_00000788(...);
extern void FUN_00000a00(...);
extern undefined4 FUN_00049094(...);
extern int FUN_00055e48(...);
extern int FUN_0005ba00(...);
extern int * FUN_000b42f8(...);
extern undefined4 * FUN_00102ea4(...);
extern void FUN_00053618(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" undefined4 * FUN_002a8de4(undefined4 *param_1,short param_2)
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309f18);
    iVar7 = 0;
    puVar4 = param_1;
    do {
      piVar5 = (int *)puVar4[0xc41];
      if (piVar5 == (int *)0x0) {
        iVar2 = puVar4[0xc4a];
      }
      else {
        if (piVar5 == (int *)0x0) {
          puVar4[0xc41] = 0;
        }
        else {
          FUN_00049094(1);
          piVar3 = (int *)*piVar5;
          if (piVar3 != (int *)0x0) {
            delete ((VC_0 *)(piVar3));
            *piVar5 = 0;
          }
          iVar2 = piVar5[2];
          uVar6 = 0;
          if (iVar2 != 0) {
            iVar2 = 0;
            do {
              if (*(int *)(piVar5[1] + iVar2) != 0) {
                FUN_00055e48(*(int *)(piVar5[1] + iVar2),1);
                *(undefined4 *)(piVar5[1] + iVar2) = 0;
              }
              uVar1 = piVar5[2];
              uVar6 = uVar6 + 1;
              iVar2 = iVar2 + 4;
            } while (uVar6 < uVar1);
          }
          piVar3 = piVar5 + 1;
          piVar5[2] = 0;
          if ((piVar3 != (int *)0x0) && (piVar3 != (int *)0x0)) {
            FUN_000b42f8(piVar3,0);
          }
          FUN_00000a00(piVar5);
          puVar4[0xc41] = 0;
        }
        iVar2 = puVar4[0xc4a];
      }
      if (iVar2 != 0) {
        FUN_0005ba00(iVar2,1);
        puVar4[0xc4a] = 0;
      }
      iVar7 = iVar7 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar7 < 4);
    iVar7 = param_1[0xc49];
    if ((iVar7 != 0) && (iVar7 != 0)) {
      FUN_0005ba00(iVar7,1);
      param_1[0xc49] = 0;
    }
    iVar7 = 0;
    puVar4 = param_1;
    do {
      iVar7 = iVar7 + 1;
      puVar4[0xc3c] = 0;
      puVar4 = puVar4 + 3;
    } while (iVar7 < 2);
    FUN_00000788(param_1 + 0xc3b,FUN_00053618,0xc,2);
    FUN_00102ea4(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// near miss from lane fm9 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x0015c2c8 end=0x0015c4e0 symbol=FUN_0015c2c8 lang=c++ data=0x002de420 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002de420-0x002de47e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode corrected by hand: object pointers use byte offsets; global references and the float callback argument are typed to retail; exact match verified; names and types await human review. */
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
extern undefined DAT_0030ebf4;
extern undefined DAT_0034179c;
extern int FUN_00000bcc(...);
extern void FUN_000143b0(...);
extern int FUN_00014934(...);
extern uint * FUN_000149a8(...);
extern void FUN_0001cad0(void *, int, void *);
extern void FUN_0001cb88(void *);
extern undefined4 * FUN_00050fc0(...);
extern void FUN_000511c4(...);
extern void FUN_00051398(undefined4, float);
extern void FUN_0015a62c(...);
extern void FUN_001b3378(void *, int);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_0015c2c8(char *param_1,int param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  FUN_000143b0(param_1 + 0x370,"menu/loadmes/special/loadmes_s%02d.xb",param_2);
  FUN_0001cad0(&DAT_0030ebf4,1,(void *)(param_1 + 0x370));
  if (param_2 == 0) {
    FUN_000143b0(param_1 + 0x370,"data/menu/loadmes/S_d%02d",param_2);
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar1 = FUN_00014934(param_1 + 0x70,param_1 + 0x370);
      if (iVar1 == 0) goto LAB_0015c49c;
    }
    piVar3 = *(int **)(param_1 + 0x34);
    if (piVar3 != (int *)0x0) {
      delete ((VC_0 *)(piVar3));
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    iVar1 = FUN_00000bcc(0x48);
    uVar2 = (undefined4)iVar1;
    if (iVar1 != 0) {
      uVar2 = (unsigned int)(FUN_00050fc0(iVar1));
    }
    *(undefined4 *)(param_1 + 0x34) = uVar2;
    FUN_000511c4(uVar2,param_1 + 0x370,0);
    FUN_00051398(*(undefined4 *)(param_1 + 0x34),3000.0f);
    FUN_000149a8(param_1 + 0x70,param_1 + 0x370);
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0x3f800000;
  }
  else {
    FUN_000143b0(param_1 + 0x370,"data/menu/loadmes/S_u%02d",param_2 + -1);
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar1 = FUN_00014934(param_1 + 0x70,param_1 + 0x370);
      if (iVar1 == 0) goto LAB_0015c49c;
    }
    piVar3 = *(int **)(param_1 + 0x34);
    if (piVar3 != (int *)0x0) {
      delete ((VC_1 *)(piVar3));
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    iVar1 = FUN_00000bcc(0x48);
    uVar2 = (undefined4)iVar1;
    if (iVar1 != 0) {
      uVar2 = (unsigned int)(FUN_00050fc0(iVar1));
    }
    *(undefined4 *)(param_1 + 0x34) = uVar2;
    FUN_000511c4(uVar2,param_1 + 0x370,0);
    FUN_00051398(*(undefined4 *)(param_1 + 0x34),3000.0f);
    FUN_000149a8(param_1 + 0x70,param_1 + 0x370);
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0x3f800000;
  }
LAB_0015c49c:
  FUN_0015a62c(param_1);
  if (param_3 != 0) {
    FUN_001b3378(&DAT_0034179c,0);
  }
  FUN_0001cb88(&DAT_0030ebf4);
  return;
}

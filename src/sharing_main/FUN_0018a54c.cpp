/* HSTMATCH module=hstp_trans_main.prx start=0x0018a54c end=0x0018a620 symbol=FUN_0018a54c lang=c++ */
/* Clone of src/eboot/FUN_0017de58.cpp (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed the float stack record and modeled the singleton member call; exact match verified; names and types await human review. */
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

extern "C" int FUN_00177ea4();
struct Receiver {
  void FUN_00198214(float,float,float,int *,int,int,int,float *);
};

extern "C" Receiver *FUN_00197fb4();
extern "C" int FUN_0019fc84(undefined4);
extern "C" int FUN_00212c68(undefined4);

extern "C" void FUN_0018a54c(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar5;
  float f0;
  float f1;
  float f2;
  float local[4];
  
  iVar1 = FUN_00177ea4();
  iVar2 = FUN_00212c68(param_2);
  iVar3 = FUN_0019fc84(param_2);
  if (*(uchar *)(iVar3 + 0x24) == '\0') {
    uVar5 = 4;
  }
  else {
    uVar5 = 2;
  }
  f0 = *(float *)(iVar1 + 0x24);
  f1 = *(float *)(iVar1 + 0x2c);
  f2 = *(float *)(iVar1 + 0x28);
  local[0] = f0;
  local[1] = f2;
  local[2] = f1;
  local[3] = 0.0f;
  FUN_00197fb4()->FUN_00198214(*(float *)(iVar2 + 4),*(float *)(iVar2 + 8),*(float *)(iVar2 + 0xc),
                               (int *)(*(int *)(*(int *)(param_1 + 8) + param_3 * 4) + 0x10),param_2,param_3,uVar5,
                               local);
  return;
}

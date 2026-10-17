/* HSTMATCH module=hstp_trans_main.prx start=0x000f5d0c end=0x000f5e1c symbol=FUN_000f5d0c lang=c++ */
/* Clone of src/eboot/update_entry_offsets_000f0644.cpp (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v3) corrected by hand: materialized the inverted byte gate, typed float fields, and expressed the final virtual call; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined * DAT_003e1e84;
extern "C" void FUN_000f5e1c(int *param_1);
extern "C" void FUN_000f6030();
extern "C" void FUN_00105470(int param_1,int param_2);

struct VTable { virtual void slot0(); virtual void slot1(); };

extern "C" void FUN_000f5d0c(int *param_1)
{
  int iVar1;
  int iVar3;
  int *piVar2;
  
  FUN_000f6030();
  iVar3 = 0;
  piVar2 = param_1;
  do {
    int enabled = (*(uchar *)(DAT_003e1e84 + 0x45) != 0) ^ 1;
    if (enabled != 0) {
      iVar1 = piVar2[0x18];
      *(short *)(iVar1 + 6) = *(short *)(iVar1 + 6) + 0x14;
      *(short *)(iVar1 + 10) = *(short *)(iVar1 + 10) + 0x14;
      iVar1 = piVar2[0x1a];
      *(short *)(iVar1 + 6) = *(short *)(iVar1 + 6) + 0x14;
      *(short *)(iVar1 + 10) = *(short *)(iVar1 + 10) + 0x14;
      *(float *)(piVar2 + 0x1c) = *(float *)(piVar2 + 0x1c) + 20.0f;
      *(float *)(piVar2 + 0x1e) = *(float *)(piVar2 + 0x1e) + 20.0f;
      iVar1 = piVar2[0x18];
    }
    else {
      iVar1 = piVar2[0x18];
    }
    FUN_00105470(iVar1,1);
    *(undefined4 *)piVar2[0x18] = 0x808080;
    FUN_00105470(piVar2[0x1a],1);
    iVar3 = iVar3 + 1;
    *(undefined4 *)piVar2[0x1a] = 0x808080;
    piVar2 = piVar2 + 1;
  } while (iVar3 < 2);
  FUN_000f5e1c(param_1);
  ((VTable *)param_1)->slot1();
  return;
}

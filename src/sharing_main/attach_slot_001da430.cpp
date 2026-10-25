/* HSTMATCH module=hstp_trans_main.prx start=0x001da430 end=0x001da640 symbol=FUN_001da430 lang=c++ */
/* Clone of src/eboot/attach_slot_001cbccc.cpp (hstclone.py tag nxc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The table lookup is one inline helper used by both branches (retail's per-branch return joins), and the slot pointer is read once after the if/else. */
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
extern undefined DAT_002d10cc;
extern undefined DAT_002d10d0;
extern undefined DAT_002d10d4;
extern void FUN_0019709c(...);
extern undefined1 * FUN_001991d4(...);
extern void FUN_001dbf68(...);
extern undefined * FUN_00238a68(int, int, undefined4, int);
extern undefined4 FUN_00238d4c(...);
extern int * FUN_0029a220(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };
struct VC_2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29(); virtual void d30(); virtual void m(int, int); };

static inline undefined *Lookup(int tbl, int idx)
{
  if (*(int *)(tbl + 4) == 0)
    return &DAT_002d10d4;
  if (*(int *)(*(int *)(tbl + 8) + 8) < 1)
    return &DAT_002d10d0;
  if ((idx < 0) || (idx >= (*(int **)(tbl + 0xc))[1]))
    return &DAT_002d10cc;
  return *(undefined **)(**(int **)(tbl + 0xc) + idx * 4);
}

extern "C" void FUN_001da430(int param_1,int *param_2,undefined4 param_3,int param_4)
{
  undefined *puVar5;
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_2 != (int *)0x0) {
    if (param_4 < 0) {
      iVar3 = param_2[0xd];
      puVar5 = Lookup((int)FUN_001991d4(7), iVar3);
    }
    else {
      puVar5 = Lookup((int)FUN_001991d4(0xc), param_4);
    }
    iVar2 = *(int *)(param_1 + 0x15c);
    iVar3 = (int)(FUN_00238a68(iVar2 + 0x34,*(undefined4 *)(iVar2 + 0x24),param_3,0));
    if (iVar3 != 0) {
      *(undefined1 *)(iVar2 + 99) = 0;
      *(undefined1 *)(iVar2 + 100) = 0;
      *(int *)(iVar2 + 0x68) = iVar3;
      *(undefined4 *)(iVar2 + 0x6c) = 0;
      *(undefined4 *)(iVar2 + 0x70) = 0;
      FUN_0019709c(*(undefined4 *)(iVar2 + 0x20),puVar5);
      FUN_001dbf68(iVar2,2,1);
    }
    *(undefined4 *)(iVar2 + 0x74) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x78) = 0xffffffff;
    FUN_00238d4c(iVar2 + 0x34,param_3,0);
    iVar2 = ((VC_0 *)(param_2))->m();
    bVar1 = iVar2 == 2;
    if (!bVar1) {
      iVar2 = ((VC_1 *)(param_2))->m();
      bVar1 = iVar2 == 3;
    }
    if (bVar1) {
      piVar4 = (int *)FUN_0029a220(param_2);
      ((VC_2 *)(piVar4))->m((int)(0), (int)(1));
      *(int **)(*(int *)(param_1 + 0x15c) + 0x5c) = param_2;
    }
  }
  return;
}

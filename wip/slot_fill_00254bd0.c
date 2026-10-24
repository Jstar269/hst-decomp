/* HSTMATCH module=EBOOT.BIN start=0x00254bd0 end=0x00254e18 symbol=FUN_00254bd0 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;

extern void FUN_000149a8(int, int);
extern int FUN_00165004(int, int);
extern void FUN_00254378(char *, int);
extern void FUN_000d7d80(void *);
extern void FUN_002045e8(void *, int, int, int, int, int, int, int, int);
extern int FUN_00164c60(int, void *);
extern int FUN_00164d00(int, void *);
extern int FUN_00164e24(int, void *);
extern int FUN_00164f64(int, void *);
extern int FUN_00164ec4(int, void *);
extern void FUN_000d7e30(void *, int);
extern char DAT_003417d0;
extern char DAT_002fcf40[];
extern int DAT_00341508;

void FUN_00254bd0(int param_1, int param_2)
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  unsigned char *pbVar6;
  int iVar7;
  undefined1 auStack_c8[200];
  char *rec;

  iVar3 = param_2 * 0x120;
  rec = (char *)&DAT_003417d0 + iVar3;
  if (*(short *)rec < 0xf) {
    *(undefined1 *)(param_2 + param_1 + 0x5c) = 0;
  }
  else {
    *(undefined1 *)(param_2 + param_1 + 0x5c) = 1;
  }
  pbVar6 = (unsigned char *)(param_2 + param_1 + 0x5c);
  if (*pbVar6 == 0) {
    *(int *)(param_2 * 4 + param_1 + 8) = (int)*(short *)rec;
  }
  else {
    *(uint *)(param_2 * 4 + param_1 + 8) = (uint)*(unsigned short *)(rec + 0x20);
  }
  iVar5 = param_2 * 4;
  iVar7 = param_1 + param_2 * 0x11;
  FUN_000149a8(iVar7 + 0x18, (int)(rec + 0x68));
  iVar7 = FUN_00165004(DAT_00341508 + (uint)*pbVar6 * 0x18, iVar7 + 0x18);
  iVar7 = *(int *)(DAT_00341508 + (uint)*pbVar6 * 0x18) + iVar7 * 0x22c;
  FUN_00254378(DAT_002fcf40, param_2);
  FUN_00254378(DAT_002fcf40, (int)*(char *)(rec + 0xa0));
  FUN_00254378(DAT_002fcf40, (int)*(unsigned char *)(rec + 0x82));
  FUN_000d7d80(auStack_c8);
  FUN_002045e8(auStack_c8, (int)*(short *)rec, (int)*(short *)(rec + 2), (int)*(short *)(rec + 4),
               (int)*(short *)(rec + 6), (int)*(short *)(rec + 8), (int)*(short *)(rec + 10),
               (int)*(unsigned char *)(rec + 0x67), (int)*(char *)(rec + 0xa0));
  if (*(unsigned char *)(rec + 0xee) == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = (uint)*(unsigned char *)(rec + 0x64);
  }
  *(uint *)(iVar5 + param_1 + 0xfc) = uVar2;
  uVar1 = FUN_00164c60(iVar7, auStack_c8);
  *(undefined4 *)(iVar5 + param_1 + 0x10c) = uVar1;
  uVar1 = FUN_00164d00(iVar7, auStack_c8);
  *(undefined4 *)(iVar5 + param_1 + 0x11c) = uVar1;
  uVar1 = FUN_00164e24(iVar7, auStack_c8);
  *(undefined4 *)(iVar5 + param_1 + 300) = uVar1;
  uVar1 = FUN_00164f64(iVar7, auStack_c8);
  *(undefined4 *)(iVar5 + param_1 + 0x13c) = uVar1;
  uVar1 = FUN_00164ec4(iVar7, auStack_c8);
  iVar4 = iVar5 + param_1;
  *(undefined4 *)(iVar4 + 0x14c) = uVar1;
  *(int *)(iVar4 + 0x16c) = (int)*(char *)(iVar7 + 0x14);
  *(int *)(iVar4 + 0x15c) = (int)*(short *)(rec + 10) % 10;
  *(int *)(iVar4 + 0x17c) = (int)*(short *)(rec + 10);
  if (*(unsigned char *)(rec + 0xee) == '\0') {
    iVar3 = 0;
  }
  else {
    iVar3 = (char)*(rec + 0xa0) + 1;
  }
  *(int *)(iVar5 + param_1 + 0x18c) = iVar3;
  FUN_000d7e30(auStack_c8, 0xffffffff);
  return;
}
// NEAR (140/146). Transcribed with a `char *rec = (char *)&DAT_003417d0 + param_2*0x120` base, which is
// what retail keeps in s0. Delta: retail also keeps `param_1 + param_2*0x11` in s5 (6 saved regs vs
// our 5) and is 6 words longer; the three FUN_00254378 calls share one a0 (DAT_002fcf40) with a new
// a1 each (param_2, lb rec+0xa0, lbu rec+0x82), and the 9th FUN_002045e8 argument (lb rec+0xa0) is
// staged on the stack first (`sw v0,0(sp)` before the six lh's).
// near miss from lane fm8 (unreviewed)

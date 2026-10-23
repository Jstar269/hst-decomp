/* HSTMATCH module=EBOOT.BIN start=0x00253f38 end=0x00254114 symbol=FUN_00253f38 lang=c99 */
/* NEAR MISS 119/119 words, 16 differ (all in the prologue schedule, plus `beqz` vs retail `beqzl`).
   Structure confirmed: `slot = &DAT_0034b340[param_1]` (int slot table, s0) and a 0x120-stride row pointer
   `sub = (unsigned char *)&DAT_003417b8 + param_1 * 0x120 + 0x18` (s1) with the flag at sub[0x24]; the two
   buffer calls pass iVar2 TWICE through the unprototyped FUN_000143b0 (the 4th argument fills the delay
   slot: `move a3,s2`). The branch must be written `if (iVar2 >= 0xf) { big } else { small }`: that puts the
   small arm out of line at 0x254060 and gives retail's `slti v0,s2,15 / bnezl v0,0x254060` dispatch, while
   `if (iVar2 < 0xf)` inlines the wrong arm. Open: retail defines sub's address FIRST (sll/addu/sll before
   `sw ra`) but colours it s1, while every spelling here colours the first-defined local s0; writing sub
   first gets the schedule (`sll a1` before `sw ra`) but flips s0/s1 and keeps 20 words differing.
   Statement order, declaration order, decl-with-initializer, int-pointer/void-pointer/struct-pointer forms, an int
   `off = param_1 * 0x120` local and a struct-array form were all tried (all >= 16 differ). */
extern char DAT_003417b8;
extern char DAT_0034b340;
extern char DAT_002fcd88[];
extern char DAT_0030ebf4[];
extern char DAT_002fcda0[];
extern char DAT_002fcdcc[];
extern char DAT_002fcde8[];
extern char DAT_002fce14[];
extern char DAT_002fce40[];
extern char DAT_002fce6c[];
extern char DAT_002fce88[];
extern char DAT_002fcea4[];
extern char DAT_002fced4[];
extern void FUN_000143b0();
extern void FUN_0001ca58();
extern void FUN_0001cb88();
extern void FUN_00092e50();

void FUN_00253f38(int param_1)
{
  int *slot;
  unsigned char *sub;
  int iVar2;
  char auStack_100[256];
  char auStack_200[256];

  slot = (int *)((char *)&DAT_0034b340 + param_1 * 4);
  sub = (unsigned char *)&DAT_003417b8 + param_1 * 0x120 + 0x18;
  iVar2 = 0;
  if (*(int *)(*slot + 0x50) != 0)
    iVar2 = *(int *)(*(int *)(*slot + 0x50) + 0x1b4);
  if (iVar2 >= 0xf) {
  FUN_0001ca58(DAT_0030ebf4,DAT_002fcd88);
  if (sub[0x24] == 0) {
    FUN_00092e50(*slot,0,DAT_002fcda0,DAT_002fcdcc,0,1);
    FUN_00092e50(*slot,1,DAT_002fcde8,DAT_002fcdcc,0,1);
  }
  else {
    FUN_00092e50(*slot,0,DAT_002fce14,DAT_002fcdcc,0,1);
    FUN_00092e50(*slot,1,DAT_002fce40,DAT_002fcdcc,0,1);
  }
  FUN_0001cb88(DAT_0030ebf4);
  }
  else {
    FUN_0001ca58(DAT_0030ebf4,DAT_002fce6c,iVar2);
    FUN_000143b0(auStack_100,DAT_002fce88,iVar2);
    FUN_000143b0(auStack_200,DAT_002fcea4,iVar2,iVar2);
    FUN_00092e50(*slot,0,auStack_200,auStack_100,0,1);
    FUN_000143b0(auStack_200,DAT_002fced4,iVar2,iVar2);
    FUN_00092e50(*slot,1,auStack_200,auStack_100,0,1);
    FUN_0001cb88(DAT_0030ebf4);
  }
  return;
}
// near miss from lane fm7 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x00170930 end=0x00170a08 symbol=FUN_00170930 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: bool flags as ints, byte fields as unsigned char behind an inline predicate, range check split into if/else-if, start value kept in its own local (register order); exact match verified; names and types await human review. */
extern int FUN_00179178();

static inline int Free(unsigned char *e) { if (e[8] != 0 || e[11] != 0 || e[12] != 0) return 0; return 1; }
int FUN_00170930(int param_1,int param_2,int param_3)
{
  int iVar5;
  int bVar2;
  int iVar4;
  int start;
  int iVar3;
  iVar4 = *(int *)(*(int *)(param_1 + 0x1d4) + 4);
  iVar5 = param_2;
  start = param_2;
  bVar2 = 0;
  do {
    iVar5 = iVar5 + param_3;
    if (iVar5 < 0) { iVar5 = start; bVar2 = 1; } else if (iVar5 >= iVar4) { iVar5 = start; bVar2 = 1; }
    iVar3 = FUN_00179178(param_1,iVar5);
  } while (!Free((unsigned char *)iVar3) && !bVar2);
  return iVar5;
}

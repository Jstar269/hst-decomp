/* HSTMATCH module=EBOOT.BIN start=0x0015435c end=0x001543d0 symbol=FUN_0015435c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global is unsigned char (lbu), global base typed as a struct pointer, counter+1 computed into a local before the lookup call; exact match verified; names and types await human review. */
typedef struct G { char pad[0xd0]; int cnt; } G;
extern unsigned char DAT_003402f0;
extern G *DAT_0034a114;
extern char DAT_002dc8b4[];
extern int *FUN_0014c384(int, int);
extern void FUN_0014d044(int *);
extern void FUN_0014fd94(char *, int);

int FUN_0015435c(char *param_1, int *param_2)
{
  int n;
  int *p;
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94(DAT_002dc8b4, *(int *)(param_1 + 8));
  }
  n = DAT_0034a114->cnt + 1;
  p = FUN_0014c384(*param_2, *(int *)(param_1 + 8));
  *p = n;
  return 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x001b63e8 end=0x001b646c symbol=FUN_001b63e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: switch on DAT_0034a678, struct member access, symbol address DAT_0034179c; exact match verified; names and types await human review. */

struct Obj {
    char pad[0x90];
    char f90;
    char pad1[2];
    char f93;
};

extern int DAT_003417c4;
extern int DAT_0034a678;
extern const char DAT_002e99c4;
extern void *DAT_0034179c;
extern void FUN_00000020(const void *);
extern void FUN_00000028(void);
extern void FUN_001b39ec(const void *);
extern void FUN_001b4dfc(int);
extern void FUN_001b646c(struct Obj *);
extern char FUN_0022c860(void);

void FUN_001b63e8(struct Obj *param_1)
{
  FUN_00000020(&DAT_002e99c4);
  param_1->f90 = 0;
  param_1->f93 = 0;
  switch (DAT_0034a678) {
  case 0x2a:
    param_1->f90 = 1;
    param_1->f93 = FUN_0022c860();
    break;
  }
  FUN_001b4dfc(DAT_003417c4);
  FUN_001b646c(param_1);
  FUN_001b39ec(&DAT_0034179c);
  FUN_00000028();
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0018dcb0 end=0x0018dcf4 symbol=FUN_0018dcb0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0) corrected by hand: early return guard, prototyped callee with float parameter; exact match verified; names and types await human review. */
typedef struct Child Child;
typedef struct Parent {
  int pad;
  Child *child;
} Parent;

extern void FUN_00108e6c(Child *, float);
extern void FUN_001090f4(Child *, int);

void FUN_0018dcb0(Parent *param_1)
{
  if (param_1->child == 0) {
    return;
  }
  FUN_00108e6c(param_1->child, 2000.0f);
  FUN_001090f4(param_1->child, 16);
}

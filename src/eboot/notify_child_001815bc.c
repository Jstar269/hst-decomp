/* HSTMATCH module=EBOOT.BIN start=0x001815bc end=0x00181600 symbol=FUN_001815bc lang=c99 */
/* Clone of src/sharing_main/notify_child_0018dcb0.c (hstclone.py tag u5fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0) corrected by hand: early return guard, prototyped callee with float parameter; exact match verified; names and types await human review. */
typedef struct Child Child;
typedef struct Parent {
  int pad;
  Child *child;
} Parent;

extern void FUN_00103540(Child *, float);
extern void FUN_001037c8(Child *, int);

void FUN_001815bc(Parent *param_1)
{
  if (param_1->child == 0) {
    return;
  }
  FUN_00103540(param_1->child, 2000.0f);
  FUN_001037c8(param_1->child, 16);
}

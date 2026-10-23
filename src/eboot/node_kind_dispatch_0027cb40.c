/* HSTMATCH module=EBOOT.BIN start=0x0027cb40 end=0x0027cc28 symbol=FUN_0027cb40 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: the doubled null test on the node pointer is retail's (Ghidra renders it the same way);
   both kind fields are read before the inner test, and their || chain alternates first/second field. */
typedef struct {
  char pad_00[0x10];
  int kindA;
  char pad_14[0x0c];
  int kindB;
} Node_0027cb40;

extern int DAT_0034a7e0;
extern void FUN_0027c328(int, int, Node_0027cb40 *);

void FUN_0027cb40(int param_1)
{
  Node_0027cb40 *o;
  int kindA;
  int kindB;

  o = **(Node_0027cb40 ***)(param_1 + 0x90);
  if (o != 0) {
    kindA = o->kindA;
    kindB = o->kindB;
    if (o != 0) {
      if (kindA == 1 || kindB == 1 || kindA == 2 || kindB == 2) {
        FUN_0027c328(*(int *)(DAT_0034a7e0 + 0x3c), *(int *)(param_1 + 0x94), o);
      }
      else if (kindA == 5 || kindB == 5 || kindA == 6 || kindB == 6 || kindA == 7 ||
               kindB == 7 || kindA == 8 || kindB == 8 || kindA == 9 || kindB == 9) {
        FUN_0027c328(*(int *)(DAT_0034a7e0 + 0x3c), *(int *)(param_1 + 0x94), o);
      }
    }
  }
  return;
}

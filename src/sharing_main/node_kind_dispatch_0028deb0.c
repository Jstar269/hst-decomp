/* HSTMATCH module=hstp_trans_main.prx start=0x0028deb0 end=0x0028df98 symbol=FUN_0028deb0 lang=c99 */
/* Clone of src/eboot/node_kind_dispatch_0027cb40.c (hstclone.py tag fm3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: the doubled null test on the node pointer is retail's (Ghidra renders it the same way);
   both kind fields are read before the inner test, and their || chain alternates first/second field. */
typedef struct {
  char pad_00[0x10];
  int kindA;
  char pad_14[0x0c];
  int kindB;
} Node_0028deb0;

extern int DAT_003f3b10;
extern void FUN_0028d698(int, int, Node_0028deb0 *);

void FUN_0028deb0(int param_1)
{
  Node_0028deb0 *o;
  int kindA;
  int kindB;

  o = **(Node_0028deb0 ***)(param_1 + 0x90);
  if (o != 0) {
    kindA = o->kindA;
    kindB = o->kindB;
    if (o != 0) {
      if (kindA == 1 || kindB == 1 || kindA == 2 || kindB == 2) {
        FUN_0028d698(*(int *)(DAT_003f3b10 + 0x3c), *(int *)(param_1 + 0x94), o);
      }
      else if (kindA == 5 || kindB == 5 || kindA == 6 || kindB == 6 || kindA == 7 ||
               kindB == 7 || kindA == 8 || kindB == 8 || kindA == 9 || kindB == 9) {
        FUN_0028d698(*(int *)(DAT_003f3b10 + 0x3c), *(int *)(param_1 + 0x94), o);
      }
    }
  }
  return;
}

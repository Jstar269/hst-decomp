/* HSTMATCH module=hstp_trans_main.prx start=0x0008f050 end=0x0008f094 symbol=FUN_0008f050 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the object as a struct with an unsigned byte flag (lbu) and pointer members; exact match verified; names and types await human review. */
typedef struct Obj {
  char pad_00[0x3c];
  void *f3c;
  void *f40;
  unsigned char f44;
} Obj;

extern void FUN_0008db80(void *);
extern void FUN_00292408(void *);
extern void FUN_0029513c(void *);

void FUN_0008f050(Obj *param_1)
{
  if (param_1->f44 != 0) {
    param_1->f44 = 0;
    FUN_00292408(param_1->f40);
  }
  FUN_0029513c(param_1->f40);
  FUN_0008db80(param_1->f3c);
}

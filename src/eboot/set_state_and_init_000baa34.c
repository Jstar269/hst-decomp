/* HSTMATCH module=EBOOT.BIN start=0x000baa34 end=0x000baaa4 symbol=FUN_000baa34 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (inputs/pseudocode/ram-0x000baa34.c, no hstgen tag) corrected by hand: the if-chain rewritten as a switch (cases 4/8 share the call, case 10 empty); exact match verified; names and types await human review. */
extern char DAT_00338ac4;
extern int FUN_000bda40(int, int, unsigned short, int, int);

void FUN_000baa34(int param_1, int param_2)
{
  *(int *)(param_1 + 0x28) = param_2;
  switch (param_2) {
  case 4:
  case 8:
    *(unsigned int *)(param_1 + 0x17c) =
      FUN_000bda40(*(int *)&DAT_00338ac4, *(int *)&DAT_00338ac4 + 0x38,
                   *(unsigned short *)(param_1 + 0x10), 0x5a4, 0) & 0xff;
    break;
  case 10:
    break;
  }
}

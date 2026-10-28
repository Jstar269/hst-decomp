/* HSTMATCH module=EBOOT.BIN start=0x00095058 end=0x000950e0 symbol=FUN_00095058 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: keep the two return blocks in the order ret1,ret0 (declare ret1 first) and end the function with an explicit `goto ret0` as the false-path fall-through; param_5 and the compared byte are unsigned char (andi/lbu). */

extern int FUN_000950e0();

int FUN_00095058(int param_1,int param_2,int param_3,unsigned int param_4,unsigned char param_5)
{
  int iVar1;

  if (*(int *)(param_1 + 0x1b0) == param_2) {
    if (*(int *)(param_1 + 0x1b4) == param_3) {
      iVar1 = FUN_000950e0(param_1,param_4);
      if (iVar1 != 0) {
        if (*(unsigned char *)(param_1 + 0x1ba) == param_5) {
          goto ret1;
        }
        if (*(int *)(param_1 + 0x1b0) == 0) {
          goto ret1;
        }
        if (*(int *)(param_1 + 0x1b0) != 5) {
          goto ret0;
        }
        goto ret1;
      }
    }
  }
  goto ret0;
ret1:
  return 1;
ret0:
  return 0;
}

/* HSTMATCH module=EBOOT.BIN start=0x000bcf88 end=0x000bd014 symbol=FUN_000bcf88 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_002d53ec[];
extern int DAT_00338ac4;
extern void FUN_000ba3ac(char *tag);
extern int FUN_000bda40(int a, int b, unsigned short c, int d, int e);

void FUN_000bcf88(int param_1)
{
  int base;

  FUN_000ba3ac(DAT_002d53ec);
  *(int *)(param_1 + 0x194) = *(int *)(param_1 + 0x190);
  *(int *)(param_1 + 0x190) = 0;
  *(int *)(param_1 + 0x28) = 11;
  switch (*(int *)(param_1 + 0x28)) {
  case 4:
  case 8:
    base = DAT_00338ac4;
    *(int *)(param_1 + 0x17c) =
        FUN_000bda40(base, base + 0x38, *(unsigned short *)(param_1 + 0x10), 1444, 0) & 0xff;
    break;
  case 10:
    break;
  }
}

/* HSTMATCH module=EBOOT.BIN start=0x001bb8b8 end=0x001bb944 symbol=FUN_001bb8b8 lang=c99 rodata=0x002c628c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_00193474(int);

int FUN_001bb8b8(int param_1, int param_2)
{
  int v = FUN_00193474(param_2);
  if (v != 0) {
    switch (param_1) {
    case 0: return *(short *)(v + 0);
    case 1: return *(short *)(v + 2);
    case 2: return *(short *)(v + 4);
    case 3: return *(short *)(v + 6);
    case 4: return *(short *)(v + 8);
    case 5: return *(short *)(v + 10);
    }
  }
  return 0;
}

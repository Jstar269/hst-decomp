/* HSTMATCH module=EBOOT.BIN start=0x001e8424 end=0x001e84c8 symbol=FUN_001e8424 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_002177d4(void *, int, int, int, int, int);

void FUN_001e8424(char *self)
{
  FUN_002177d4(self + 0x279c, *(short *)(self + 0x27a4) + 0x15e,
               (int)*(short *)(self + 0x27a6), (int)*(short *)(self + 0x27a4),
               (int)*(short *)(self + 0x27a6), 5);
  FUN_002177d4(self + 0x48, (int)*(short *)(self + 0x5c), (int)*(short *)(self + 0x5e),
               (int)((float)(int)*(short *)(self + 0x5c) + -140.0f),
               (int)*(short *)(self + 0x5e), 5);
  FUN_002177d4(self + 0x168, (int)*(short *)(self + 0x170), (int)*(short *)(self + 0x172),
               (int)((float)(int)*(short *)(self + 0x170) + -140.0f),
               (int)*(short *)(self + 0x172), 5);
}

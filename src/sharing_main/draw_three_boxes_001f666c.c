/* HSTMATCH module=hstp_trans_main.prx start=0x001f666c end=0x001f6710 symbol=FUN_001f666c lang=c99 */
/* Clone of src/eboot/draw_three_boxes_001e8424.c (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_0022687c(void *, int, int, int, int, int);

void FUN_001f666c(char *self)
{
  FUN_0022687c(self + 0x279c, *(short *)(self + 0x27a4) + 0x15e,
               (int)*(short *)(self + 0x27a6), (int)*(short *)(self + 0x27a4),
               (int)*(short *)(self + 0x27a6), 5);
  FUN_0022687c(self + 0x48, (int)*(short *)(self + 0x5c), (int)*(short *)(self + 0x5e),
               (int)((float)(int)*(short *)(self + 0x5c) + -140.0f),
               (int)*(short *)(self + 0x5e), 5);
  FUN_0022687c(self + 0x168, (int)*(short *)(self + 0x170), (int)*(short *)(self + 0x172),
               (int)((float)(int)*(short *)(self + 0x170) + -140.0f),
               (int)*(short *)(self + 0x172), 5);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x001f5664 end=0x001f56ec symbol=FUN_001f5664 lang=c99 */
/* Clone of src/eboot/call_with_packed_bytes_001e744c.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_001fc5ec();
extern int FUN_00066a84(int, const char *, int);
extern void FUN_002268dc(int, unsigned, int, int);
extern char DAT_003940a4[];

void FUN_001f5664(char *self)
{
  int x = *(int *)(self + 0x948);
  unsigned value = (unsigned)*(unsigned char *)(self + 0x99e) << 24 |
                   (unsigned)*(unsigned char *)(self + 0x99c) << 16 |
                   (unsigned)*(unsigned char *)(self + 0x99a) << 8 |
                   (unsigned)*(unsigned char *)(self + 0x998);
  int r = FUN_001fc5ec();
  r = FUN_00066a84(r, DAT_003940a4, 1);
  FUN_002268dc((int)(self + 0x928), value, x, r);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x001c412c end=0x001c41bc symbol=FUN_001c412c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: used unsigned-byte globals, an int helper result, a shared flag OR, and the address symbol for the report call; exact match verified; names and types await human review. */

extern unsigned char * DAT_003e95e0;
extern unsigned char DAT_003e19f8;
extern unsigned char DAT_003eab00;
extern unsigned char DAT_003eaad8;
extern void FUN_001c1d74(void *,int,int);
extern int FUN_0023cd08(void);
void FUN_001c412c(int param_1)
{
  int mode = *(int *)(DAT_003e95e0 + 0x1364);
  int flag = 0;
  if (mode == 0x11 && ((DAT_003e19f8 == 0 && *(unsigned char *)(param_1 + 0x90) != 0 && FUN_0023cd08() != 0) || DAT_003eab00 != 0)) flag |= 1;
  FUN_001c1d74(&DAT_003eaad8,mode - 1,flag);
}

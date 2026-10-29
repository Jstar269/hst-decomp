/* HSTMATCH module=EBOOT.BIN start=0x000480a4 end=0x000480f4 symbol=FUN_000480a4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Bumps the global counter at 0x31105c and calls the hook installed at 0x310ffc when the flag byte at
   0x311028 is clear. Names provisional. */
extern unsigned int DAT_0031105c;
extern void (*DAT_00310ffc)(void);
extern unsigned char DAT_00311028;

void FUN_000480a4(void)
{
  DAT_0031105c = DAT_0031105c + 1;
  if (DAT_00310ffc != 0) {
    if (DAT_00311028 == 0) {
      DAT_00310ffc();
    }
  }
}

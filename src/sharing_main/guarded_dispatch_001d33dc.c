/* HSTMATCH module=hstp_trans_main.prx start=0x001d33dc end=0x001d341c symbol=FUN_001d33dc lang=c99 */
/* Clone of src/eboot/guarded_dispatch_001c5044.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_001d429c();
void FUN_001d33dc(int p)
{
  if (*(int *)(p + 0x16c) == 0) {
    switch (*(int *)(p + 0xc4)) {
      case 2:
        FUN_001d429c(p);
        break;
      default:
        break;
    }
  }
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00138254 end=0x001382bc symbol=FUN_00138254 lang=c99 */
/* Clone of src/eboot/ensure_object_0012cde8.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003e48c0;
extern int DAT_003f344c;
extern int FUN_00000bcc(int);
extern int *FUN_0013914c(int *);
extern void FUN_00138d90(int);
extern void FUN_001514cc(void);
extern void FUN_001d4ca0(int, int *);
void FUN_00138254(int param_1)
{
  int *p;
  FUN_001514cc();
  if (DAT_003e48c0 == 0) {
    p = (int *)FUN_00000bcc(0x250);
    if (p != 0)
      p = FUN_0013914c(p);
    FUN_001d4ca0(DAT_003f344c, p);
  }
  FUN_00138d90(param_1);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x000468f4 end=0x00046954 symbol=FUN_000468f4 lang=c99 */
/* Clone of src/eboot/FUN_00046820.c (hstclone.py tag a2c2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_003ba328; extern unsigned char DAT_003b3e5c; extern char DAT_00375af4[]; extern void FUN_00046664(char *s); extern void FUN_002c7628(int us); extern void FUN_002c75c8(void);
int FUN_000468f4(void) { DAT_003ba328 = 1; while (DAT_003b3e5c) { FUN_00046664(DAT_00375af4); FUN_002c7628(1000); } FUN_002c75c8(); return 0; }

/* HSTMATCH module=hstp_trans_main.prx start=0x002441f4 end=0x0024422c symbol=FUN_002441f4 */
/* Clone of src/eboot/FUN_002340f4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
void FUN_002441f4(int *p) { int i; *p = 89; for (i = 0; i < 10; i++) { p[1] = 89; p++; } }

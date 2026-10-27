/* HSTMATCH module=hstp_trans_main.prx start=0x000133f4 end=0x0001342c symbol=FUN_000133f4 lang=c99 cc=gcc171-O2 */
/* Clone of src/eboot/FUN_000133f4.c (hstclone.py tag a2c1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct R { char pad[0xa8]; unsigned long long next; };
extern struct R *FUN_0000fe3c(void);
void FUN_000133f4(unsigned seed) { FUN_0000fe3c()->next = seed; }

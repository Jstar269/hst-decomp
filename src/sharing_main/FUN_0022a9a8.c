/* HSTMATCH module=hstp_trans_main.prx start=0x0022a9a8 end=0x0022a9ec symbol=FUN_0022a9a8 lang=c99 */
/* Clone of src/eboot/FUN_0021b434.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern int FUN_0023ce60(void);
extern void FUN_00108aec(int param_1);

void FUN_0022a9a8(int param_1)
{
  if (*(unsigned char *)(param_1 + 0x54) != 0)
    return;
  if (*(int *)(FUN_0023ce60() + 0x138) != 0)
    return;
  FUN_00108aec(param_1);
}

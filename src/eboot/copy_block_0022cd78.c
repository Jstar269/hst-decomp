/* HSTMATCH module=EBOOT.BIN start=0x0022cd78 end=0x0022cdd0 symbol=FUN_0022cd78 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002c9b38[];
extern int DAT_0034a318[];

void FUN_0022cd78(void)
{
  int i;
  for (i = 0; i < 15; i++)
    DAT_0034a318[i] = DAT_002c9b38[i];
}

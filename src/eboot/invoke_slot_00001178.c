/* HSTMATCH module=EBOOT.BIN start=0x00001178 end=0x000011b0 symbol=FUN_00001178 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_00001178(int *self)
{
  if (self[0] == 0) return;
  if (self[2] == 0) return;
  ((void (*)(int,int))self[2])(self[0],-1);
}

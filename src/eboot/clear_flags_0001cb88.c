/* HSTMATCH module=EBOOT.BIN start=0x0001cb88 end=0x0001cbc8 symbol=FUN_0001cb88 lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); exact match verified; names and types await human review. */
/* Clears three byte flags at +0x1008, +0x1009 and +0x100c; when the +0x1009 flag was set it first logs through
   FUN_0001c104. Matching idiom: the flag store is written BEFORE the log call (not after), which is what makes
   MWCC materialise the message address fully before the `jal` and put the store in the delay slot. */
extern char DAT_0030ab9c[];

extern void FUN_0001c104(char *msg);

void FUN_0001cb88(char *self)
{
  if (*(unsigned char *)(self + 0x1009)) {
    *(unsigned char *)(self + 0x1009) = 0;
    FUN_0001c104(DAT_0030ab9c);
  }
  *(unsigned char *)(self + 0x1008) = 0;
  *(unsigned char *)(self + 0x100c) = 0;
}

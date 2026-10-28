/* HSTMATCH module=EBOOT.BIN start=0x0001cb88 end=0x0001cbc8 symbol=FUN_0001cb88 lang=c */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); names and types await human review. */

extern char DAT_0030ab9c[];

extern void FUN_0001c104(char *msg);

void FUN_0001cb88(char *self)
{
  if (*(unsigned char *)(self + 0x1009)) {
    FUN_0001c104(DAT_0030ab9c);
    *(unsigned char *)(self + 0x1009) = 0;
  }
  *(unsigned char *)(self + 0x1008) = 0;
  *(unsigned char *)(self + 0x100c) = 0;
}

/* Lane dsn2 shape map (3 compiles; 16/16 words - ONLY the jal delay slot differs, 2 words).
   Retail: lbu v1,0x1009(a0); beqz v1,<second store>; move s0,a0 (delay); lui a0,0x31; addiu a0,a0,-21604;
   jal 0x1c104; sb zero,0x1009(s0) IN THE DELAY SLOT; sb zero,0x1008(s0); sb zero,0x100c(s0).
   Semantics the branch target reveals (this was the real fix): only the tested flag's clear is conditional - the
   0x1008 and 0x100c stores are UNCONDITIONAL, so they sit after the if-block. Writing all three inside the if
   branches past them (0x1cbb8 instead of 0x1cbb0) and costs a word.
   What does not match: MWCC here defers the argument's `addiu` past the jal into the delay slot (lui; jal;
   addiu), retail materialised the whole address before the call and put the 0x1009 store in the slot. Reordering
   the stores in the source (flag cleared last) did not change it - the slot filler prefers the address fixup.
   Next step: a source form that forces the symbol address to be fully materialised before the call (e.g. a local
   holding the message that does not disturb the lbu-first top). Nothing else is left in this function. */
// near miss from lane dsn2 (unreviewed)

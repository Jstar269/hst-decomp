/* HSTMATCH module=EBOOT.BIN start=0x0022cc04 end=0x0022cc54 symbol=FUN_0022cc04 lang=c99 */
/* Hand-written reconstruction (external matching lane): both byte tests are written as
   `((x != 0) ^ 1)`, which is what makes mwcc emit `lbu; sltu v1,zero,v1; xori v1,1; beqz` (a plain
   `x == 0` gives beqz on the loaded byte instead). The 0xe04f / 0xc208 offsets come out of
   DAT_003415a8 + 0x10000 with negative displacements, and both loads are unsigned (`lbu`).
   Exact match verified; names and types await human review. */
extern char *DAT_003415a8;  /* address of the global system block */

/* Returns 1 when the byte at 0xe04f is zero and bit 1 of the byte at 0xc208 is clear. */
int FUN_0022cc04(void)
{
    int allowed;

    allowed = 0;
    if ((((int)*(unsigned char *)(DAT_003415a8 + 0xe04f) != 0) ^ 1) &&
        ((((int)*(unsigned char *)(DAT_003415a8 + 0xc208) & 2) != 0) ^ 1)) {
        allowed = 1;
    }
    return allowed;
}

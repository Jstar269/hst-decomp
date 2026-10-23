/* HSTMATCH module=EBOOT.BIN start=0x0022cc04 end=0x0022cc54 symbol=FUN_0022cc04 lang=c99 */
/* Hand-written reconstruction (external matching lane): both byte tests are written as
   `((x != 0) ^ 1)`, which is what makes mwcc emit `lbu; sltu v1,zero,v1; xori v1,1; beqz` (a plain
   `x == 0` gives beqz on the loaded byte instead). The 0xe04f / 0xc208 offsets come out of
   DAT_003415a8 + 0x10000 with negative displacements, and both loads are unsigned (`lbu`).
   Exact match verified; names and types await human review. */
extern char *DAT_003415a8;

int FUN_0022cc04(void)
{
    int uVar1;

    uVar1 = 0;
    if ((((int)*(unsigned char *)(DAT_003415a8 + 0xe04f) != 0) ^ 1) &&
        ((((int)*(unsigned char *)(DAT_003415a8 + 0xc208) & 2) != 0) ^ 1)) {
        uVar1 = 1;
    }
    return uVar1;
}

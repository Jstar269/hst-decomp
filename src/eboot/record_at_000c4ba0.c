/* HSTMATCH module=EBOOT.BIN start=0x000c4ba0 end=0x000c4bd4 symbol=FUN_000c4ba0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002d5af8[];
struct E { char pad[464]; };

char *FUN_000c4ba0(void *a0, int i)
{
    return (char *)a0 + DAT_002d5af8[i] * 464 + 64;
}

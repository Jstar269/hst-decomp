/* HSTMATCH module=EBOOT.BIN start=0x00226128 end=0x00226138 symbol=FUN_00226128 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x118]; unsigned char flag; } C118;
typedef struct { char pad[0x24]; C118 *c; } B24;
typedef struct { char pad[0x3c]; B24 *b; } A3c;

unsigned char FUN_00226128(A3c *a)
{
    return a->b->c->flag;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x0023569c end=0x002356ac symbol=FUN_0023569c */
/* Clone of src/eboot/FUN_00226128.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x118]; unsigned char flag; } C118;
typedef struct { char pad[0x24]; C118 *c; } B24;
typedef struct { char pad[0x3c]; B24 *b; } A3c;

unsigned char FUN_0023569c(A3c *a)
{
    return a->b->c->flag;
}

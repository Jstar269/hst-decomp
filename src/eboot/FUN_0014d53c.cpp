/* HSTMATCH module=EBOOT.BIN start=0x0014d53c end=0x0014d630 symbol=FUN_0014d53c lang=c++ helpers=FUN_0014c610@0x0014c610-0x0014c63c */
/* Hand-written reconstruction from the disassembly (same-file static log stub FUN_0014c610 placed by helpers=; the factory returns the object it creates, and both loop counters are block-scoped); exact match verified; names and types await human review. */
extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern char DAT_002dc270[];
extern char DAT_003402f4[];

extern "C" {
static void FUN_0014c610(...) {}
void *FUN_00000bcc(int);
void *FUN_0014d630(void *, int, int, int);

/* Copies a record's data block (count at +0xc, ints from +0x10) into the global
   table at DAT_003402f4 + 0x20, then creates and initialises one 0x28-byte object
   from the record's id (+8) and the descriptor's fields 0 and 3. */
void *FUN_0014d53c(int *param_1, int *param_2)
{
    int id;
    int value;
    unsigned count;
    void *p;

    if (DAT_003402f0 != 0) {
        switch (DAT_003402f0) {
        case 0:
            id = param_1[2];
            break;
        default:
            FUN_0014c610(DAT_002dc240);
            for (int n = 0; n < param_2[6] + 1; n++)
                FUN_0014c610(DAT_002dc24c);
            id = param_1[2];
            break;
        }
        FUN_0014c610(DAT_002dc270, id);
    }
    count = param_1[3];
    value = param_2[0];
    for (int k = 0; k < count; k++)
        ((int *)DAT_003402f4)[k + 8] = param_1[k + 4];
    p = (void *)FUN_00000bcc(0x28);
    if (p != 0)
        p = FUN_0014d630(p, value, param_1[2], param_2[3]);
    return p;
}
}

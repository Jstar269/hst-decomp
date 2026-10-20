/* HSTMATCH module=EBOOT.BIN start=0x001930c4 end=0x00193118 symbol=FUN_001930c4 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { int count; unsigned char *items; } Table;
extern Table *DAT_00341734;

unsigned char *FUN_001930c4(int index)
{
    if (DAT_00341734 != 0 && index >= 0 && (unsigned int)index < (unsigned int)DAT_00341734->count)
        return DAT_00341734->items + index * 108;
    return 0;
}

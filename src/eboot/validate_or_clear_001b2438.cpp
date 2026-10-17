/* HSTMATCH module=EBOOT.BIN start=0x001b2438 end=0x001b247c symbol=FUN_001b2438 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int FUN_00062a6c(int value);

extern "C" int FUN_001b2438(void *self, int *value)
{
    if (*value < 0 || FUN_00062a6c(*value) == 0) {
        *value = -1;
        return 0;
    }
    return 1;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x001c04cc end=0x001c0510 symbol=FUN_001c04cc lang=c++ */
/* Clone of src/eboot/validate_or_clear_001b2438.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int FUN_00063930(int value);

extern "C" int FUN_001c04cc(void *self, int *value)
{
    if (*value < 0 || FUN_00063930(*value) == 0) {
        *value = -1;
        return 0;
    }
    return 1;
}

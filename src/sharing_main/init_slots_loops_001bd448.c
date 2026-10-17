/* HSTMATCH module=hstp_trans_main.prx start=0x001bd448 end=0x001bd4e4 symbol=FUN_001bd448 lang=c99 */
/* Clone of src/eboot/init_slots_loops_001afd70.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: loop bounds written inclusive (i <= 0x31 etc.) to get slti at; exact match verified; names and types await human review. */
extern void FUN_001bde64(char *self, int idx);

void FUN_001bd448(char *self)
{
    int i;
    i = 0x28;
    do {
        FUN_001bde64(self, i);
        i = i + 1;
    } while (i <= 0x31);
    i = 0x84;
    do {
        FUN_001bde64(self, i);
        i = i + 1;
    } while (i <= 0x97);
    i = 0x98;
    do {
        FUN_001bde64(self, i);
        i = i + 1;
    } while (i <= 0xab);
    *(int *)(self + 0x7a4) = -1;
    *(int *)(self + 0x7c4) = -1;
    *(int *)(self + 0x7c8) = 0x1da;
}

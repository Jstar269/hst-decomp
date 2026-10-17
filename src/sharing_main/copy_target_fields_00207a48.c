/* HSTMATCH module=hstp_trans_main.prx start=0x00207a48 end=0x00207a94 symbol=FUN_00207a48 lang=c99 */
/* Clone of src/eboot/copy_target_fields_001f9390.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: used an early null return and reloaded the owner pointer for the final helper call; exact match verified; names and types await human review. */
extern void FUN_00228f68(void *, int);

void FUN_00207a48(char *self)
{
    char *target = *(char **)(self + 0x564);
    if (target == 0) return;
    *(float *)(target + 0x10) = *(float *)(self + 0x570);
    *(float *)(target + 0x14) = *(float *)(self + 0x574);
    *(float *)(target + 0x18) = *(float *)(self + 0x578);
    *(float *)(target + 0x1c) = *(float *)(self + 0x57c);
    FUN_00228f68(*(void **)(self + 0x564), 3);
}

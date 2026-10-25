/* HSTMATCH module=EBOOT.BIN start=0x00003100 end=0x00003148 symbol=FUN_00003100 lang=c99 */
/* Clone of src/sharing_main/check_and_load_00003100.c (hstclone.py tag ag56e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern int FUN_000030d0(void *);
extern int *FUN_00003148(void *);
extern int FUN_00003168(void *);

int FUN_00003100(void *param_1)
{
    if (FUN_000030d0(param_1)) {
        return *FUN_00003148(param_1);
    }
    return (unsigned char)FUN_00003168(param_1);
}

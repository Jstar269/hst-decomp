/* HSTMATCH module=hstp_trans_main.prx start=0x00050848 end=0x000508a0 symbol=FUN_00050848 lang=c99 */
/* Clone of src/eboot/lookup_then_call_0004ff14.c (hstclone.py tag a0db26hsEB): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *FUN_00050aec(void *a, void *b);
extern int FUN_0003363c(void *obj, void *arg);

int FUN_00050848(void *a, void *b, void *arg)
{
    int result = 1;
    void *obj = FUN_00050aec(a, b);
    if (obj != 0) {
        result = FUN_0003363c(obj, arg);
        if (result == 0) {
            result = 1;
        }
    }
    return result;
}

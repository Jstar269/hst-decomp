/* HSTMATCH module=hstp_trans_main.prx start=0x000507f0 end=0x00050848 symbol=FUN_000507f0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *FUN_00050aec(void *a, void *b);
extern int FUN_00033628(void *obj, void *arg);

int FUN_000507f0(void *a, void *b, void *arg)
{
    int result = 1;
    void *obj = FUN_00050aec(a, b);
    if (obj != 0) {
        result = FUN_00033628(obj, arg);
        if (result == 0) {
            result = 1;
        }
    }
    return result;
}

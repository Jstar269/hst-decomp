/* HSTMATCH module=EBOOT.BIN start=0x0004ff14 end=0x0004ff6c symbol=FUN_0004ff14 lang=c99 */
/* Clone of src/sharing_main/lookup_then_call_000507f0.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *FUN_00050210(void *a, void *b);
extern int FUN_00033600(void *obj, void *arg);

int FUN_0004ff14(void *a, void *b, void *arg)
{
    int result = 1;
    void *obj = FUN_00050210(a, b);
    if (obj != 0) {
        result = FUN_00033600(obj, arg);
        if (result == 0) {
            result = 1;
        }
    }
    return result;
}

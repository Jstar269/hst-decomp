/* HSTMATCH module=EBOOT.BIN start=0x00000f98 end=0x0000100c symbol=FUN_00000f98 lang=c99 */
/* Clone of src/sharing_main/call_init_funcs_00000f98.c (hstclone.py tag u5fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void FUN_00002774(void *a, void *b);

typedef void (*Func)(void);

void FUN_00000f98(Func *first, Func *last, void *arg3, void *arg4)
{
    for (Func *p = first; p < last; ++p) {
        (*p)();
    }
    FUN_00002774(arg3, arg4);
}

/* HSTMATCH module=EBOOT.BIN start=0x001b210c end=0x001b2180 symbol=FUN_001b210c lang=c99 */
/* Clone of src/sharing_main/handle_set_fixed_001c01a0.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* If FUN_001b2438 accepts the handle (it resets *h to -1 when invalid), pass the two floats to FUN_00062a9c
   as 1/128 fixed-point ints; returns whether the handle was valid. */
extern int FUN_001b2438(void *self, int *h);
extern void FUN_00062a9c(int h, int x, int y);

int FUN_001b210c(void *self, int *h, float x, float y)
{
    if (!FUN_001b2438(self, h)) return 0;
    FUN_00062a9c(*h, (int)(x * 128.0f), (int)(y * 128.0f));
    return 1;
}

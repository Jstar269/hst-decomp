/* HSTMATCH module=hstp_trans_main.prx start=0x001c01a0 end=0x001c0214 symbol=FUN_001c01a0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* If FUN_001c04cc accepts the handle (it resets *h to -1 when invalid), pass the two floats to FUN_00063960
   as 1/128 fixed-point ints; returns whether the handle was valid. */
extern int FUN_001c04cc(void *self, int *h);
extern void FUN_00063960(int h, int x, int y);

int FUN_001c01a0(void *self, int *h, float x, float y)
{
    if (!FUN_001c04cc(self, h)) return 0;
    FUN_00063960(*h, (int)(x * 128.0f), (int)(y * 128.0f));
    return 1;
}

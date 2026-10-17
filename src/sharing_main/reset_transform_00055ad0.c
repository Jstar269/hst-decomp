/* HSTMATCH module=hstp_trans_main.prx start=0x00055ad0 end=0x00055b54 symbol=FUN_00055ad0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: prototyped float callee signatures for proper EABI float argument passing; exact match verified; names and types await human review. */

extern const char DAT_002cc260[];
extern void FUN_00055b64(void *self, const void *mat);
extern void FUN_00055c0c(void *self, float val);
extern void FUN_00034200(void *p);
extern void FUN_00055b54(void *self, float x, float y, float z);

void FUN_00055ad0(char *self)
{
    *(unsigned char *)(self + 0x90) = 0;
    *(int *)(self + 0x8c) = 0;
    FUN_00055b64(self, DAT_002cc260);
    FUN_00055c0c(self, 1.0f);
    *(float *)(self + 0x80) = 0.0f;
    *(float *)(self + 0x94) = 1.0f;
    FUN_00034200(self + 0x10);
    *(float *)(self + 0x20) = 0.0f;
    *(float *)(self + 0x28) = 0.0f;
    *(float *)(self + 0x24) = 0.0f;
    *(float *)(self + 0x2c) = 0.5f;
    FUN_00055b54(self, -1.0f, 0.0f, 0.0f);
}

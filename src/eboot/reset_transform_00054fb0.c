/* HSTMATCH module=EBOOT.BIN start=0x00054fb0 end=0x00055034 symbol=FUN_00054fb0 lang=c99 */
/* Clone of src/sharing_main/reset_transform_00055ad0.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: prototyped float callee signatures for proper EABI float argument passing; exact match verified; names and types await human review. */

extern const char DAT_002bc410[];
extern void FUN_00055044(void *self, const void *mat);
extern void FUN_000550ec(void *self, float val);
extern void FUN_000341d8(void *p);
extern void FUN_00055034(void *self, float x, float y, float z);

void FUN_00054fb0(char *self)
{
    *(unsigned char *)(self + 0x90) = 0;
    *(int *)(self + 0x8c) = 0;
    FUN_00055044(self, DAT_002bc410);
    FUN_000550ec(self, 1.0f);
    *(float *)(self + 0x80) = 0.0f;
    *(float *)(self + 0x94) = 1.0f;
    FUN_000341d8(self + 0x10);
    *(float *)(self + 0x20) = 0.0f;
    *(float *)(self + 0x28) = 0.0f;
    *(float *)(self + 0x24) = 0.0f;
    *(float *)(self + 0x2c) = 0.5f;
    FUN_00055034(self, -1.0f, 0.0f, 0.0f);
}

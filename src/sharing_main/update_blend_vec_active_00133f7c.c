/* HSTMATCH module=hstp_trans_main.prx start=0x00133f7c end=0x00133ffc symbol=FUN_00133f7c lang=c99 */
/* Clone of src/eboot/update_blend_vec_active_00128d0c.c (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: typed Vec4 difference assignment and Vec3Pad local; exact match verified; names and types await human review. */
typedef unsigned char uchar;
typedef unsigned int uint;

struct Vec4 {
    float x, y, z, w;
};

struct Vec3Pad {
    float x, y, z;
    int pad;
};

extern void FUN_0002245c(struct Vec4 *, const void *, const void *);
extern void FUN_00022540(struct Vec3Pad *, const void *);
extern float FUN_0000c6f4(float, float);

void FUN_00133f7c(char *param_1)
{
    struct Vec4 diff;
    struct Vec3Pad local_10;
    struct Vec4 tmp;

    if (*(uchar *)(param_1 + 0x1e0) != 0) {
        FUN_0002245c(&tmp, param_1 + 0x1d0, param_1 + 0x1b0);
        diff = tmp;
        *(float *)(param_1 + 0x1e8) = *(float *)(param_1 + 0x1e4);
        FUN_00022540(&local_10, &diff);
        local_10.pad = 0;
        *(float *)(param_1 + 0x1e4) = FUN_0000c6f4(local_10.x, local_10.z);
    }
}

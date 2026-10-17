/* HSTMATCH module=EBOOT.BIN start=0x00060ed8 end=0x00060fb0 symbol=FUN_00060ed8 lang=c99 */
/* Clone of src/sharing_main/set_camera_matrices_00061d5c.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed fields as float to emit lwc1/swc1 and typed fallback pointer to DAT_003313c4; exact match verified; names and types await human review. */

extern char *DAT_003313c4;
extern float FUN_0000c000(float angle);

void FUN_00060ed8(char *param_1, char *param_2)
{
    if (param_2 == 0) {
        param_2 = DAT_003313c4;
    }
    char *v1 = param_2;
    if (v1 == 0) {
        v1 = DAT_003313c4;
    }

    *(float *)(v1 + 0x1e0) = *(float *)(param_1 + 0x30);
    *(float *)(v1 + 0x1e4) = *(float *)(param_1 + 0x34);
    *(float *)(v1 + 0x1e8) = *(float *)(param_1 + 0x38);
    *(float *)(v1 + 0x1ec) = *(float *)(param_1 + 0x3c);

    *(float *)(v1 + 0x1f0) = *(float *)(param_1 + 0x20);
    *(float *)(v1 + 0x1f4) = *(float *)(param_1 + 0x24);
    *(float *)(v1 + 0x1f8) = *(float *)(param_1 + 0x28);
    *(float *)(v1 + 0x1fc) = *(float *)(param_1 + 0x2c);

    *(float *)(v1 + 0x1d0) = *(float *)(param_1 + 0x40);
    *(float *)(v1 + 0x1d4) = *(float *)(param_1 + 0x44);
    *(float *)(v1 + 0x1d8) = *(float *)(param_1 + 0x48);
    *(float *)(v1 + 0x1dc) = *(float *)(param_1 + 0x4c);

    float f = *(float *)(param_1 + 0x80);
    *(float *)(param_2 + 0x200) = f;
    *(float *)(param_2 + 0x214) = FUN_0000c000(f * 0.008726646f);
    *(float *)(param_2 + 0x204) = *(float *)(param_1 + 0x84);
    *(float *)(param_2 + 0x208) = *(float *)(param_1 + 0x88);
}

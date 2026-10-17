/* HSTMATCH module=hstp_trans_main.prx start=0x00061d5c end=0x00061e34 symbol=FUN_00061d5c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed fields as float to emit lwc1/swc1 and typed fallback pointer to DAT_003da704; exact match verified; names and types await human review. */

extern char *DAT_003da704;
extern float FUN_0000c018(float angle);

void FUN_00061d5c(char *param_1, char *param_2)
{
    if (param_2 == 0) {
        param_2 = DAT_003da704;
    }
    char *v1 = param_2;
    if (v1 == 0) {
        v1 = DAT_003da704;
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
    *(float *)(param_2 + 0x214) = FUN_0000c018(f * 0.008726646f);
    *(float *)(param_2 + 0x204) = *(float *)(param_1 + 0x84);
    *(float *)(param_2 + 0x208) = *(float *)(param_1 + 0x88);
}

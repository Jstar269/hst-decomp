/* HSTMATCH module=EBOOT.BIN start=0x002a51ec end=0x002a5370 symbol=FUN_002a51ec lang=c99 */
/* Near miss: 94/97 words matched retail. Loop latch and bit-test ternary decoded; s1/s2 counter allocation and blez delay slot scheduling remain. */

extern int DAT_00300a8c;
extern char DAT_00300a90;
extern void *DAT_00310fc4;

extern void *FUN_00011090(char *dest, const char *src, int n);
extern void FUN_000149a8(void *dst, const void *src);
extern int FUN_00014a40(const char *str);
extern void FUN_0004344c(void *ctx, const char *str, int *p4, int *p8, void *p0);

void FUN_002a51ec(char *param_1, void *param_2, void *param_3)
{
    int local_4;
    int local_8;
    char buf[128];
    int local_24;
    int total_len;
    int offset;
    int count;

    local_4 = 0;
    local_8 = 0;
    FUN_0004344c(DAT_00310fc4, param_1, &local_4, &local_8, 0);
    total_len = FUN_00014a40(param_1);
    offset = 0;
    count = 0;
    FUN_000149a8(param_2, &DAT_00300a90);
    FUN_000149a8(param_3, &DAT_00300a90);

    if (total_len < 1) {
        return;
    }

    char *pcVar2 = param_1;
    do {
        int iVar4 = 1;
        local_24 = 0;
        do {
            if (((int)*pcVar2 & (1 << (7 - local_24))) == 0) {
                int *piVar3;
                if (local_24 < DAT_00300a8c) {
                    piVar3 = &DAT_00300a8c;
                } else {
                    piVar3 = &local_24;
                }
                iVar4 = *piVar3;
                break;
            }
            local_24++;
        } while (local_24 < 8);

        offset += iVar4;
        FUN_00011090(buf, param_1, offset);
        buf[offset] = 0;
        FUN_0004344c(DAT_00310fc4, buf, &local_4, &local_8, 0);
        count++;

        if (count > 11) {
            break;
        }
        pcVar2 = param_1 + offset;
    } while (offset < total_len);

    FUN_000149a8(param_2, buf);
    FUN_000149a8(param_3, param_1 + offset);
}
// near miss from lane u6fr1-0 (unreviewed)

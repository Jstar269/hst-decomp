/* HSTMATCH module=EBOOT.BIN start=0x001b4a70 end=0x001b4b64 symbol=FUN_001b4a70 lang=c99 */
extern char DAT_002e7700[];
extern int DAT_0034178c;
extern unsigned char *DAT_00338b44;
extern int FUN_00062b64(int, int, int);

int FUN_001b4a70(int *param_1, int param_2, int param_3)
{
    int base = *param_1;
    int *t = (int *)(DAT_002e7700 + param_3 * 0x1c);
    int flag = !DAT_00338b44[0x45];
    int sel = *(unsigned char *)(param_2 + base + 0x798) != 0 ? 2 : 0;
    int n = *(unsigned char *)((char *)t + sel + flag + 4);

    if (n > 0) {
        DAT_0034178c = DAT_0034178c * 0x343fd + 0x269ec3;
        if (*t == 0xc3) {
            int p = *(int *)(param_2 * 4 + base + 0x768);
            if (p != 0)
                return FUN_00062b64(p, t[((DAT_0034178c & 0x7fffffff) >> 16) % n + 2], 0);
        }
    }
    return -1;
}
// near miss: 61/61 words, 36 differ, first at +0x2c. Retail loads the flag byte (lbu) BEFORE the
// address computation and emits sltu a2,zero,a2 / xori a2,a2,1 / beqz / andi a2,a2,0xff in the branch
// delay; ours schedules the flag load after and drops the sltu+andi rotation. Ruled out: flag as
// an expression inside the index (slower schedule), signed char pointer (lb, no sltu), `!x` with
// unsigned char (same rotation, still one instruction missing).
// near miss from lane fm6 (unreviewed)

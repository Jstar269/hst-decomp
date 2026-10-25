/* HSTMATCH module=EBOOT.BIN start=0x00064820 end=0x000649c0 symbol=FUN_00064820 lang=c99 */
extern int DAT_00307148;
extern int DAT_00307124;
extern int DAT_00307100;
extern int DAT_003070dc;

extern void *FUN_00000bcc(unsigned int);
extern void *FUN_00000a90(unsigned int);
extern unsigned int FUN_00014a40(const char *);
extern void FUN_000149a8(void *, const char *);
extern double FUN_0000d610(const char *);
extern int FUN_0000d62c(const char *);
extern float FUN_000223a0(int, int);

int *FUN_00064820(char *s)
{
    char c;
    char *p;
    int *o;
    unsigned int n;
    int invalid;
    int dot;

    invalid = 0;
    dot = 0;
    if (*s != '\0') {
        c = *s;
        p = s;
        while (('/' < c && c < ':') || c == '.' || c == '-') {
            if (c == '.') {
                dot = 1;
                goto done;
            }
            p++;
            if (*p == '\0')
                goto done;
            c = *p;
        }
        invalid = 1;
    }
done:
    if (invalid || FUN_00014a40(s) == 0) {
        o = (int *)FUN_00000bcc(8);
        if (o != 0) {
            *o = (int)&DAT_00307148;
            *o = (int)&DAT_00307124;
            o[1] = 0;
            if (s != 0) {
                n = FUN_00014a40(s);
                o[1] = (int)FUN_00000a90(n + 1);
                FUN_000149a8((void *)o[1], s);
            }
        }
    } else if (dot) {
        o = (int *)FUN_00000bcc(8);
        if (o != 0) {
            double d = FUN_0000d610(s);
            float f = FUN_000223a0((int)*(long long *)&d, (int)(*(long long *)&d >> 32));
            *o = (int)&DAT_00307148;
            *o = (int)&DAT_00307100;
            o[1] = (int)f;
        }
    } else {
        o = (int *)FUN_00000bcc(8);
        if (o != 0) {
            int v = FUN_0000d62c(s);
            *o = (int)&DAT_00307148;
            *o = (int)&DAT_003070dc;
            o[1] = v;
        }
    }
    return o;
}
// near miss from lane fm11 (unreviewed)

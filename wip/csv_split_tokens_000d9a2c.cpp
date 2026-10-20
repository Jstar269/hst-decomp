/* HSTMATCH module=EBOOT.BIN start=0x000d9a2c end=0x000d9b1c symbol=FUN_000d9a2c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_002d6acc[];

extern "C" void FUN_0005da00(void *, char **, char);

extern "C" void FUN_000d9a2c(int *vec, char *s) {
    char *local = 0;
    char *start = 0;
    char c = *s;
    if (c == 0) return;
    do {
        if (c == ',' || c == '\r' || c == '\n') {
            *s = 0;
            s++;
            if (local == 0) local = DAT_002d6acc;
            if ((unsigned)vec[1] < (unsigned)vec[2]) {
                vec[1] = vec[1] + 1;
                *(char **)(vec[0] + vec[1] * 4 - 4) = local;
            } else {
                FUN_0005da00(vec, &local, 0);
            }
            local = 0;
            start = 0;
        } else {
            if (start == 0) {
                local = s;
                start = s;
            }
        }
        s++;
        c = *s;
    } while (c != 0);
}
// near miss from lane ds7 (unreviewed)

/* HSTMATCH module=EBOOT.BIN start=0x0028b654 end=0x0028b93c symbol=FUN_0028b654 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the digit scan is a for loop with an EMPTY body, `for (p = us + 1; (*p < '0' || *p > '9') && *p != 0; p++) {}`; names and types await human review. */
extern char DAT_002fedd8[];
extern char DAT_002fede0[];
extern char DAT_002fede8[];
extern char DAT_002fedf0[];
extern char DAT_002fedf8[];
extern char DAT_002fee00[];
extern char DAT_002fee08[];
extern char DAT_002fee14[];
extern char DAT_002fee1c[];
extern char DAT_002fee28[];
extern char DAT_002fee38[];
extern char DAT_002fee48[];
extern char DAT_002fee58[];
extern char DAT_002fed60[];
extern char DAT_002fee64[];
extern char DAT_002fee6c[];
extern int FUN_00014a40(const char *);
extern char *FUN_000149a8(char *, const char *);
extern char *FUN_00014cfc(const char *, int);
extern int FUN_0000d62c(const char *);
extern int FUN_00014934(const char *, const char *);

void FUN_0028b654(int unused, const char *name, int *kind, int *num)
{
    if (name == 0 || FUN_00014a40(name) == 0) {
        *kind = -1;
        *num = -1;
    } else {
        char buf[32] = {0};
        char *us;
        char *p;
        FUN_000149a8(buf, name);
        us = FUN_00014cfc(buf, 0x5f);
        if (us == 0) {
            *kind = -1;
            *num = -1;
        } else {
            *us = 0;
            for (p = us + 1; (*p < '0' || *p > '9') && *p != 0; p++) {
            }
            *num = FUN_0000d62c(p);
            if (FUN_00014934(buf, DAT_002fedd8) == 0) {
            *kind = 1;
        } else if (FUN_00014934(buf, DAT_002fede0) == 0) {
            *kind = 2;
        } else if (FUN_00014934(buf, DAT_002fede8) == 0) {
            *kind = 3;
        } else if (FUN_00014934(buf, DAT_002fedf0) == 0) {
            *kind = 4;
        } else if (FUN_00014934(buf, DAT_002fedf8) == 0) {
            *kind = 5;
        } else if (FUN_00014934(buf, DAT_002fee00) == 0) {
            *kind = 6;
        } else if (FUN_00014934(buf, DAT_002fee08) == 0) {
            *kind = 7;
        } else if (FUN_00014934(buf, DAT_002fee14) == 0) {
            *kind = 8;
        } else if (FUN_00014934(buf, DAT_002fee1c) == 0) {
            *kind = 9;
        } else if (FUN_00014934(buf, DAT_002fee28) == 0) {
            *kind = 10;
        } else if (FUN_00014934(buf, DAT_002fee38) == 0) {
            *kind = 11;
        } else if (FUN_00014934(buf, DAT_002fee48) == 0) {
            *kind = 12;
        } else if (FUN_00014934(buf, DAT_002fee58) == 0) {
            *kind = 13;
        } else if (FUN_00014934(buf, DAT_002fed60) == 0) {
            *kind = 14;
        } else if (FUN_00014934(buf, DAT_002fee64) == 0) {
            *kind = 15;
        } else if (FUN_00014934(buf, DAT_002fee6c) == 0) {
            *kind = 16;
        } else {
            *kind = -1;
            *num = -1;
        }

        }
    }
}

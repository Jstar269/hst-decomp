/* HSTMATCH module=hstp_trans_main.prx start=0x0029ce48 end=0x0029d130 symbol=FUN_0029ce48 lang=c99 data=0x003a7d4c */
/* Clone of src/eboot/parse_asset_name_0028b654.c (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (15 strings, 0x003a7d4c-0x003a7de6) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the digit scan is a for loop with an EMPTY body, `for (p = us + 1; (*p < '0' || *p > '9') && *p != 0; p++) {}`; names and types await human review. */
extern char DAT_003a7cd4[];
extern int FUN_00014a40(const char *);
extern char *FUN_000149a8(char *, const char *);
extern char *FUN_00014cfc(const char *, int);
extern int FUN_0000d644(const char *);
extern int FUN_00014934(const char *, const char *);

void FUN_0029ce48(int unused, const char *name, int *kind, int *num)
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
            *num = FUN_0000d644(p);
            if (FUN_00014934(buf, "Head") == 0) {
            *kind = 1;
        } else if (FUN_00014934(buf, "Body") == 0) {
            *kind = 2;
        } else if (FUN_00014934(buf, "Acce") == 0) {
            *kind = 3;
        } else if (FUN_00014934(buf, "Racket") == 0) {
            *kind = 4;
        } else if (FUN_00014934(buf, "Court") == 0) {
            *kind = 5;
        } else if (FUN_00014934(buf, "Judge") == 0) {
            *kind = 6;
        } else if (FUN_00014934(buf, "Item_Cam") == 0) {
            *kind = 7;
        } else if (FUN_00014934(buf, "Item_CD") == 0) {
            *kind = 8;
        } else if (FUN_00014934(buf, "Item_Voice") == 0) {
            *kind = 9;
        } else if (FUN_00014934(buf, "Item_JudgeVoice") == 0) {
            *kind = 10;
        } else if (FUN_00014934(buf, "Item_Wallpaper") == 0) {
            *kind = 11;
        } else if (FUN_00014934(buf, "Item_Tickets") == 0) {
            *kind = 12;
        } else if (FUN_00014934(buf, "Item_Stamp") == 0) {
            *kind = 13;
        } else if (FUN_00014934(buf, DAT_003a7cd4) == 0) {
            *kind = 14;
        } else if (FUN_00014934(buf, "Kunsyo") == 0) {
            *kind = 15;
        } else if (FUN_00014934(buf, "P_Set") == 0) {
            *kind = 16;
        } else {
            *kind = -1;
            *num = -1;
        }

        }
    }
}

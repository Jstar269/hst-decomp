/* HSTMATCH module=EBOOT.BIN start=0x0028b654 end=0x0028b93c symbol=FUN_0028b654 lang=c99 data=0x002fedd8 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the digit scan is a for loop with an EMPTY body, `for (p = us + 1; (*p < '0' || *p > '9') && *p != 0; p++) {}`; names and types await human review. Data: its string literals (15 strings, 0x002fedd8-0x002fee72) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Asset kind ids, taken from the name prefixes compared below. */
enum {
    ASSET_KIND_NONE = -1,
    ASSET_KIND_HEAD = 1,
    ASSET_KIND_BODY,
    ASSET_KIND_ACCE,
    ASSET_KIND_RACKET,
    ASSET_KIND_COURT,
    ASSET_KIND_JUDGE,
    ASSET_KIND_ITEM_CAM,
    ASSET_KIND_ITEM_CD,
    ASSET_KIND_ITEM_VOICE,
    ASSET_KIND_ITEM_JUDGEVOICE,
    ASSET_KIND_ITEM_WALLPAPER,
    ASSET_KIND_ITEM_TICKETS,
    ASSET_KIND_ITEM_STAMP,
    ASSET_KIND_NAMED_14,   /* prefix held in a data string */
    ASSET_KIND_KUNSYO,
    ASSET_KIND_P_SET
};

#define NAME_BUF_SIZE 32

extern char DAT_002fed60[];
extern int FUN_00014a40(const char *);
extern char *FUN_000149a8(char *, const char *);
extern char *FUN_00014cfc(const char *, int);
extern int FUN_0000d62c(const char *);
extern int FUN_00014934(const char *, const char *);

/* Splits an asset name "<Prefix>_<number>" into its kind id and number; both are -1 when the name is missing or unknown. */
void FUN_0028b654(int unused, const char *name, int *kind, int *num)
{
    if (name == 0 || FUN_00014a40(name) == 0) {
        *kind = ASSET_KIND_NONE;
        *num = -1;
    } else {
        char buf[NAME_BUF_SIZE] = {0};
        char *us;
        char *p;
        FUN_000149a8(buf, name);
        us = FUN_00014cfc(buf, '_');
        if (us == 0) {
            *kind = ASSET_KIND_NONE;
            *num = -1;
        } else {
            *us = 0;
            for (p = us + 1; (*p < '0' || *p > '9') && *p != 0; p++) {
            }
            *num = FUN_0000d62c(p);
            if (FUN_00014934(buf, "Head") == 0) {
                *kind = ASSET_KIND_HEAD;
            } else if (FUN_00014934(buf, "Body") == 0) {
                *kind = ASSET_KIND_BODY;
            } else if (FUN_00014934(buf, "Acce") == 0) {
                *kind = ASSET_KIND_ACCE;
            } else if (FUN_00014934(buf, "Racket") == 0) {
                *kind = ASSET_KIND_RACKET;
            } else if (FUN_00014934(buf, "Court") == 0) {
                *kind = ASSET_KIND_COURT;
            } else if (FUN_00014934(buf, "Judge") == 0) {
                *kind = ASSET_KIND_JUDGE;
            } else if (FUN_00014934(buf, "Item_Cam") == 0) {
                *kind = ASSET_KIND_ITEM_CAM;
            } else if (FUN_00014934(buf, "Item_CD") == 0) {
                *kind = ASSET_KIND_ITEM_CD;
            } else if (FUN_00014934(buf, "Item_Voice") == 0) {
                *kind = ASSET_KIND_ITEM_VOICE;
            } else if (FUN_00014934(buf, "Item_JudgeVoice") == 0) {
                *kind = ASSET_KIND_ITEM_JUDGEVOICE;
            } else if (FUN_00014934(buf, "Item_Wallpaper") == 0) {
                *kind = ASSET_KIND_ITEM_WALLPAPER;
            } else if (FUN_00014934(buf, "Item_Tickets") == 0) {
                *kind = ASSET_KIND_ITEM_TICKETS;
            } else if (FUN_00014934(buf, "Item_Stamp") == 0) {
                *kind = ASSET_KIND_ITEM_STAMP;
            } else if (FUN_00014934(buf, DAT_002fed60) == 0) {
                *kind = ASSET_KIND_NAMED_14;
            } else if (FUN_00014934(buf, "Kunsyo") == 0) {
                *kind = ASSET_KIND_KUNSYO;
            } else if (FUN_00014934(buf, "P_Set") == 0) {
                *kind = ASSET_KIND_P_SET;
            } else {
                *kind = ASSET_KIND_NONE;
                *num = -1;
            }
        }
    }
}

/* HSTMATCH module=EBOOT.BIN start=0x0004fb88 end=0x0004fcf8 symbol=FUN_0004fb88 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Iterates the asset bank's name table and registers names missing from the list (same lock/assert idiom as src/eboot/FUN_0004f52c.c; the object compiled with opt_strength_reduction off). */
#pragma opt_strength_reduction off
extern char DAT_002d0d40[];
extern char DAT_002d0a6c[];
extern char DAT_002d0d44[];
extern char DAT_002d0d60[];
extern char DAT_00311170[];

extern int FUN_00014934(const char *, const char *);
extern int FUN_0002fecc(void *);
extern void *FUN_0002fed8(void *, int);
extern void FUN_00049194(void);
extern int FUN_000491cc(void);
extern void FUN_0004ea98(const char *, ...);
extern void FUN_0004f010(void *, int, void *, int, void *);
extern void FUN_0004fcf8(void *, const char *);

typedef struct {
    const char **data;
    unsigned int count;
} NameList;

typedef struct {
    char pad[0x1a00c];
} Table;

void FUN_0004fb88(Table *table, void *asset, NameList *list)
{
    int i;
    const char *name;
    int missing;
    int j;
    int n;

    FUN_00049194();
    n = FUN_0002fecc(asset);
    FUN_000491cc();
    if (n < 0) {
        FUN_0004ea98(DAT_002d0d44);
        goto fail;
    }
    for (i = 0; i < n; i++) {
        FUN_00049194();
        name = (const char *)FUN_0002fed8(asset, i);
        FUN_000491cc();
        if (name == 0) {
            FUN_0004ea98(DAT_002d0d60);
            goto fail;
        }
        missing = 1;
        for (j = 0; j < list->count; j++) {
            if (FUN_00014934(list->data[j], name) == 0) {
                missing = 0;
                break;
            }
        }
        if (missing)
            FUN_0004fcf8(table, name);
    }
    return;
fail:
    FUN_0004f010(DAT_00311170, 0, DAT_002d0a6c, 1520, DAT_002d0d40);
}

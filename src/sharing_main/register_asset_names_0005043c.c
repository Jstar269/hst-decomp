/* HSTMATCH module=hstp_trans_main.prx start=0x0005043c end=0x000505ac symbol=FUN_0005043c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sharing twin of src/eboot/register_asset_names_0004fb88.c (EBOOT 0x4fb88), the same source with the addresses
   substituted. Iterates the asset bank's name table and registers names missing from the list (lock/assert idiom;
   the object compiled with opt_strength_reduction off). */
#pragma opt_strength_reduction off
extern char DAT_003767fc[];
extern char DAT_003763c8[];
extern char DAT_00376800[];
extern char DAT_0037681c[];
extern char DAT_003ba4b0[];

extern int FUN_00014934(const char *, const char *);
extern int FUN_0002fef4(void *);
extern void *FUN_0002ff00(void *, int);
extern void FUN_00048fb8(void);
extern int FUN_00049020(void);
extern void FUN_0004efe0(const char *, ...);
extern void FUN_0004f864(void *, int, void *, int, void *);
extern void FUN_000505ac(void *, const char *);

typedef struct {
    const char **data;
    unsigned int count;
} NameList;

typedef struct {
    char pad[0x1a00c];
} Table;

void FUN_0005043c(Table *table, void *asset, NameList *list)
{
    int i;
    const char *name;
    int missing;
    int j;
    int n;

    FUN_00048fb8();
    n = FUN_0002fef4(asset);
    FUN_00049020();
    if (n < 0) {
        FUN_0004efe0(DAT_00376800);
        goto fail;
    }
    for (i = 0; i < n; i++) {
        FUN_00048fb8();
        name = (const char *)FUN_0002ff00(asset, i);
        FUN_00049020();
        if (name == 0) {
            FUN_0004efe0(DAT_0037681c);
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
            FUN_000505ac(table, name);
    }
    return;
fail:
    FUN_0004f864(DAT_003ba4b0, 0, DAT_003763c8, 1520, DAT_003767fc);
}

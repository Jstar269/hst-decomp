/* HSTMATCH module=EBOOT.BIN start=0x002042c8 end=0x0020437c symbol=FUN_002042c8 lang=c99 data=0x002ef5b0 */
/* LoadChrSelParamChara: data/menu/chrselect/chrsel_param_chara.csv; see docs/DATA-TABLES.md Data: its string literals (1 strings, 0x002ef5b0-0x002ef5db) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Parameter table: 15 records of 16 bytes, allocated as an array with a 16-byte header. */
#define PARAM_RECORD_COUNT 15
#define PARAM_RECORD_SIZE 16
#define ARRAY_HEADER_SIZE 16
/* Size of the loader loaderect. */
#define LOADER_SIZE 48

extern void *DAT_0034a148; /* the record array, or 0 before loading */
extern void *DAT_0034a14c; /* the loader loaderect */
extern char DAT_0020437c[];
extern char DAT_003070bc[];

extern void *FUN_00000a90(int size);
extern void *FUN_000008d8(void *block, char *name, int zero, int a, int b);
extern void *FUN_00000bcc(int size);
extern void FUN_000649c0(void *loader);
extern void FUN_0008c230(void *p);
extern void FUN_0017b030(void *a, void *b, char *c, int d, int e);

/* One-time creation of the character-select parameter table and its loader, then loads the csv into the table. */
void FUN_002042c8(void)
{
    void *block;
    void *loader;

    if (DAT_0034a148 != 0)
        return;

    block = FUN_00000a90(PARAM_RECORD_SIZE * PARAM_RECORD_COUNT + ARRAY_HEADER_SIZE);
    DAT_0034a148 = FUN_000008d8(block, DAT_0020437c, 0, PARAM_RECORD_SIZE, PARAM_RECORD_COUNT);

    if ((loader = FUN_00000bcc(LOADER_SIZE)) != 0) {
        FUN_000649c0(loader);
        *(void **)loader = DAT_003070bc;
        FUN_0008c230((char *)loader + 16);
        FUN_0008c230((char *)loader + 32);
    }
    DAT_0034a14c = loader;
    FUN_0017b030(DAT_0034a148, loader, "data/menu/chrselect/chrsel_param_chara.csv", PARAM_RECORD_SIZE, PARAM_RECORD_COUNT);
}

/* HSTMATCH module=hstp_trans_main.prx start=0x00212b30 end=0x00212be4 symbol=FUN_00212b30 lang=c99 data=0x003976a4 */
/* Clone of src/eboot/global_alloc_init_002042c8.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003976a4-0x003976cf) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Parameter table: 15 records of 16 bytes, allocated as an array with a 16-byte header. */
#define PARAM_RECORD_COUNT 15
#define PARAM_RECORD_SIZE 16
#define ARRAY_HEADER_SIZE 16
/* Size of the loader loaderect. */
#define LOADER_SIZE 48

extern void *DAT_003f3480; /* the record array, or 0 before loading */
extern void *DAT_003f3484; /* the loader loaderect */
extern char DAT_00212be4[];
extern char DAT_003b0388[];

extern void *FUN_00000a90(int size);
extern void *FUN_000008d8(void *block, char *name, int zero, int a, int b);
extern void *FUN_00000bcc(int size);
extern void FUN_00065884(void *loader);
extern void FUN_0008d97c(void *p);
extern void FUN_00187724(void *a, void *b, char *c, int d, int e);

/* One-time creation of the character-select parameter table and its loader, then loads the csv into the table. */
void FUN_00212b30(void)
{
    void *block;
    void *loader;

    if (DAT_003f3480 != 0)
        return;

    block = FUN_00000a90(PARAM_RECORD_SIZE * PARAM_RECORD_COUNT + ARRAY_HEADER_SIZE);
    DAT_003f3480 = FUN_000008d8(block, DAT_00212be4, 0, PARAM_RECORD_SIZE, PARAM_RECORD_COUNT);

    if ((loader = FUN_00000bcc(LOADER_SIZE)) != 0) {
        FUN_00065884(loader);
        *(void **)loader = DAT_003b0388;
        FUN_0008d97c((char *)loader + 16);
        FUN_0008d97c((char *)loader + 32);
    }
    DAT_003f3484 = loader;
    FUN_00187724(DAT_003f3480, loader, "data/menu/chrselect/chrsel_param_chara.csv", PARAM_RECORD_SIZE, PARAM_RECORD_COUNT);
}

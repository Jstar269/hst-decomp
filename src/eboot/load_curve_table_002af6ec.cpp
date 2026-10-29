/* HSTMATCH module=EBOOT.BIN start=0x002af6ec end=0x002af8f4 symbol=FUN_002af6ec lang=c++ */
/* LoadPartsLevelParamTable: data/common/parts/Parts_P_Param.txt; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly (reader class pattern of src/eboot/init_items_from_config_001ed27c.cpp and virtual deleting dtor); exact match verified; names and types await human review. */
extern "C" {
extern const char DAT_00302de4[];
extern char DAT_00302e08;
extern const char DAT_00302e0c[];
extern const char DAT_00302e14[];
extern char DAT_00302e1c;

void FUN_000649c0(void *);
void FUN_0008c230(void *);
int FUN_000651b8(void *, const char *, int, int, void *);
int FUN_00065554(void *, int, const char *);
float FUN_000655f8(void *, int, const void *);
void FUN_002afaf8(void *, int);
extern char DAT_003070bc[];
}

#define LEVEL_COUNT 30  /* rows in the parameter file */

struct LevelEntry {
    int kind : 4;
    unsigned int amount : 28;
    float unk4;
};

struct CurveRow {
    float v[5];
};

struct LevelTable {
    LevelEntry entries[LEVEL_COUNT];
    CurveRow curves[LEVEL_COUNT];
};

struct ReaderBase {
    virtual ~ReaderBase();
};

/* Text reader constructed on the heap for the parameter file. */
struct Reader {
    char pad[0x30];
    Reader() {
        FUN_000649c0(this);
        *(char **)this = DAT_003070bc;
        FUN_0008c230(pad + 16);
        FUN_0008c230(pad + 32);
    }
};

/* Read the parameter file into the 30 entries, then fetch the 30 curve rows. */
extern "C" void FUN_002af6ec(LevelTable *table)
{
    Reader *obj = new Reader();
    FUN_000651b8(obj, DAT_00302de4, 0, 1, &DAT_00302e08);

    int i = 0;
    LevelEntry *cursor = table->entries;
    for (; i < LEVEL_COUNT; ++i) {
        switch (FUN_00065554(obj, i + 1, DAT_00302e0c)) {
        case 0:
            cursor->kind = 0;
            break;
        case 1:
            cursor->kind = 1;
            break;
        case 2:
            cursor->kind = 2;
            break;
        case 3:
            cursor->kind = 3;
            break;
        }

        cursor->unk4 = FUN_000655f8(obj, i + 1, DAT_00302e14);
        float value = FUN_000655f8(obj, i + 1, &DAT_00302e1c);
        cursor->amount = (int)value;
        cursor++;
    }

    if (obj) {
        delete (ReaderBase *)obj;
    }

    for (int j = 0; j < LEVEL_COUNT; ++j) {
        CurveRow row;
        FUN_002afaf8(&row, j);
        table->curves[j].v[0] = row.v[0];
        table->curves[j].v[1] = row.v[1];
        table->curves[j].v[2] = row.v[2];
        table->curves[j].v[3] = row.v[3];
        table->curves[j].v[4] = row.v[4];
    }
}

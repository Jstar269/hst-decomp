/* HSTMATCH module=hstp_trans_main.prx start=0x002bf13c end=0x002bf344 symbol=FUN_002bf13c lang=c++ */
/* Clone of src/eboot/load_curve_table_002af6ec.cpp (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (reader class pattern of src/eboot/init_items_from_config_001ed27c.cpp and virtual deleting dtor); exact match verified; names and types await human review. */
extern "C" {
extern const char DAT_003abfec[];
extern char DAT_003ac010;
extern const char DAT_003ac014[];
extern const char DAT_003ac01c[];
extern char DAT_003ac024;

void FUN_00065884(void *);
void FUN_0008d97c(void *);
int FUN_00066260(void *, const char *, int, int, void *);
int FUN_00066700(void *, int, const char *);
float FUN_0006682c(void *, int, const void *);
void FUN_002bf548(void *, int);
extern char DAT_003b0388[];
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
        FUN_00065884(this);
        *(char **)this = DAT_003b0388;
        FUN_0008d97c(pad + 16);
        FUN_0008d97c(pad + 32);
    }
};

/* Read the parameter file into the 30 entries, then fetch the 30 curve rows. */
extern "C" void FUN_002bf13c(LevelTable *table)
{
    Reader *obj = new Reader();
    FUN_00066260(obj, DAT_003abfec, 0, 1, &DAT_003ac010);

    int i = 0;
    LevelEntry *cursor = table->entries;
    for (; i < LEVEL_COUNT; ++i) {
        switch (FUN_00066700(obj, i + 1, DAT_003ac014)) {
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

        cursor->unk4 = FUN_0006682c(obj, i + 1, DAT_003ac01c);
        float value = FUN_0006682c(obj, i + 1, &DAT_003ac024);
        cursor->amount = (int)value;
        cursor++;
    }

    if (obj) {
        delete (ReaderBase *)obj;
    }

    for (int j = 0; j < LEVEL_COUNT; ++j) {
        CurveRow row;
        FUN_002bf548(&row, j);
        table->curves[j].v[0] = row.v[0];
        table->curves[j].v[1] = row.v[1];
        table->curves[j].v[2] = row.v[2];
        table->curves[j].v[3] = row.v[3];
        table->curves[j].v[4] = row.v[4];
    }
}

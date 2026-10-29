/* HSTMATCH module=EBOOT.BIN start=0x001415e8 end=0x00141718 symbol=FUN_001415e8 lang=c++ */
/* Stage_LoadAreaClip: areaclip.csv rows; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; matching idiom: the open result is a callee returning unsigned char tested with an explicit != 0 (gives retail's andi 0xff and keeps the CSV-values block first); exact match verified; names and types await human review. */
struct CsvFile { int pad[4]; };

extern "C" {
void FUN_000649c0(CsvFile *);
unsigned char FUN_00064bf4(CsvFile *, const char *, int, const char *);
int FUN_000650e0(CsvFile *);
float FUN_00065140(CsvFile *, int, int);
void FUN_00064a08(CsvFile *, int);
}

extern const char DAT_002dbb34[];

struct Obj {
    char pad0[0x1300];
    float min_a;
    float max_a;
    float min_b;
    float max_b;
    float max_c;
    float min_c;
};

/* Loads one row of the area-clip table into three min/max pairs; falls back to +-3, +-3, +-1000 when the file or row is missing. */
extern "C" void FUN_001415e8(Obj *self, int row, const char *name)
{
    CsvFile csv;

    FUN_000649c0(&csv);
    if (FUN_00064bf4(&csv, name, 1, DAT_002dbb34) != 0 && FUN_000650e0(&csv) > row) {
        self->min_a = -FUN_00065140(&csv, row, 1);
        self->max_a = -FUN_00065140(&csv, row, 0);
        self->min_b = FUN_00065140(&csv, row, 2);
        self->max_b = FUN_00065140(&csv, row, 3);
        self->min_c = FUN_00065140(&csv, row, 4);
        self->max_c = FUN_00065140(&csv, row, 5);
    } else {
        self->min_a = -3.0f;
        self->max_a = 3.0f;
        self->min_b = -3.0f;
        self->max_b = 3.0f;
        self->min_c = -1000.0f;
        self->max_c = 1000.0f;
    }
    FUN_00064a08(&csv, -1);
}

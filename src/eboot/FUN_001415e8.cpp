/* HSTMATCH module=EBOOT.BIN start=0x001415e8 end=0x00141718 symbol=FUN_001415e8 lang=c++ */
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
    float f1300;
    float f1304;
    float f1308;
    float f130c;
    float f1310;
    float f1314;
};

extern "C" void FUN_001415e8(Obj *self, int row, const char *name)
{
    CsvFile csv;

    FUN_000649c0(&csv);
    if (FUN_00064bf4(&csv, name, 1, DAT_002dbb34) != 0 && FUN_000650e0(&csv) > row) {
        self->f1300 = -FUN_00065140(&csv, row, 1);
        self->f1304 = -FUN_00065140(&csv, row, 0);
        self->f1308 = FUN_00065140(&csv, row, 2);
        self->f130c = FUN_00065140(&csv, row, 3);
        self->f1314 = FUN_00065140(&csv, row, 4);
        self->f1310 = FUN_00065140(&csv, row, 5);
    } else {
        self->f1300 = -3.0f;
        self->f1304 = 3.0f;
        self->f1308 = -3.0f;
        self->f130c = 3.0f;
        self->f1314 = -1000.0f;
        self->f1310 = 1000.0f;
    }
    FUN_00064a08(&csv, -1);
}

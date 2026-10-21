/* HSTMATCH module=hstp_trans_main.prx start=0x0014cc34 end=0x0014cd64 symbol=FUN_0014cc34 lang=c++ */
/* Clone of src/eboot/FUN_001415e8.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: the open result is a callee returning unsigned char tested with an explicit != 0 (gives retail's andi 0xff and keeps the CSV-values block first); exact match verified; names and types await human review. */
struct CsvFile { int pad[4]; };

extern "C" {
void FUN_00065884(CsvFile *);
unsigned char FUN_00065ab8(CsvFile *, const char *, int, const char *);
int FUN_00065fa4(CsvFile *);
float FUN_000660f0(CsvFile *, int, int);
void FUN_000658cc(CsvFile *, int);
}

extern const char DAT_00382d94[];

struct Obj {
    char pad0[0x1300];
    float f1300;
    float f1304;
    float f1308;
    float f130c;
    float f1310;
    float f1314;
};

extern "C" void FUN_0014cc34(Obj *self, int row, const char *name)
{
    CsvFile csv;

    FUN_00065884(&csv);
    if (FUN_00065ab8(&csv, name, 1, DAT_00382d94) != 0 && FUN_00065fa4(&csv) > row) {
        self->f1300 = -FUN_000660f0(&csv, row, 1);
        self->f1304 = -FUN_000660f0(&csv, row, 0);
        self->f1308 = FUN_000660f0(&csv, row, 2);
        self->f130c = FUN_000660f0(&csv, row, 3);
        self->f1314 = FUN_000660f0(&csv, row, 4);
        self->f1310 = FUN_000660f0(&csv, row, 5);
    } else {
        self->f1300 = -3.0f;
        self->f1304 = 3.0f;
        self->f1308 = -3.0f;
        self->f130c = 3.0f;
        self->f1314 = -1000.0f;
        self->f1310 = 1000.0f;
    }
    FUN_000658cc(&csv, -1);
}

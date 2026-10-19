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

struct Elem1 {
    int lo : 4;
    unsigned int hi : 28;
    float f4;
};

struct Vec5 {
    float v[5];
};

struct Data {
    Elem1 elems[30];
    Vec5 vecs[30];
};

struct Base {
    virtual ~Base();
};

struct Res {
    char pad[0x30];
    Res() {
        FUN_00065884(this);
        *(char **)this = DAT_003b0388;
        FUN_0008d97c(pad + 16);
        FUN_0008d97c(pad + 32);
    }
};

extern "C" void FUN_002bf13c(Data *param_1)
{
    Res *obj = new Res();
    FUN_00066260(obj, DAT_003abfec, 0, 1, &DAT_003ac010);

    int i = 0;
    Elem1 *cursor = param_1->elems;
    for (; i < 30; ++i) {
        switch (FUN_00066700(obj, i + 1, DAT_003ac014)) {
        case 0:
            cursor->lo = 0;
            break;
        case 1:
            cursor->lo = 1;
            break;
        case 2:
            cursor->lo = 2;
            break;
        case 3:
            cursor->lo = 3;
            break;
        }

        cursor->f4 = FUN_0006682c(obj, i + 1, DAT_003ac01c);
        float f = FUN_0006682c(obj, i + 1, &DAT_003ac024);
        cursor->hi = (int)f;
        cursor++;
    }

    if (obj) {
        delete (Base *)obj;
    }

    for (int j = 0; j < 30; ++j) {
        Vec5 vec;
        FUN_002bf548(&vec, j);
        param_1->vecs[j].v[0] = vec.v[0];
        param_1->vecs[j].v[1] = vec.v[1];
        param_1->vecs[j].v[2] = vec.v[2];
        param_1->vecs[j].v[3] = vec.v[3];
        param_1->vecs[j].v[4] = vec.v[4];
    }
}

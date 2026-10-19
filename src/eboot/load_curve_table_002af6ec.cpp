/* HSTMATCH module=EBOOT.BIN start=0x002af6ec end=0x002af8f4 symbol=FUN_002af6ec lang=c++ */
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
        FUN_000649c0(this);
        *(char **)this = DAT_003070bc;
        FUN_0008c230(pad + 16);
        FUN_0008c230(pad + 32);
    }
};

extern "C" void FUN_002af6ec(Data *param_1)
{
    Res *obj = new Res();
    FUN_000651b8(obj, DAT_00302de4, 0, 1, &DAT_00302e08);

    int i = 0;
    Elem1 *cursor = param_1->elems;
    for (; i < 30; ++i) {
        switch (FUN_00065554(obj, i + 1, DAT_00302e0c)) {
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

        cursor->f4 = FUN_000655f8(obj, i + 1, DAT_00302e14);
        float f = FUN_000655f8(obj, i + 1, &DAT_00302e1c);
        cursor->hi = (int)f;
        cursor++;
    }

    if (obj) {
        delete (Base *)obj;
    }

    for (int j = 0; j < 30; ++j) {
        Vec5 vec;
        FUN_002afaf8(&vec, j);
        param_1->vecs[j].v[0] = vec.v[0];
        param_1->vecs[j].v[1] = vec.v[1];
        param_1->vecs[j].v[2] = vec.v[2];
        param_1->vecs[j].v[3] = vec.v[3];
        param_1->vecs[j].v[4] = vec.v[4];
    }
}

/* HSTMATCH module=EBOOT.BIN start=0x0015c078 end=0x0015c1a0 symbol=FUN_0015c078 lang=c++ data=0x002de3a4 */
/* Clone of src/eboot/menu_load_advice_0015b958.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002de3a4-0x002de3e4) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Menu "load message advice" setup: format two resource paths into the object's path buffer, and when no
   model is loaded yet (or the resource check 0x14934 says so) replace the model: virtual delete, new 0x48-byte
   object (ctor 0x50fc0), load from path, set a 3000.0 parameter, register, reset a 4-float block. Names provisional. */
struct Model_00050fc0 {
    virtual ~Model_00050fc0();
};
struct Self_0015c078;
extern "C" {
extern char DAT_0030ebf4[];
void FUN_0015a4c8(Self_0015c078 *self, int a);
void FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_0001cad0(void *lock, int a, char *buf);
void FUN_0001cb88(void *lock);
int FUN_00014934(void *res, char *path);
void FUN_000149a8(void *res, char *path);
Model_00050fc0 *FUN_00050fc0(void *mem);
void FUN_000511c4(Model_00050fc0 *m, char *path, int a);
void FUN_00051398(Model_00050fc0 *m, float f);
}
void *operator new(unsigned int size);

struct Self_0015c078 {
    char pad0[0x38];
    Model_00050fc0 *model;
    char pad1[0x50 - 0x3c];
    float v[4];
    char pad2[0x170 - 0x60];
    char res[0x200];
    char path[0x100];
};

extern "C" void FUN_0015c078(Self_0015c078 *self, int idx)
{
    FUN_0015a4c8(self, 0);
    FUN_000143b0(self->path, "menu/loadmes/player/loadmes_p%02d.xb", idx);
    FUN_0001cad0(DAT_0030ebf4, 1, self->path);
    FUN_000143b0(self->path, "data/menu/loadmes/P%02d", idx);
    if (self->model == 0 || FUN_00014934(self->res, self->path)) {
        if (self->model) {
            delete self->model;
            self->model = 0;
        }
        Model_00050fc0 *mem = (Model_00050fc0 *)operator new(0x48);
        if (mem)
            mem = FUN_00050fc0(mem);
        self->model = mem;
        FUN_000511c4(mem, self->path, 0);
        FUN_00051398(self->model, 3000.0f);
        FUN_000149a8(self->res, self->path);
        self->v[0] = 0.0f;
        self->v[1] = 0.0f;
        self->v[2] = 0.0f;
        self->v[3] = 1.0f;
    }
    FUN_0001cb88(DAT_0030ebf4);
}

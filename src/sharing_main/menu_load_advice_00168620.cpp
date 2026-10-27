/* HSTMATCH module=hstp_trans_main.prx start=0x00168620 end=0x00168748 symbol=FUN_00168620 lang=c++ data=0x00385960 */
/* Clone of src/eboot/menu_load_advice_0015b958.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00385960-0x003859a0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Menu "load message advice" setup: format two resource paths into the object's path buffer, and when no
   model is loaded yet (or the resource check 0x14934 says so) replace the model: virtual delete, new 0x48-byte
   object (ctor 0x50fc0), load from path, set a 3000.0 parameter, register, reset a 4-float block. Names provisional. */
struct Model_000518d4 {
    virtual ~Model_000518d4();
};
struct Self_00168620;
extern "C" {
extern char DAT_003b7ebc[];
void FUN_00166aa0(Self_00168620 *self, int a);
void FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_0001c684(void *lock, int a, char *buf);
void FUN_0001c73c(void *lock);
int FUN_00014934(void *res, char *path);
void FUN_000149a8(void *res, char *path);
Model_000518d4 *FUN_000518d4(void *mem);
void FUN_00051ad8(Model_000518d4 *m, char *path, int a);
void FUN_00051d38(Model_000518d4 *m, float f);
}
void *operator new(unsigned int size);

struct Self_00168620 {
    char pad0[0x38];
    Model_000518d4 *model;
    char pad1[0x50 - 0x3c];
    float v[4];
    char pad2[0x170 - 0x60];
    char res[0x200];
    char path[0x100];
};

extern "C" void FUN_00168620(Self_00168620 *self, int idx)
{
    FUN_00166aa0(self, 0);
    FUN_000143b0(self->path, "menu/loadmes/player/loadmes_p%02d.xb", idx);
    FUN_0001c684(DAT_003b7ebc, 1, self->path);
    FUN_000143b0(self->path, "data/menu/loadmes/P%02d", idx);
    if (self->model == 0 || FUN_00014934(self->res, self->path)) {
        if (self->model) {
            delete self->model;
            self->model = 0;
        }
        Model_000518d4 *mem = (Model_000518d4 *)operator new(0x48);
        if (mem)
            mem = FUN_000518d4(mem);
        self->model = mem;
        FUN_00051ad8(mem, self->path, 0);
        FUN_00051d38(self->model, 3000.0f);
        FUN_000149a8(self->res, self->path);
        self->v[0] = 0.0f;
        self->v[1] = 0.0f;
        self->v[2] = 0.0f;
        self->v[3] = 1.0f;
    }
    FUN_0001c73c(DAT_003b7ebc);
}

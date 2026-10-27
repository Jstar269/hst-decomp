/* HSTMATCH module=EBOOT.BIN start=0x00062468 end=0x000626bc symbol=FUN_00062468 lang=c++ data=0x002d1174 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (6 strings, 0x002d1174-0x002d11b5) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Snd {
    void *data;
    int handle;
    unsigned char ext;
    char pad9[0x10 - 9];
    void *extData;
};

extern "C" {
void FUN_000626bc(Snd *);
void FUN_00062740(Snd *);
void *FUN_0004cad0(const char *, int *, int, int);
char *FUN_00014d64(const char *, const char *);
char *FUN_000149a8(char *, const char *);
int FUN_000143b0(char *, const char *, ...);
int FUN_00072590(int, void *);
int FUN_000725e0(int, const char *, int);
void FUN_000104e0(void *);
void FUN_0007392c(int, int);
}

extern "C" void FUN_00062468(Snd *self, const char *name, int raw)
{
    FUN_000626bc(self);
    int size = 0;
    void *p = FUN_0004cad0(name, &size, 16, 1);
    if (p == 0)
        return;
    self->data = p;
    FUN_00062740(self);
    if (FUN_00014d64(name, ".sgh")) {
        if (self->handle < 0)
            return;
        char buf[256];
        if (raw) {
            FUN_000149a8(buf, name);
        } else {
            FUN_000143b0(buf, "disc0:/PSP_GAME/USRDIR/%s", name);
            for (char *c = FUN_00014d64(buf, name); *c; c++) {
                if (*c >= 'A' && *c <= 'Z')
                    *c += 32;
            }
        }
        char *e = FUN_00014d64(buf, ".sgh");
        e[3] = 'b';
        if (raw) {
            size = 0;
            self->extData = FUN_0004cad0(buf, &size, 16, 1);
            if (self->extData) {
                if (FUN_00072590(self->handle, self->extData)) {
                    self->ext = 1;
                } else if (self->extData) {
                    FUN_000104e0(self->extData);
                    self->extData = 0;
                }
            }
        } else {
            if (FUN_000725e0(self->handle, buf, 0))
                self->ext = 1;
        }
        if (FUN_00014d64(name, "env_"))
            FUN_0007392c(self->handle, 9);
        else
            FUN_0007392c(self->handle, 3);
    } else {
        if (self->handle < 0)
            return;
        if (FUN_00014d64(name, "bgm_"))
            FUN_0007392c(self->handle, 3);
        else if (FUN_00014d64(name, "jingle"))
            FUN_0007392c(self->handle, 4);
        else if (FUN_00014d64(name, "sys_"))
            FUN_0007392c(self->handle, 1);
    }
}

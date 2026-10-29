/* HSTMATCH module=EBOOT.BIN start=0x0015b958 end=0x0015ba80 symbol=FUN_0015b958 lang=c++ data=0x002de25c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002de25c-0x002de29c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Menu "load message advice" setup: format two resource paths into the object's path buffer, and when no
   model is loaded yet (or the resource check 0x14934 says so) replace the model: virtual delete, new 0x48-byte
   object (ctor 0x50fc0), load from path, set a 3000.0 parameter, register, reset a 4-float block. Names provisional. */

#include "hst/loadmes_obj.h"

extern "C" {
extern char DAT_0030ebf4[];
void FUN_0015a4c8(LoadMesObj *self, int a);
void FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_0001cad0(void *lock, int a, char *buf);
void FUN_0001cb88(void *lock);
int FUN_00014934(void *res, char *path);
void FUN_000149a8(void *res, char *path);
LoadMesRes *FUN_00050fc0(void *mem);
void FUN_000511c4(LoadMesRes *m, char *path, int a);
void FUN_00051398(float f, LoadMesRes *m);
}
void *operator new(unsigned int size);

/* Size of one resource object. */
#define LOADMES_RES_SIZE 0x48

/* Loads advice message idx: formats the two resource paths and replaces the message resource when needed. */
extern "C" void FUN_0015b958(LoadMesObj *self, int idx)
{
    FUN_0015a4c8(self, 0);
    FUN_000143b0(self->nameBuf, "menu/loadmes/advice/loadmes_a%02d.xb", idx);
    FUN_0001cad0(DAT_0030ebf4, 1, self->nameBuf);
    FUN_000143b0(self->nameBuf, "data/menu/loadmes/A%02d", idx);
    if (self->message == 0 || FUN_00014934(self->msgCache, self->nameBuf)) {
        if (self->message) {
            delete self->message;
            self->message = 0;
        }
        LoadMesRes *mem = (LoadMesRes *)operator new(LOADMES_RES_SIZE);
        if (mem)
            mem = FUN_00050fc0(mem);
        self->message = mem;
        FUN_000511c4(mem, self->nameBuf, 0);
        FUN_00051398(3000.0f, self->message);
        FUN_000149a8(self->msgCache, self->nameBuf);
        self->msgParam.x = 0.0f;
        self->msgParam.y = 0.0f;
        self->msgParam.z = 0.0f;
        self->msgParam.w = 1.0f;
    }
    FUN_0001cb88(DAT_0030ebf4);
}

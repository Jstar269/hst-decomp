/* HSTMATCH module=EBOOT.BIN start=0x00293564 end=0x0029365c symbol=FUN_00293564 lang=c++ data=0x002ffb90 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002ffb90-0x002ffbcc) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/komono_obj.h"

/* Virtual view of the model holder: slot 1 attaches a stream. */
struct ModelHolderVirt {
    virtual void s0();
    virtual void SetStream(I3rStream *);
};

extern "C" {
void *FUN_00000bcc(unsigned);
void FUN_000143b0(char *, const char *, const char *, const char *);
I3rStream *FUN_00053670(void *, char *, const char *, int, int, int, int);
void FUN_00053718(I3rStream *, int);
ModelHolder *FUN_00056b98(void *);
void FUN_0005743c(ModelHolder *, int, void *, int);
}

/* Loads the komono model stream named `name`, then builds the render sub-object and attaches the stream. */
extern "C" void FUN_00293564(KomonoObj *obj, const char *name)
{
    char path[256];
    FUN_000143b0(path, "data/lobby/komono/%s/%s.i3r", name, name);
    I3rStream *stream = (I3rStream *)FUN_00000bcc(I3R_STREAM_SIZE);
    if (stream) stream = FUN_00053670(stream, path, "data/lobby/komono/sourceimages/", 0, 0, 0, 0);
    obj->stream = stream;
    if (stream->unk8 == 0 && stream != 0) {
        FUN_00053718(stream, 1);
        obj->stream = 0;
    }
    ModelHolder *sub = (ModelHolder *)FUN_00000bcc(MODEL_HOLDER_SIZE);
    if (sub) sub = FUN_00056b98(sub);
    obj->sub = sub;
    if (obj->stream != 0) {
        ((ModelHolderVirt *)obj->sub)->SetStream(obj->stream);
        if (obj->unk74 != 0) {
            FUN_0005743c(obj->sub, 0, obj->unk74, 0);
        }
    }
}

/* HSTMATCH module=EBOOT.BIN start=0x00266818 end=0x0026694c symbol=FUN_00266818 lang=c++ */
/* Clone of src/sharing_main/model_loop_repeat_00277794.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* When the model's animation has ended (IsEnd: the same track scan as the particle emitter 0x6a894) and the repeat
   count at +0x1f8 is positive, decrement it, rewind the model (frame 0 on every track, time 0) and step it once,
   then do the same for the optional second model at +0x74. Names provisional. */
struct MotionData { char pad0[8]; float length; };
struct Motion { MotionData *data; };
struct Track {
    Motion *motion;
    char pad4[0x10 - 0x4];
    float frame;
    char pad14[0x34 - 0x14];
    float Length() const { return motion ? motion->data->length : 0.0f; }
};

struct Model {
    char pad0[0xf4];
    Track tracks[1];
    char pad128[0x158 - 0x128];
    int firstTrack;
    int lastTrack;
    int LastTrack() const { return lastTrack; }
    bool IsEnd()
    {
        for (int i = firstTrack; i <= LastTrack(); i++) {
            if (tracks[i].frame < tracks[i].Length())
                return false;
        }
        return true;
    }
};

extern "C" {
void FUN_00058f38(Model *, float, int);
void FUN_0005f110(Model *, float);
void FUN_00059174(Model *);
void FUN_0005f0d8(Model *);
}

static inline void Rewind(Model *m)
{
    FUN_00058f38(m, 0.0f, -1);
    FUN_0005f110(m, 0.0f);
}

static inline void Step(Model *m)
{
    FUN_00059174(m);
    FUN_0005f0d8(m);
}

struct Self {
    char pad0[0x70];
    Model *model;
    Model *model2;
    char pad78[0x1f8 - 0x78];
    int count;
};

extern "C" void FUN_00266818(Self *self)
{
    if (self->model != 0 && self->model->IsEnd() && self->count > 0) {
        self->count--;
        Rewind(self->model);
        Step(self->model);
        if (self->model2 != 0) {
            Rewind(self->model2);
            Step(self->model2);
        }
    }
}

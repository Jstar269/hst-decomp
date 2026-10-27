/* HSTMATCH module=hstp_trans_main.prx start=0x00277794 end=0x002778c8 symbol=FUN_00277794 lang=c++ */
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
void FUN_00059c1c(Model *, float, int);
void FUN_0005ff00(Model *, float);
void FUN_00059e58(Model *);
void FUN_0005fec8(Model *);
}

static inline void Rewind(Model *m)
{
    FUN_00059c1c(m, 0.0f, -1);
    FUN_0005ff00(m, 0.0f);
}

static inline void Step(Model *m)
{
    FUN_00059e58(m);
    FUN_0005fec8(m);
}

struct Self {
    char pad0[0x70];
    Model *model;
    Model *model2;
    char pad78[0x1f8 - 0x78];
    int count;
};

extern "C" void FUN_00277794(Self *self)
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

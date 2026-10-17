/* HSTMATCH module=EBOOT.BIN start=0x0016781c end=0x0016787c symbol=FUN_0016781c */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Quat;
typedef struct { Quat q[4]; int extra[6]; } QuatSet;

void FUN_0016781c(QuatSet *s)
{
    s->q[0].x = 0.0f; s->q[0].y = 0.0f; s->q[0].z = 0.0f; s->q[0].w = 1.0f;
    s->q[1].x = 0.0f; s->q[1].y = 0.0f; s->q[1].z = 0.0f; s->q[1].w = 1.0f;
    s->q[2].x = 0.0f; s->q[2].y = 0.0f; s->q[2].z = 0.0f; s->q[2].w = 1.0f;
    s->q[3].x = 0.0f; s->q[3].y = 0.0f; s->q[3].z = 0.0f; s->q[3].w = 1.0f;
    s->extra[0] = 0; s->extra[1] = 0; s->extra[2] = 0;
    s->extra[3] = 0; s->extra[4] = 0; s->extra[5] = 0;
}

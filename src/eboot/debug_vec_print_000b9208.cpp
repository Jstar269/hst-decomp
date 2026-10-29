/* HSTMATCH module=EBOOT.BIN start=0x000b9208 end=0x000b939c symbol=FUN_000b9208 lang=c++ data=0x002d49dc */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x002d49dc-0x002d4a3f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct CamGlobals { char pad[0x1d0]; Vec4 pos; };
/* Debug camera state: the same object as the debug camera update source. */
struct DebugCam {
    char pad0[0xc8];
    int mode;
    char pad1[0xf0 - 0xcc];
    float fov;
    int preset;
    int obj;
};

enum { CAM_OFF = 0, CAM_FREE = 1 };

extern CamGlobals *DAT_003313c4;
extern int DAT_00340284;
extern char DAT_0030fc10[];

extern "C" {
void FUN_00047d58(...);
float sqrtf(float);
void FUN_0015f8f4(int);
void FUN_00131198(Vec4 *, int, int, int);
float FUN_0016a93c(Vec4 *, Vec4 *);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_00131db8(int, int);

/* Draw the debug camera readout: direction, distance and height to the selected preset, fov and its name. */
void FUN_000b9208(DebugCam *cam)
{
    if (cam->mode > CAM_OFF) {
        if (cam->mode == CAM_FREE) {
            FUN_0015f8f4(cam->obj);
        } else {
            Vec4 presetPos;
            FUN_00131198(&presetPos, DAT_00340284, cam->preset, -1);
            Vec4 camPos;
            camPos.x = DAT_003313c4->pos.x;
            camPos.y = DAT_003313c4->pos.y;
            camPos.z = DAT_003313c4->pos.z;
            camPos.w = DAT_003313c4->pos.w;
            Vec4 delta;
            float direction; float height; float dist;
            direction = 360.0f - FUN_0016a93c(&presetPos, &camPos);
            FUN_00022434(&delta, &presetPos, &camPos);
            dist = sqrtf(delta.x * delta.x + delta.z * delta.z);
            height = presetPos.y - camPos.y;
            FUN_00047d58(DAT_0030fc10, "Direction: %6.1f", (double)direction);
            FUN_00047d58(DAT_0030fc10, "Dist:      %6.1f", (double)dist);
            FUN_00047d58(DAT_0030fc10, "Height:    %6.1f", (double)height);
            FUN_00047d58(DAT_0030fc10, "FOV:       %6.1f", (double)cam->fov);
            FUN_00047d58(DAT_0030fc10, "CamBasePoint:   %s", FUN_00131db8(DAT_00340284, cam->preset));
        }
    }
}
}

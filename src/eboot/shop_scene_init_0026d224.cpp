/* HSTMATCH module=EBOOT.BIN start=0x0026d224 end=0x0026d5fc symbol=FUN_0026d224 lang=c++ */
/* Shop scene init: reads chrsel_param_scroll.csv by row position, loads face_dummy.i3r; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/shop_scene.h"
#include "hst/table_reader.h"

struct Vec4 { float x, y, z, w; };

/* Model object with a virtual Load (path, then five arguments). */
struct ShopModel {
    virtual void m0();
    virtual void m1();
    virtual void Load(const char *, int, int, int, int, int);
};

extern "C" char DAT_0030ab9c;
extern "C" char DAT_0030ebf4;
extern "C" char DAT_002fe138[];
extern "C" char DAT_002fe148[];
extern "C" char DAT_002fe168[];
extern "C" char DAT_002fe190[];
extern "C" char DAT_002fe1bc[];
extern "C" char DAT_002fe1dc[];
extern "C" char DAT_002fe208[];
extern "C" char DAT_0034179c;
extern "C" int DAT_003313c4;
extern "C" int DAT_003386c8;

extern "C" {
void *FUN_00010184(int, int);
void FUN_0001bfb4(void *, void *, int);
void FUN_0001cad0(void *, int, void *);
void FUN_00104118(void *, void *, int);
void *FUN_00000bcc(int);
void *FUN_00102e38(void *);
void *FUN_00056b98(void *);
void FUN_001b2e78(void *);
void FUN_001037c8(void *, int);
void FUN_00103540(void *, float);
void *FUN_002226b4(void *, int);
void FUN_002230dc(void *, float, float);
void *FUN_0021d7c4(void *);
void FUN_000649c0(TableReader *);
void FUN_00064bf4(TableReader *, void *, int, void *);
int FUN_00065104(TableReader *, int, int);
void FUN_0001cb88(void *);
int FUN_0001cbfc();
int FUN_0001cc54();
void FUN_000104e0(void *);
void FUN_00293c6c(void *);
void FUN_001b3ce8(void *, int);
void FUN_0005ba78(void *, int);
float FUN_0000c000(float);
void FUN_0005bbd4(void *, float, float, float, float, float, float);
void FUN_0005c76c(void *, float, float, float, float);
void FUN_0005c854(void *, int, Vec4 *, Vec4 *);
void FUN_0005bc58(void *);
void *FUN_0008d994(int);
void FUN_00064a08(TableReader *, int);

/* Builds the shop scene: layout widgets, the model, the camera and the scroll parameters read from the table. */
int FUN_0026d224(ShopScene *scene)
{
    void *buf = FUN_00010184(0x40, 0x280000);
    FUN_0001bfb4(&DAT_0030ab9c, buf, 0x280000);
    FUN_0001cad0(&DAT_0030ebf4, 1, DAT_002fe138);
    FUN_00104118(scene->pane, DAT_002fe148, 0);
    void *p = FUN_00000bcc(SHOP_PANE_SIZE);
    if (p != 0) {
        p = FUN_00102e38(p);
    }
    scene->widget_fc = (ShopWidget *)p;
    FUN_00104118(p, DAT_002fe168, 0);
    void *q = FUN_00000bcc(0x1b0);
    ShopModel *model;
    if (q != 0) {
        model = (ShopModel *)FUN_00056b98(q);
        scene->model = model;
    } else {
        scene->model = (ShopModel *)q;
        model = (ShopModel *)q;
    }
    model->Load(DAT_002fe190, 0, 0, 0, 0, 0);
    FUN_001b2e78(&DAT_0034179c);
    p = FUN_00000bcc(SHOP_PANE_SIZE);
    if (p != 0) {
        p = FUN_00102e38(p);
    }
    scene->widget_100 = (ShopWidget *)p;
    FUN_00104118(p, DAT_002fe1bc, 0);
    FUN_001037c8(scene->widget_100, -2);
    FUN_00103540(scene->widget_100, 2000.0f);
    void *r = FUN_00000bcc(0xcc);
    void *rm;
    if (r != 0) {
        rm = FUN_002226b4(r, 1);
        scene->widget_a0c = (ShopWidget *)rm;
    } else {
        scene->widget_a0c = (ShopWidget *)r;
        rm = r;
    }
    FUN_001037c8(rm, -1);
    FUN_002230dc(scene->widget_a0c, 110.0f, 50.0f);
    void *s = FUN_00000bcc(0x210);
    void *sm;
    if (s != 0) {
        sm = FUN_0021d7c4(s);
        scene->widget_a3c = (ShopWidget *)sm;
    } else {
        scene->widget_a3c = (ShopWidget *)s;
        sm = s;
    }
    FUN_001037c8(sm, -1);
    TableReader table;
    FUN_000649c0(&table);
    FUN_00064bf4(&table, DAT_002fe1dc, 0, DAT_002fe208);
    scene->scroll_params[0] = FUN_00065104(&table, 0, 1);
    scene->scroll_params[1] = FUN_00065104(&table, 1, 1);
    scene->scroll_params[2] = FUN_00065104(&table, 2, 1);
    FUN_0001cb88(&DAT_0030ebf4);
    int base = FUN_0001cbfc();
    int size = FUN_0001cc54();
    FUN_0001bfb4(&DAT_0030ab9c, (void *)base, size);
    if (buf != 0) {
        FUN_000104e0(buf);
    }
    FUN_00293c6c(scene->sub920);
    FUN_001b3ce8(&DAT_0034179c, 8);
    FUN_00103540(scene->pane, 2000.0f);
    FUN_001037c8(scene->pane, 4);
    FUN_0005ba78(&scene->camera, DAT_003313c4);
    scene->camera.vec1d0[0] = 0.0f;
    scene->camera.vec1d0[1] = -1.0f;
    scene->camera.vec1d0[2] = 5.0f;
    scene->camera.vec1d0[3] = 1.0f;
    scene->camera.vec1e0[0] = 0.0f;
    scene->camera.vec1e0[1] = 0.2f;
    scene->camera.vec1e0[2] = -1.0f;
    scene->camera.vec1e0[3] = 1.0f;
    scene->camera.fov = 45.0f;
    scene->camera.tan_half_fov = FUN_0000c000(scene->camera.fov * 0.008726646f);
    scene->camera.near_z = 0.1f;
    scene->camera.far_z = 1000.0f;
    FUN_0005bbd4(&scene->camera, 0.0f, 0.0f, 480.0f, 272.0f, 240.0f, 136.0f);
    FUN_0005c76c(&scene->camera, 1.0f, 1.0f, 1.0f, 1.0f);
    Vec4 vec_a;
    Vec4 vec_b;
    vec_a.z = -1.0f;
    vec_a.w = 1.0f;
    vec_b.x = 1.0f;
    vec_b.y = 1.0f;
    vec_b.z = 1.0f;
    vec_b.w = 1.0f;
    vec_a.x = 0.0f;
    vec_a.y = 0.0f;
    FUN_0005c854(&scene->camera, 0, &vec_a, &vec_b);
    FUN_0005bc58(&scene->camera);
    void *widget = FUN_0008d994(DAT_003386c8);
    if (widget != 0) {
        FUN_00103540(widget, 2100.0f);
    }
    FUN_00064a08(&table, -1);
    return 1;
}
}

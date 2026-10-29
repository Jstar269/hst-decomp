/* HSTMATCH module=EBOOT.BIN start=0x001e1084 end=0x001e12dc symbol=FUN_001e1084 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Calls virtual slot 3 on each non-null widget of the screen, including a 21-entry array walked in a loop;
   the mode selects an extra call (case 0: the object at unk40 and the overall layout, case 1: a helper on a field of the host object);
   a helper then runs on the host object and a final call is made last. Names provisional. */
enum { SLOT3_WIDGET_COUNT = 21 };

struct Widget {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
};
struct Host {
    char pad[0x8c];
    void *unk8c;
};
struct ResultScreen {
    char pad[0x3c];
    Host *host;
    Widget *unk40;
    int mode;
    char pad48[0xd4 - 0x48];
    Widget *overall_layout;
    char padd8[0x1f4 - 0xd8];
    Widget *unk1f4;
    char pad1f8[0x810 - 0x1f8];
    Widget *phase_layout;
    char pad814[0x9b4 - 0x814];
    Widget *status_layout;
    char pad9b8[0x175c - 0x9b8];
    Widget *rank_layout;
    char pad1760[0x1954 - 0x1760];
    Widget *unk1954;
    Widget *unk1958;
    char pad195c[0x1adc - 0x195c];
    Widget *widgets[SLOT3_WIDGET_COUNT];
    char pad1b30[0x1d64 - 0x1b30];
    Widget *unk1d64;
    Widget *members_layout;
    char pad1d6c[0x21e4 - 0x1d6c];
    Widget *unk21e4;
    char pad21e8[0x235c - 0x21e8];
    Widget *unk235c;
    char pad2360[0x2464 - 0x2360];
    Widget *unk2464;
    char pad2468[0x250c - 0x2468];
    Widget *unk250c;
    char pad2510[0x25b8 - 0x2510];
    Widget *unk25b8;
};
extern int DAT_00310fc4;
extern "C" {
void FUN_001eab70(void *);
void FUN_001031e8(void *);
void FUN_00042ff4(float, int);
}

extern "C" void FUN_001e1084(ResultScreen *screen)
{
    if (screen->unk250c)
        screen->unk250c->s3();
    switch (screen->mode) {
    case 0:
        screen->unk40->s3();
        if (screen->overall_layout)
            screen->overall_layout->s3();
        break;
    case 1:
        FUN_001eab70(screen->host->unk8c);
        break;
    }
    if (screen->host)
        FUN_001031e8(screen->host);
    if (screen->unk1f4)
        screen->unk1f4->s3();
    if (screen->status_layout)
        screen->status_layout->s3();
    if (screen->phase_layout)
        screen->phase_layout->s3();
    if (screen->rank_layout)
        screen->rank_layout->s3();
    if (screen->unk1954)
        screen->unk1954->s3();
    if (screen->members_layout)
        screen->members_layout->s3();
    if (screen->unk21e4)
        screen->unk21e4->s3();
    if (screen->unk235c)
        screen->unk235c->s3();
    if (screen->unk2464)
        screen->unk2464->s3();
    if (screen->unk25b8)
        screen->unk25b8->s3();
    for (int i = 0; i < SLOT3_WIDGET_COUNT; i++) {
        if (screen->widgets[i])
            screen->widgets[i]->s3();
    }
    if (screen->unk1958)
        screen->unk1958->s3();
    if (screen->unk1d64)
        screen->unk1d64->s3();
    FUN_00042ff4(100000.0f, DAT_00310fc4);
}

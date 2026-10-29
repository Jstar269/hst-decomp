/* Text context object: the button layout lookups and the queue of icons to draw. */
#ifndef HST_TEXT_CTX_H
#define HST_TEXT_CTX_H

enum { TEXT_BUTTON_COUNT = 30, TEXT_ICON_MAX = 10 };

struct TextLayoutObj;

typedef struct TextIcon {
    int id;
    int x;
    int y;
    float w;
    float h;
} TextIcon;

typedef struct TextCtx {
    struct TextLayoutObj *obj;        /* 0x00 */
    int btn_ref[TEXT_BUTTON_COUNT];   /* 0x04 */
    int btn_data[TEXT_BUTTON_COUNT];  /* 0x7c */
    TextIcon icons[TEXT_ICON_MAX];    /* 0xf4 */
    int icon_count;                   /* 0x1bc */
#ifdef __cplusplus
    /* Queue an icon for drawing; ignored when the queue is full. */
    void Add(int id, int x, int y, float w, float h)
    {
        if (icon_count < TEXT_ICON_MAX) {
            TextIcon *ic = &icons[icon_count];
            ic->id = id;
            ic->x = x;
            ic->y = y;
            ic->w = w;
            ic->h = h;
            icon_count++;
        }
    }
#endif
} TextCtx;

#endif

/* HSTMATCH module=EBOOT.BIN start=0x00197208 end=0x001972d0 symbol=FUN_00197208 lang=c++ data=0x002e1608 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string-pointer tables (1 tables, 30 strings, 0x002e1608-0x002e17a8) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
#include "hst/text_ctx.h"

struct TextLayoutObj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
};

extern "C" TextCtx *DAT_00341768;
extern "C" char DAT_002e17a8[];
extern "C" char DAT_002e17c8[];
extern "C" char *DAT_002e1730[] = {
    "btn_juji0",
    "btn_juji1",
    "btn_juji2",
    "btn_juji3",
    "btn_juji4",
    "btn_juji5",
    "btn_analog0",
    "btn_analog1",
    "btn_analog2",
    "btn_analog3",
    "btn_analog4",
    "btn_analog5",
    "btn0",
    "btn1",
    "btn2",
    "btn3",
    "btn4",
    "btn5",
    "btn_bg0",
    "btn_bg1",
    "btn_bg2",
    "btn_bg3",
    "btn_bg4",
    "btn_bg5",
    "btn_bg6",
    "btn_bg7",
    "btn_bg8",
    "btn_bg9",
    "btn_bg10",
    "btn_bg11",
};
extern "C" void FUN_00104118(void *, void *, int);
extern "C" TextLayoutObj *FUN_001039d8(void *, void *, int);
extern "C" void *FUN_001026b8(TextLayoutObj *, void *);

/* Load the button layout and record each named button's lookup result and its stored word. */
extern "C" void FUN_00197208(void)
{
    TextCtx *ctx;
    TextLayoutObj *group;
    int i;
    char **name;
    int *slot; /* walks the context words: btn_ref at +1, btn_data at +31 */

    ctx = DAT_00341768;
    if (ctx != 0) {
        FUN_00104118(ctx->obj, DAT_002e17a8, 0);
        group = FUN_001039d8(ctx->obj, DAT_002e17c8, 0);
        i = 0;
        name = DAT_002e1730;
        slot = (int *)ctx;
        do {
            int *ref = (int *)FUN_001026b8(group, *name);
            slot[1] = (int)ref;
            i++;
            name++;
            slot[31] = ref[9];
            slot++;
        } while (i < TEXT_BUTTON_COUNT);
        ctx->obj->m2();
    }
}

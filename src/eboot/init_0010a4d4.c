/* HSTMATCH module=EBOOT.BIN start=0x0010a4d4 end=0x0010a5b0 symbol=FUN_0010a4d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the function returns int (the stripped print call is declared int and its result is stored back into the checked value, which is returned: `if (r) r = print(fmt, r); return r;`), which keeps r in v0 and gives retail beqzl/move a1,v0 shape; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/utility_params.h"

enum {
  MSGBOX_STYLE_YESNO = 1,  /* yes/no buttons, cancel disabled */
  MSGBOX_STYLE_OK = 2      /* single button, cancel disabled */
};

extern char DAT_002d8dd0[];
extern u32 * FUN_000114c0();
extern char * FUN_00014b74();
extern int FUN_0010a4a8(const char *, ...);
extern void FUN_00199280();
extern int FUN_002b7c20();

/* Start a message dialog that shows the given text; logs the start-up result when it fails. */
int FUN_0010a4d4(MsgDialogParams *params,u32 text,int style)
{
  int result;
  
  FUN_000114c0(params,0,sizeof(MsgDialogParams));
  params->base.size = sizeof(MsgDialogParams);
  params->base.language = 0;
  params->base.buttonSwap = 0;
  params->base.graphicsThread = UTILITY_PRIO_GRAPHICS;
  params->base.accessThread = UTILITY_PRIO_ACCESS;
  params->base.fontThread = UTILITY_PRIO_FONT;
  params->base.soundThread = UTILITY_PRIO_SOUND;
  FUN_00199280(params);
  params->mode = MSGDIALOG_MODE_TEXT;
  if (style == MSGBOX_STYLE_YESNO) {
    params->options = MSGDIALOG_OPTION_YESNO | MSGDIALOG_OPTION_NO_CANCEL;
  }
  else if (style == MSGBOX_STYLE_OK) {
    params->options = MSGDIALOG_OPTION_NO_CANCEL;
  }
  FUN_00014b74(params->message,text,sizeof(params->message) - 1);
  params->message[sizeof(params->message) - 1] = 0;
  result = FUN_002b7c20(params);
  if (result != 0) {
    result = FUN_0010a4a8(DAT_002d8dd0,result);
  }
  return result;
}

/* HSTMATCH module=EBOOT.BIN start=0x00198278 end=0x001982d8 symbol=FUN_00198278 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/text_draw.h"

#define TOKEN_BUF_SIZE 1024 /* bytes of the token copy */

extern void FUN_00197834(TextDraw *self,const char *text,int measure,int draw,int p5,char *out);
extern void FUN_00198098(TextDraw *self,const char *src,char *dst);

/* Copies the string token by token into a local buffer, then runs the string layout on the copy with measure and draw both off.
   Returns out unchanged. */
char * FUN_00198278(TextDraw *self,const char *text,int p5,char *out)
{
  char token_buf [TOKEN_BUF_SIZE];
  
  FUN_00198098(self,text,token_buf);
  FUN_00197834(self,token_buf,0,0,p5,out);
  return out;
}

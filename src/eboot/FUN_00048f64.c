/* HSTMATCH module=EBOOT.BIN start=0x00048f64 end=0x00048fc8 symbol=FUN_00048f64 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_0002c52c(int a, int *b); extern int DAT_002d0734; extern int FUN_002b7910(int h, int n); extern void (*DAT_00311144)(int v); extern int FUN_002b79b0(int a);
int FUN_00048f64(int a, int *b) { int v; FUN_0002c52c(a, b); v = *b; FUN_002b7910(DAT_002d0734, 1); DAT_00311144(v); FUN_002b7910(DAT_002d0734, 1); FUN_002b79b0(0); return 0; }

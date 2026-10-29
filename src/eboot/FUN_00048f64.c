/* HSTMATCH module=EBOOT.BIN start=0x00048f64 end=0x00048fc8 symbol=FUN_00048f64 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_0002c52c(int a, int *b);
extern int DAT_002d0734;      /* semaphore handle */
extern int FUN_002b7910(int h, int n);
extern void (*DAT_00311144)(int v);
extern int FUN_002b79b0(int a);

/* Thread body: reads the start argument, calls the registered callback with it and signals the semaphore around the call. */
int FUN_00048f64(int arg_size, int *argp)
{
  int value;

  FUN_0002c52c(arg_size, argp);
  value = *argp;
  FUN_002b7910(DAT_002d0734, 1);
  DAT_00311144(value);
  FUN_002b7910(DAT_002d0734, 1);
  FUN_002b79b0(0);
  return 0;
}

/* HSTMATCH module=hstp_trans_main.prx start=0x000006e8 end=0x00000788 symbol=FUN_000006e8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned int size_t;

extern void FUN_000009e4(void *);

void FUN_000006e8(char *param_1, void *param_2)
{
  if (param_1 != 0) {
    if (param_2 != 0) {
      void (*dtor)(void *, int) = *(void (**)(void *, int))(param_1 - 8);
      size_t elem_size = *(size_t *)(param_1 - 16);
      size_t count = *(size_t *)(param_1 - 12);
      size_t i = 0;
      char *elem = param_1 + elem_size * count;
      for (; i < count; i++) {
        elem -= elem_size;
        (*dtor)(elem, -1);
      }
    }
    FUN_000009e4(param_1 - 16);
  }
}

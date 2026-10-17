/* HSTMATCH module=hstp_trans_main.prx start=0x0010dae4 end=0x0010dbcc symbol=FUN_0010dae4 lang=c99 */
/* Clone of src/eboot/FUN_00107d24.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { int *data; int size; } Buffer;
extern void FUN_00000a00(void *);
extern void FUN_000111c0(void *, const void *, int);

int *FUN_0010dae4(Buffer *buffer, int *insert, int count, int position)
{
  if (insert != 0) {
    char *data = (char *)buffer->data;
    int bytes = count * 4;
    int copyBytes = (bytes / 4) * 4;
    FUN_000111c0(data, insert, copyBytes);
    FUN_000111c0(data + copyBytes + position * 4,
                 (char *)insert + bytes,
                 ((((int)((char *)insert + buffer->size * 4) -
                    (int)((char *)insert + bytes)) / 4) * 4));
    FUN_00000a00(insert);
  }
  buffer->size += position;
  return (int *)((char *)buffer->data + count * 4);
}

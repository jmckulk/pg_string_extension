#include "postgres.h"
#include <string.h>
#include "fmgr.h"
#include "utils/geo_decls.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(echo_text);

Datum
echo_text(PG_FUNCTION_ARGS){
  text *t = PG_GETARG_TEXT_PP(0);
  text *new_t = (text *) palloc(VARSIZE_ANY_EXHDR(t) + VARHDRSZ);
  SET_VARSIZE(new_t, VARSIZE_ANY_EXHDR(t) + VARHDRSZ);
  memcpy( (void *) VARDATA(new_t),
          (void *) VARDATA_ANY(t),
          VARSIZE_ANY_EXHDR(t));
  PG_RETURN_TEXT_P(new_t);
}


PG_FUNCTION_INFO_V1(is_palindrome);

Datum
is_palindrome(PG_FUNCTION_ARGS){
  text *t = PG_GETARG_TEXT_PP(0);

  

  PG_RETURN_BOOL(false);
}

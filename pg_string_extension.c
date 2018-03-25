#include "postgres.h"
#include <string.h>
#include "fmgr.h"
#include "utils/geo_decls.h"
#include "utils/builtins.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(echo_text);

int compare(const void*, const void*);
int len_with_no_spaces(const char *s);
int len_with_no_spaces(const char *s){
  const char * sc;
  int count = 0;
  sc = s;

  while(*sc != '\0'){
    if(*sc == ' '){
      count++;
    }
    sc++;
  }

  return sc - s - count;
}

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
  text *word = PG_GETARG_TEXT_PP(0);

  char * c_word = text_to_cstring(word);
  int len = strlen(c_word);

  if(len == 0){
    PG_RETURN_BOOL(false);
  }

  if(len == 1){
    PG_RETURN_BOOL(true);
  }

  int front = 0, back = len - 1;

  while((front < back) && (front != back)){
    if(c_word[front] != c_word[back]){
      PG_RETURN_BOOL(false);
    } else {
      front++;
      back--;
    }
  }

  PG_RETURN_BOOL(true);
}

int compare(const void* a, const void* b){
  char char_a = *((char*) a);
  char char_b = *((char*) b);

  if(char_a == char_b){
    return 0;
  } else if(char_a < char_b){
    return -1;
  } else {
    return 1;
  }
}

PG_FUNCTION_INFO_V1(sort_chars);

Datum
sort_chars(PG_FUNCTION_ARGS){
  text *unsorted = PG_GETARG_TEXT_PP(0);
  char *unsorted_c = text_to_cstring(unsorted);
  int len = strlen(unsorted_c);

  qsort(unsorted_c, len, sizeof(char), compare);

  text *sorted = cstring_to_text(unsorted_c);

  PG_RETURN_TEXT_P(sorted);
}

PG_FUNCTION_INFO_V1(is_anagram);

Datum
is_anagram(PG_FUNCTION_ARGS){
  text *word_a = PG_GETARG_TEXT_PP(0);
  text *word_b = PG_GETARG_TEXT_PP(1);

  char *c_word_a = text_to_cstring(word_a);
  char *c_word_b = text_to_cstring(word_b);

  int len_no_a = len_with_no_spaces(c_word_a);
  int len_no_b = len_with_no_spaces(c_word_b);

  if(len_no_a != len_no_b){
    PG_RETURN_BOOL(false);
  }

  int i, len_a = strlen(c_word_a);

  for(i = 0; i < len_a; i++){
    while(c_word_a[i] == ' '){
      i++;
    }
    char * char_b = strchr(c_word_b, c_word_a[i]);
    if(char_b == NULL){
      PG_RETURN_BOOL(false);
    } else {
      * char_b = '{';
    }
  }

  PG_RETURN_BOOL(true);
}

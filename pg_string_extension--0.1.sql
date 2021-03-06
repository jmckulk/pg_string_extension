-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo USE "CREATE EXTENSION pg_string_extension" to load this file. \quit

CREATE FUNCTION echo_text(text) RETURNS text
 AS '$libdir/pg_string_extension', 'echo_text'
 LANGUAGE C STRICT;

CREATE FUNCTION is_palindrome(text) RETURNS boolean
  AS '$libdir/pg_string_extension', 'is_palindrome'
  LANGUAGE C STRICT;

CREATE FUNCTION sort_chars(text) RETURNS text
  AS '$libdir/pg_string_extension', 'sort_chars'
  LANGUAGE C STRICT;

CREATE FUNCTION is_anagram(text, text) RETURNS boolean
  AS '$libdir/pg_string_extension', 'is_anagram'
  LANGUAGE C STRICT;

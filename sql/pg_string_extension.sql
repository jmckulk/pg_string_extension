CREATE EXTENSION pg_string_extension;
SELECT is_palindrome('');
SELECT is_palindrome('a');
SELECT is_palindrome('aa');
SELECT is_palindrome('aba');
SELECT is_palindrome('helloolleh');
SELECT is_palindrome('world');
SELECT is_palindrome('aaab');
SELECT is_palindrome('helloollehhelloollehhelloollehhelloollehhelloollehhelloollehhelloollehhelloollehhelloollehhelloolleh');

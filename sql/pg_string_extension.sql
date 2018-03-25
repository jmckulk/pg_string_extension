CREATE EXTENSION pg_string_extension;
SELECT is_palindrome('');
SELECT is_palindrome('a');
SELECT is_palindrome('aa');
SELECT is_palindrome('aba');
SELECT is_palindrome('helloolleh');
SELECT is_palindrome('world');
SELECT is_palindrome('aaab');


SELECT is_anagram('hello', 'hello');
SELECT is_anagram('dirty room', 'dormitory');
SELECT is_anagram('dormitory', 'dirty room');
SELECT is_anagram('tar', 'cat');
SELECT is_anagram('tar', 'rat');
SELECT is_anagram('i am lord voldemort', 'tom marvolo riddle');
SELECT is_anagram('bad credit', 'debit card');
SELECT is_anagram('debit card', 'bad credit');
SELECT is_anagram('hello', 'helloabc');
SELECT is_anagram('helloabc', 'hello');
SELECT is_anagram('  hello', 'hello');
SELECT is_anagram('hello', 'hel  lo');


SELECT sort_chars('qwertyuiopasdfghjklzxcvbnm');
SELECT sort_chars('CcBbAa');

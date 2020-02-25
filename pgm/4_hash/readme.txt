--------------------------------------------------------------------------------
Hash tables: 
--------------------------------------------------------------------------------
There are many names for this data structure. 
Different languages has different names for it.
-> Hash maps (ruby)/
-> maps (java) /
-> ordered maps/
-> dictionary(python) /
-> objects (java script).

--------------------------------------------------------------------------------
Hash table: Terminnology
--------------------------------------------------------------------------------
Hashes: Key - value pair
Hash function
Index
Collision

--------------------------------------------------------------------------------
What is Hash function?
--------------------------------------------------------------------------------
Hash function is a function that generates a value of fixed length for each
input that gets. 

Eg: md5 hash, sha-1 hash, sha-256 hash
Facts:
-> it is one way. From hash value we cannot know what input was.
-> For same input it always generate same value.
-> this is why it is called idempotent

--------------------------------------------------------------------------------
Big O:
--------------------------------------------------------------------------------
Insert: O(1)
lookup: O(1), O(n) on Collision
delete: O(1)
search: O(1)

When you have a collision, it slows down reading and writing.
With a hash table O(n/k) where k is the size of your hash table

There are different ways to solve collision. Refer Wikipedia
One way is linked list (separate chaining)
Second is open addressing
Third is Robin hood hashing



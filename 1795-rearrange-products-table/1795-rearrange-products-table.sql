# Write your MySQL query statement below
SELECT product_id, 'store1' AS store, store1 AS price FROM Products WHERE store1 IS NOT NULL
UNION 
SELECT product_id, 'store2' AS store, store2 AS price FROM Products WHERE store2 IS NOT NULL
UNION 
SELECT product_id, 'store3' AS store, store3 AS price FROM Products WHERE store3 IS NOT NULL

ORDER BY 1,2 ASC
# it gets added to every row, because select product_id, store1, 'banana' goes through every row, selects product_id and store1, but then it comes to 'banana' which isnt a column refence just a literal value so it just selects 'banana'. it does this for every row so you see it in every row of the output

# mysql> select product_id, store1 from Products;
# +------------+--------+
# | product_id | store1 |
# +------------+--------+
# |          0 |     95 |
# |          1 |     70 |
# +------------+--------+
# 2 rows in set (0.00 sec)

# mysql> select product_id, store1, 'banana' from Products;
# +------------+--------+--------+
# | product_id | store1 | banana |
# +------------+--------+--------+
# |          0 |     95 | banana |
# |          1 |     70 | banana |
# +------------+--------+--------+
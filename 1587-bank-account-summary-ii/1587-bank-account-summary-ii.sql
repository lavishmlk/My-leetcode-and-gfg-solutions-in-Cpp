# Write your MySQL query statement below
# //having is always used after group by
select name, sum(amount) as balance
# or can also write like this-> select Users.name, sum(amount)  balance
from  Transactions join Users USING (account)
GROUP BY account
having balance>10000






































# SELECT u.name, SUM(amount) as balance
# FROM Transactions
# JOIN Users u
# USING (account)
# GROUP BY account
# HAVING balance>10000
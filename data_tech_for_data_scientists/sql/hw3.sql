--Q1
SELECT DISTINCT cust_id
FROM Orders
WHERE order_num IN (
    SELECT order_num
    FROM OrderItems
    WHERE item_price >= 10);

--Q2
--(a)
SELECT cust_id, order_date
FROM Orders
WHERE order_num IN (
    SELECT order_num
    FROM OrderItems
    WHERE prod_id = 'BR01')
ORDER BY order_date;

--(b)
SELECT Customers.cust_email, Orders.order_date
FROM Customers
JOIN Orders ON Customers.cust_id = Orders.cust_id
JOIN OrderItems ON Orders.order_num = OrderItems.order_num
WHERE OrderItems.prod_id = 'BR01'
ORDER BY Orders.order_date;

--Q3
SELECT Orders.cust_id, 
       (SELECT SUM(OrderItems.item_price * OrderItems.quantity) 
        FROM OrderItems 
        WHERE OrderItems.order_num = Orders.order_num) AS total_ordered
FROM Orders
GROUP BY Orders.cust_id
ORDER BY total_ordered DESC;

--Q4
--(a)
SELECT Customers.cust_name, Orders.order_num
FROM Customers, Orders
WHERE Customers.cust_id = Orders.cust_id
ORDER BY Customers.cust_name, Orders.order_num;

--(b)
SELECT Customers.cust_name, Orders.order_num
FROM Customers
INNER JOIN Orders ON Customers.cust_id = Orders.cust_id
ORDER BY Customers.cust_name, Orders.order_num;

--Q5
--(a)
SELECT Orders.order_date
FROM Orders, OrderItems
WHERE Orders.order_num = OrderItems.order_num
AND OrderItems.prod_id = 'BR01'
ORDER BY Orders.order_date;

--(b)
SELECT Customers.cust_email
FROM Customers
JOIN Orders ON Customers.cust_id = Orders.cust_id
JOIN OrderItems ON Orders.order_num = OrderItems.order_num
WHERE OrderItems.prod_id = 'BR01'
ORDER BY Orders.order_date;

--Q6
SELECT Vendors.vend_id, COUNT(Products.prod_id) AS num_products
FROM Vendors
LEFT OUTER JOIN Products ON Vendors.vend_id = Products.vend_id
GROUP BY Vendors.vend_id
ORDER BY Vendors.vend_id;

--Q7
--(a)
SELECT prod_id, quantity
FROM OrderItems
WHERE quantity = 100
UNION
SELECT prod_id, quantity
FROM OrderItems
WHERE prod_id IN ('BNBG01', 'BNBG02')
ORDER BY prod_id;

--(b)
SELECT prod_id, quantity
FROM OrderItems
WHERE quantity = 100 OR prod_id IN ('BNBG01', 'BNBG02')
ORDER BY prod_id;

--Q8
SELECT Customers.cust_name, SUM(OrderItems.quantity * OrderItems.item_price) AS total_price
FROM Customers, Orders, OrderItems
WHERE Customers.cust_id = Orders.cust_id
AND Orders.order_num = OrderItems.order_num
GROUP BY Customers.cust_name
HAVING SUM(OrderItems.quantity * OrderItems.item_price) >= 1000
ORDER BY Customers.cust_name;
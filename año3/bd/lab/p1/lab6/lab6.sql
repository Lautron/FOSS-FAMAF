USE classicmodels;

-- -- 1)
-- SELECT
--     o.city,
--     COUNT(e.employeenumber) AS emp_num
-- FROM employees AS e INNER JOIN offices AS o
--     ON e.officecode = o.officecode
-- GROUP BY o.officecode
-- ORDER BY emp_num DESC
-- LIMIT 1;

-- -- 2)
--
-- DROP VIEW IF EXISTS orders_by_office;
-- CREATE VIEW orders_by_office AS (
--     SELECT
--         offices.officecode,
--         o.ordernumber
--     FROM orders AS o INNER JOIN customers AS c
--         ON o.customernumber = c.customernumber
--     INNER JOIN employees AS e
--         ON c.salesrepemployeenumber = e.employeenumber
--     INNER JOIN offices
--         ON e.officecode = offices.officecode
-- );
--
-- -- 2)a)
-- WITH order_count_by_office AS (
--     SELECT COUNT(obo.ordernumber) AS order_count
--     FROM orders_by_office AS obo
--     GROUP BY obo.officecode
-- )
--
-- SELECT AVG(oc.order_count)
-- FROM order_count_by_office AS oc;
--
-- -- 2)b)
--
-- WITH order_quantity_per_office AS (
--     SELECT
--         obo.officecode,
--         SUM(od.quantityordered) AS total_quantity
--     FROM orders_by_office AS obo INNER JOIN orderdetails AS od
--         ON obo.ordernumber = od.ordernumber
--     GROUP BY obo.officecode
-- )
--
-- SELECT *
-- FROM order_quantity_per_office AS oqpo
-- ORDER BY oqpo.total_quantity DESC
-- LIMIT 1;

-- -- 3)
-- SELECT
--     MONTHNAME(p.paymentdate) AS month,
--     AVG(p.amount),
--     MAX(p.amount),
--     MIN(p.amount)
-- FROM payments AS p
-- GROUP BY month;

-- -- 4)
-- SELECT c.creditlimit, c.customerNumber
-- FROM customers c;
--
-- DROP PROCEDURE IF EXISTS update_credit;
-- CREATE PROCEDURE update_credit (IN customer_id INT, IN new_limit INT) BEGIN
--     UPDATE customers c
--     SET c.creditlimit = new_limit
--     WHERE c.customerNumber = customer_id;
-- END;
--
-- -- test
-- START TRANSACTION;
--     SELECT c.creditlimit, c.customerNumber
--     FROM customers AS c
--     WHERE c.customerNumber = 168;
--
--     CALL update_credit(168, 1000);
--
--     SELECT c.creditlimit, c.customerNumber
--     FROM customers AS c
--     WHERE c.customerNumber = 168;
-- ROLLBACK;

-- -- 5)
-- DROP VIEW IF EXISTS premium_customers;
-- CREATE VIEW premium_customers AS (
--     SELECT
--         c.customername,
--         c.city,
--         SUM(p.amount) AS total_spent
--     FROM customers AS c INNER JOIN payments AS p
--         ON c.customernumber = p.customernumber
--     GROUP BY c.customernumber
--     ORDER BY total_spent DESC
--     LIMIT 10
-- );

-- 6)
DROP FUNCTION IF EXISTS employee_of_the_month;
CREATE FUNCTION employee_of_the_month(month INT, year INT) RETURNS VARCHAR(100) READS SQL DATA
BEGIN
DECLARE best_employee VARCHAR(100);
SELECT CONCAT_WS(" ", e.firstname, e.lastname) INTO best_employee
FROM orders AS o INNER JOIN customers AS c
    ON o.customernumber = c.customernumber
INNER JOIN employees AS e
    ON c.salesrepemployeenumber = e.employeenumber
WHERE MONTH(o.orderdate) = month AND YEAR(o.orderdate) = year
GROUP BY e.employeenumber
ORDER BY COUNT(o.ordernumber) DESC
LIMIT 1;

RETURN best_employee;
END;

SELECT employee_of_the_month(1, 2003) AS mejor_empleado;

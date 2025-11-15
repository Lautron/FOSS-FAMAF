USE airbnb_like_db;

-- 1) OK
SELECT
    p.name,
    COUNT(r.id) AS review_count
FROM properties AS p INNER JOIN reviews AS r
    ON p.id = r.property_id
WHERE YEAR(TIMESTAMP(r.created_at)) = 2024
GROUP BY p.id
ORDER BY review_count DESC
LIMIT 7;

-- 2) OK
SELECT
    p.name,
    (DATEDIFF(b.check_out, b.check_in) * p.price_per_night) AS total_price
FROM properties AS p INNER JOIN bookings AS b
    ON p.id = b.property_id;

-- 3) OK
SELECT u.name, SUM(p.amount) AS total_payments
FROM users AS u INNER JOIN bookings AS b
    ON u.id = b.user_id
INNER JOIN payments AS p
    ON b.id = p.booking_id
GROUP BY u.id
ORDER BY total_payments desc
LIMIT 10;

-- 4) OK
DROP TRIGGER IF EXISTS notify_host_after_booking;
CREATE TRIGGER notify_host_after_booking AFTER INSERT
ON bookings FOR EACH ROW
BEGIN
INSERT INTO messages (sender_id, receiver_id, property_id, content)
SELECT
    new.user_id,
    p.owner_id,
    p.id,
    (SELECT "Se ha hecho una nueva reserva")
FROM properties AS p
WHERE new.property_id = p.id;
END;


-- 5) OK
DROP PROCEDURE IF EXISTS add_new_booking;
CREATE PROCEDURE add_new_booking (IN property_id INT, IN user_id INT, IN check_in DATE, IN check_out DATE) BEGIN
    -- Profe Ramiro dijo que no hace falta calcular total_price
    -- DONE: Check availability
    -- Aclaracion: me quedé sin tiempo para pulirlo bien
    IF EXISTS ( SELECT 1
    FROM property_availability pa
    WHERE pa.property_id = property_id
        AND pa.status = 'available'
        AND check_in >= pa.available_from
        AND check_out <= pa.available_to)
    THEN
        INSERT INTO bookings (property_id, user_id, check_in, check_out, total_price, status)
            VALUES(property_id, user_id, check_in, check_out, 0, "confirmed");
        INSERT INTO property_availability (property_id, available_from, available_to, status)
            VALUES(property_id, check_out, check_in, "reserved");
        -- No me dio el tiempo para poner bien el property_availability
    END IF;
END;

-- TEST repeated booking OK
START TRANSACTION;
    SELECT *
    FROM bookings b
    WHERE b.property_id = 1619;

    CALL add_new_booking(1619, 1747, "2024-11-29", "2024-12-12");

    SELECT *
    FROM bookings b
    WHERE b.property_id = 1619;
ROLLBACK;

-- TEST new booking OK
START TRANSACTION;

    SELECT *
    FROM property_availability b
    WHERE b.property_id = 1619;

    CALL add_new_booking(1619, 1747, "2024-10-02", "2024-10-15");

    SELECT *
    FROM bookings b
    WHERE b.property_id = 1619;
    --
    SELECT *
    FROM property_availability b
    WHERE b.property_id = 1619;
ROLLBACK;

-- TEST new message OK
START TRANSACTION;
    SELECT *
    FROM messages m
    WHERE m.property_id = 1619;

    CALL add_new_booking(1619, 1747, "2024-10-15", "2024-10-20");

    SELECT *
    FROM messages m
    WHERE m.property_id = 1619;
ROLLBACK;

-- -- 6) OK
CREATE ROLE IF NOT EXISTS admin;

GRANT INSERT
ON properties
TO admin;

GRANT UPDATE (status)
ON property_availability
TO admin;

-- TEST
SHOW GRANTS FOR admin;

-- 7)
-- Esto no contradice la propiedad de durabilidad de ACID ya que esta propiedad
-- no implica que los datos jamas seran cambiados (en el caso de que se agreguen nuevos datos)
-- ,si no que hay que interpretarlo como que si se cargan nuevos datos, estos seran guardados
-- (y son recuperables) por más que haya fallos en el sistema. Lo cual es independiente
-- de si se estan añadiendo datos totalmente nuevos o si se estan actualizando datos viejos.

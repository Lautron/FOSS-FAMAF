USE world;
-- 1)

SELECT
    ci.name AS city,
    co.name AS country
FROM city AS ci INNER JOIN country AS co ON ci.countrycode = co.code
WHERE co.code IN (
    SELECT country.code
    FROM country
    WHERE country.population > 10000
);

-- 2)
SELECT
    name,
    population
FROM city
WHERE population > (
    SELECT avg(population) AS avg_pop
    FROM city
);

-- 3)
SELECT
    city.name,
    city.population
FROM city INNER JOIN country
    ON city.countrycode = country.code
WHERE
    country.continent != 'Asia'
    AND city.population >= some(
        SELECT country.population
        FROM country
        WHERE country.continent = 'Asia'
    );

-- 4)

SELECT
    country.name,
    countrylanguage.language,
    countrylanguage.percentage
FROM country INNER JOIN countrylanguage
    ON
        country.code = countrylanguage.countrycode
        AND countrylanguage.isofficial = 'F'
WHERE countrylanguage.percentage > all(
    SELECT cl.percentage
    FROM countrylanguage AS cl
    WHERE cl.countrycode = country.code AND cl.isofficial = 'T'
);

-- 5)a)
SELECT
    c.region,
    c.name
FROM country AS c
WHERE c.surfacearea < 1000 AND EXISTS (
    SELECT ci.population
    FROM city AS ci
    WHERE ci.countrycode = c.code AND ci.population > 100000
);

-- 5)b)
SELECT
    c.region,
    c.name
FROM country AS c INNER JOIN city AS ci
    ON
        c.code = ci.countrycode
        AND c.surfacearea < 1000 AND ci.population > 100000;

-- 6)a) Consultas escalares
SELECT
    co.name,
    (
        SELECT max(city.population)
        FROM city
        WHERE city.countrycode = co.code
    ) AS most_populated_city
FROM country AS co;

-- 6)b) Agrupacion
SELECT
    co.name,
    max(ci.population) AS most_populated_city
FROM country AS co LEFT JOIN city AS ci
    ON co.code = ci.countrycode
GROUP BY co.name;

-- 7)
SELECT
    co.name,
    cl.language,
    cl.percentage
FROM country AS co LEFT JOIN countrylanguage AS cl
    ON co.code = cl.countrycode AND cl.isofficial = 'F'
WHERE cl.percentage > (
    SELECT avg(ol.percentage)
    FROM countrylanguage AS ol
    WHERE ol.isofficial = 'T' AND ol.countrycode = co.code
);

-- 8)
SELECT
    co.continent,
    sum(co.population) AS population
FROM country AS co
GROUP BY co.continent
ORDER BY population DESC;

-- 9)
SELECT
    co.continent,
    avg(co.lifeexpectancy) AS avg_life
FROM country AS co
GROUP BY co.continent
HAVING avg_life >= 40 AND avg_life <= 70;

-- 10)
SELECT
    c.continent,
    max(c.population) AS max_pop,
    min(c.population) AS min_pop,
    avg(c.population) AS avg_pop,
    sum(c.population) AS total_pop
FROM country AS c
GROUP BY c.continent;


/* PARTE 2 */

-- 6)a) Consultas escalares si se puede
SELECT
    co.name,
    (
        SELECT city.name
        FROM city
        WHERE city.countrycode = co.code
        ORDER BY city.population DESC
        LIMIT 1
    ) AS city,
    (
        SELECT max(city.population)
        FROM city
        WHERE city.countrycode = co.code
    ) AS city_pop
FROM country AS co;

-- 6)b) Con agrupaciones no se puede sin usar un join adicional y consultas anidadas

USE `world`;

SELECT city.name AS city, country.name AS country, country.region, country.governmentform
FROM city INNER JOIN country
ON city.countrycode = country.code
ORDER BY city.population desc
LIMIT 10;

-- INFO: When to use LEFT or RIGHT join?
-- When you can have null values. ie. If a country doesn't need to have a capital
-- SELECT country.name AS country, city.name AS city, country.population
-- FROM country LEFT JOIN city
-- ON country.capital = city.id
-- ORDER BY country.population asc
-- LIMIT 10;

-- SELECT country.name, country.continent, countrylanguage.language
-- FROM country INNER JOIN countrylanguage
-- ON country.code = countrylanguage.countrycode
-- AND countrylanguage.isofficial = 'T';

-- SELECT country.name as country, city.name as city, country.surfacearea
-- FROM country INNER JOIN city
-- ON country.capital = city.id
-- ORDER BY country.surfacearea desc
-- LIMIT 20;

-- SELECT
--     city.name as city,
--     countrylanguage.language as official_language,
--     countrylanguage.percentage
-- FROM city INNER JOIN countrylanguage
-- ON city.countrycode = countrylanguage.countrycode
-- AND countrylanguage.isofficial = 'T'
-- ORDER BY city.population asc;

-- (SELECT name, population
-- FROM country
-- WHERE population > 100
-- ORDER BY population desc
-- LIMIT 10
-- ) UNION (
-- SELECT name, population
-- FROM country
-- WHERE population > 100
-- ORDER BY population asc
-- LIMIT 10
-- );

-- INFO: you can't use joins with intersect it seems
-- (
-- SELECT country.name
-- FROM country, countrylanguage
-- WHERE country.Code = countrylanguage.CountryCode
-- AND countrylanguage.IsOfficial = 'T' AND countrylanguage.Language = "English"
-- ) INTERSECT (
-- SELECT country.name
-- FROM country, countrylanguage
-- WHERE country.Code = countrylanguage.CountryCode
-- AND countrylanguage.IsOfficial = 'T' AND countrylanguage.Language = "French"
-- );

-- (
-- SELECT country.name
-- FROM country, countrylanguage
-- WHERE country.Code = countrylanguage.CountryCode AND countrylanguage.Language = "English"
-- ) EXCEPT (
-- SELECT country.name
-- FROM country, countrylanguage
-- WHERE country.Code = countrylanguage.CountryCode AND countrylanguage.Language = "Spanish"
-- )

-- Parte 2:
-- 1) Tener run predicado adicional en el ON es lo mismo que añadir un where

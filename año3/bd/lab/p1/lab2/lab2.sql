
CREATE TABLE city (
    ID INT NOT NULL AUTO_INCREMENT,
    Name VARCHAR(100),
    CountryCode VARCHAR(100),
    District VARCHAR(100),
    Population INT,
    PRIMARY KEY (ID),
    FOREIGN KEY (CountryCode) REFERENCES country(Code)
);

CREATE TABLE countrylanguage (
    CountryCode int,
    Language VARCHAR(100),
    IsOfficial CHAR(1),
    Percentage int,
    PRIMARY KEY (CountryCode, Language),
    FOREIGN KEY (CountryCode) REFERENCES country(Code)
);

CREATE TABLE country (
    Code VARCHAR(100),
    Continent VARCHAR(100),
    Region VARCHAR(100),
    SurfaceArea INT,
    IndepYear INT,
    Population INT,
    LifeExpectancy INT,
    GNP INT,
    GNPOld INT,
    SurfaceArea INT,
    LocalName VARCHAR(100),
    GovernmentForm VARCHAR(100),
    HeadOfState VARCHAR(100),
    Capital VARCHAR(100),
    Code2 VARCHAR(100),
);






SELECT description FROM crime_scene_reports
WHERE day=28 AND year=2021 AND month=7 AND street='Humphrey Street';

-- Theft took place in the bakery at 10:15AM

SELECT transcript FROM interviews
WHERE transcript LIKE '%bakery%';

SELECT license_plate FROM bakery_security_logs
WHERE day=28 AND year=2021 AND month=7 AND hour=10 AND minute > 15 AND minute < 26 ;


-- The Thief called the somone after the Theft and talked for less than a minute
SELECT name FROM people
WHERE phone_number LIKE (
SELECT receiver FROM phone_calls
WHERE day=28 AND year=2021 AND month=7 AND duration < 60
AND caller LIKE (SELECT phone_number FROM people WHERE name ='Bruce')
);

--THE FLIGHT the thief took to escape the city

SELECT destination_airport_id FROM flights
INNER JOIN airports ON airports.id=origin_airport_id
WHERE city='Fiftyville' AND day=29 AND year=2021 AND month=7 ORDER BY hour LIMIT 1;

SELECT city FROM airports
INNER JOIN flights ON airports.id=flights.destination_airport_id
WHERE airports.id LIKE (SELECT destination_airport_id FROM flights
INNER JOIN airports ON airports.id=origin_airport_id
WHERE city='Fiftyville' AND day=29 AND year=2021 AND month=7 ORDER BY hour LIMIT 1)LIMIT 1;




SELECT name FROM people
WHERE phone_number IN(SELECT caller FROM phone_calls
WHERE day=28 AND year=2021 AND month=7 AND duration < 60)
AND
passport_number IN (SELECT passport_number FROM passengers
INNER JOIN flights ON passengers.flight_id=flights.id
WHERE flights.id=36)
AND
license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE day=28 AND year=2021 AND month=7 AND hour=10 AND minute > 15 AND minute < 26)
AND
id IN (SELECT person_id FROM bank_accounts
INNER JOIN atm_transactions ON bank_accounts.account_number=atm_transactions.account_number
WHERE day=28 AND year=2021 AND month=7 AND atm_location='Leggett Street' AND transaction_type='withdraw');






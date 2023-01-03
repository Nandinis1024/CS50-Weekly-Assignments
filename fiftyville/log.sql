-- Keep a log of any SQL queries you execute as you solve the mystery.
--QUERY 1: To read the description of the crime
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2021 AND street = 'Humphrey Street';
--time of the crime: 10:15 am
--QUERY 2: To read the interview transcripts for the crime
SELECT * FROM interviews  WHERE day = 28 AND month = 7 AND year = 2021;
--QUERY 3: To check the bakery_security_logs within 10:15-10:25 time frame
SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day= 28 AND hour = 10 AND minute BETWEEN 15 AND 25;
--QUERY 4: To check the atm_transaction
SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
--QUERY 5:To check the bank accounts to obtain the people_id
SELECT * FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw');
--QUERY 6:use those id in people table to obtain the license_plate
SELECT * FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(
    SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'

));

--QUERY 7: Tally the license plate from the bakery's record
SELECT license_plate FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(
    SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'

));
--suspects: Iman, Luca, Diana, Bruce
--QUERY 8: Call details of the 4 suspects
SELECT * FROM phone_calls WHERE caller IN ('(829) 555-5269', '(389) 555-5198', '(770) 555-1861', '(367) 555-5533') AND year = 2021 AND month = 7 AND day = 28 AND duration <= 60;
--two suspects remain Diana and Bruce
--QUERY 9: Look for the details of the eariest flight on 29
SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute;
--QUERY 10: determine the city
SELECT * FROM airports WHERE id = 4;
--THE CITY IS NEW YORK CITY
--QUERY 11 passenger details for the flight
SELECT * FROM passengers WHERE flight_id = 36;

SELECT * FROM people
JOIN
WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(
    SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'

));









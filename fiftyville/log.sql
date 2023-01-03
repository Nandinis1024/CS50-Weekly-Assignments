-- Keep a log of any SQL queries you execute as you solve the mystery.
--QUERY 1: To read the description of the crime
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2021 AND street = 'Humphrey Street';
--time of the crime: 10:15 am
--QUERY 2: To read the interview transcripts for the crime
SELECT * FROM interviews  WHERE day = 28 AND month = 7 AND year = 2021;
--QUERY 3: To check the bakery_security_logs within 10:15-10:25 time frame
SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day= 28 AND hour = 10
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
SELECT license_plate FROM bakery_security_logs
JOIN 

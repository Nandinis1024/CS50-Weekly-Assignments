-- Keep a log of any SQL queries you execute as you solve the mystery.
--QUERY 1: To read the description of the crime
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2021 AND street = 'Humphrey Street';
--time of the crime: 10:15 am
--QUERY 2: To read the interview transcripts for the crime
SELECT * FROM interviews  WHERE day = 28 AND month = 7 AND year = 2021;


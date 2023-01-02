SELECT name FROM people WHERE id IN
(
    SELECT people_id FROM stars WHERE movie_id IN
    (
        SELECT id FROM movies WHERE title = 'Toy Story'
    )
);
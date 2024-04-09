SELECT title FROM movies
INNER JOIN stars ON stars.movie_id=movies.id
INNER JOIN people ON people.id=stars.person_id
WHERE name='Bradley Cooper'
INTERSECT
SELECT title FROM movies
INNER JOIN stars ON stars.movie_id=movies.id
INNER JOIN people ON people.id=stars.person_id
WHERE name='Jennifer Lawrence';

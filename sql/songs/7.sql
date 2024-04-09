SELECT SUM(energy) / COUNT(energy) as avg_energy_Drake FROM songs
WHERE artist_id = (SELECT id FROM artists WHERE name like 'Drake');
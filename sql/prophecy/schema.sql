CREATE TABLE students(
    id INTEGER,
    student_name TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE houses(
    id INTEGER,
    house_name TEXT NOT NULL,
    head TEXT NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE info(
    students_id INTEGER,
    houses_id INTEGER,
    FOREIGN KEY (students_id) REFERENCES students(id),
    FOREIGN KEY (houses_id) REFERENCES houses(id)
);

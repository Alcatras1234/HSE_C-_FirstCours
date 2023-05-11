#include "sort_students.h"

int CompareDate(Student student, Student student1);
int CompareName(Student student, Student student1);
int CompareStudent(Student& student, Student& student1, SortKind kind);
void SortStudents(std::vector<Student>& students, SortKind sort_kind) {
    int vec_size = static_cast<int>(students.size());
    for (int i = 0; i < vec_size; ++i) {
        for (int j = i + 1; j < vec_size; ++j) {
            if (CompareStudent(students[i], students[j], sort_kind) > 0) {
                Student time = students[j];
                students[j] = students[i];
                students[i] = time;
            }
        }
    }
}
int CompareStudent(Student& student1, Student& student2, SortKind sort_kind) {
    int compareres = 0;
    if (sort_kind == SortKind::Date) {
        compareres = CompareDate(student1, student2);
    } else {
        compareres = CompareName(student1, student2);
    }
    return compareres;
}
int CompareDate(Student student, Student student1) {
    if (student.birth_date.year > student1.birth_date.year) {
        return 1;
    } else if (student.birth_date.year < student1.birth_date.year) {
        return -1;
    } else if (student.birth_date.year == student1.birth_date.year) {
        if (student.birth_date.month > student1.birth_date.month) {
            return 1;
        } else if (student.birth_date.month < student1.birth_date.month) {
            return -1;
        } else if (student.birth_date.month == student1.birth_date.month) {
            if (student.birth_date.day > student1.birth_date.day) {
                return 1;
            } else if (student.birth_date.day < student1.birth_date.day) {
                return -1;
            } else if (student.birth_date.day == student1.birth_date.day) {
                return CompareName(student, student1);
            }
        }
    }
    return 0;
}
int CompareName(Student student, Student student1) {
    if (student.last_name > student1.last_name) {
        return 1;
    }
    if (student.last_name < student1.last_name) {
        return -1;
    }
    if (student.name > student1.name) {
        return 1;
    }
    if (student.name < student1.name) {
        return -1;
    }
    return 0;
}

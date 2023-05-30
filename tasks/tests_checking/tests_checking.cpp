#include "tests_checking.h"

#include <deque>

std::vector<std::string> StudentsOrder(const std::vector<StudentAction>& student_actions,
                                       const std::vector<size_t>& queries) {
    std::deque<std::string> check_order;
    for (const StudentAction& student_action : student_actions) {
        if (student_action.side == Side::Top) {
            check_order.push_front(student_action.name);
        } else {
            check_order.push_back(student_action.name);
        }
    }

    std::vector<std::string> students_order(queries.size());

    for (size_t i = 0; i < students_order.size(); ++i) {
        students_order[i] = check_order[queries[i] - 1];
    }
    return students_order;
}
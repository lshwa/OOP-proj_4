//Assignment.cpp
#include "Assignment.h"

// 생성자: 과제의 제목, 마감 기한, 중요도를 초기화하고 완료 상태를 false로 설정
Assignment::Assignment(std::string title, std::string dueDate, int priority)
    : title(title), dueDate(dueDate), priority(priority), completed(false) {}

// 과제 수정 메서드: 제목, 마감 기한, 중요도를 변경
void Assignment::modifyAssignment(std::string title, std::string dueDate, int priority) {
    this->title = title;
    this->dueDate = dueDate;
    this->priority = priority;
}

// 과제를 완료 상태로 변경
void Assignment::markAsComplete() {
    completed = true;
}

// 과제를 미완료 상태로 변경
void Assignment::markAsIncomplete() {
    completed = false;
}

// Getter 메서드 구현
std::string Assignment::getTitle() const {
    return title;
}

std::string Assignment::getDueDate() const {
    return dueDate;
}

int Assignment::getPriority() const {
    return priority;
}

bool Assignment::isCompleted() const {
    return completed;
}

// 상태 출력 메서드: 완료 상태를 "완료" 또는 "미완료"로 반환
std::string Assignment::getStatus() const {
    return completed ? "완료" : "미완료";
}
//Assignment.h
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>

// 과제를 관리하는 클래스
class Assignment {
private:
    std::string title;     // 과제 제목
    std::string dueDate;   // 마감 기한
    int priority;          // 중요도 (1-5)
    bool completed;        // 완료 상태 (true: 완료, false: 미완료)

public:
    // 생성자
    Assignment(std::string title, std::string dueDate, int priority);

    // 과제 수정 메서드
    void modifyAssignment(std::string title, std::string dueDate, int priority);

    // 과제 완료 상태 처리 메서드
    void markAsComplete();
    void markAsIncomplete();

    // Getter 메서드
    std::string getTitle() const;
    std::string getDueDate() const;
    int getPriority() const;
    bool isCompleted() const;

    // 상태 출력 메서드
    std::string getStatus() const; // "완료" 또는 "미완료" 반환
};

#endif
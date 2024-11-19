#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Assignment.h"
#include "Schedule.h"
#include "Visualization.h"

// 사용자 관리 클래스
class User {
private:
    std::string name;                    // 사용자 이름
    std::vector<Assignment> assignments; // 과제 목록
    Schedule schedule;                   // 수업 일정
    Visualization visualization;         // 학습 기록 시각화

    // 과제 관리 관련 메서드
    void manageAssignments();
    void addAssignmentViaConsole();
    void listAssignments();
    void completeAssignment();

    // 학습 시간 관리 관련 메서드
    void manageStudyTime();
    void recordStudyTime();
    void showStudyTime();

    // 수업 일정 관리 관련 메서드
    void manageSchedule();

    // 학습 진척도 확인 관련 메서드
    

public:
    // 생성자
    User(std::string name);

    // 메인 메뉴 실행
    void runMainMenu();
};

#endif
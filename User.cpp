//User.cpp
#include "User.h"
#include <iostream>

// 생성자
User::User(std::string name) : name(name) {}

// 과제 목록 보기
void User::listAssignments() {
    if (assignments.empty()) {
        std::cout << "등록된 과제가 없습니다.\n";
    } else {
        std::cout << "\n--- 과제 목록 ---\n";
        for (size_t i = 0; i < assignments.size(); ++i) {
            std::cout << i + 1 << ". 제목: " << assignments[i].getTitle()
                      << ", 마감 기한: " << assignments[i].getDueDate()
                      << ", 중요도: " << assignments[i].getPriority()
                      << ", 상태: " << assignments[i].getStatus() << "\n";
        }
    }
}

// 학습 시간 기록
void User::recordStudyTime() {
    std::string date;
    int time;
    std::cout << "날짜를 입력하세요 (YYYY-MM-DD): ";
    std::cin >> date;
    std::cout << "학습 시간을 입력하세요 (분): ";
    std::cin >> time;

    visualization.addStudyData(date, time);
    std::cout << "학습 시간이 기록되었습니다.\n";
}

// 과제 완료 처리
void User::completeAssignment() {
    if (assignments.empty()) {
        std::cout << "완료 처리할 과제가 없습니다.\n";
        return;
    }

    listAssignments();
    int index = 0;
    std::cout << "완료 처리할 과제 번호를 입력하세요 (1부터 시작): ";
    std::cin >> index;

    if (index < 1 || index > static_cast<int>(assignments.size())) {
        std::cout << "잘못된 번호입니다.\n";
        return;
    }

    assignments[index - 1].markAsComplete();
    std::cout << "과제가 완료 처리되었습니다.\n";
}

// 과제 추가
void User::addAssignmentViaConsole() {
    std::string title, dueDate;
    int priority;
    std::cout << "과제 제목을 입력하세요: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "마감 기한을 입력하세요 (YYYY-MM-DD): ";
    std::cin >> dueDate;
    std::cout << "중요도를 입력하세요 (1-5): ";
    std::cin >> priority;

    assignments.emplace_back(title, dueDate, priority);
    std::cout << "과제가 추가되었습니다.\n";
}


// 메인 메뉴 실행
void User::runMainMenu() {
    bool running = true;
    while (running) {
        int choice = 0;
        std::cout << "\n--- 학습 관리 시스템 ---\n";
        std::cout << "1. 과제 관리\n";
        std::cout << "2. 학습 시간 관리\n";
        std::cout << "3. 수업 일정 관리\n";
        std::cout << "4. 학습 진척도 확인\n";
        std::cout << "5. 종료\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manageAssignments();
                break;
            case 2:
                manageStudyTime();
                break;
            case 3:
                manageSchedule();
                break;
            case 4:
                std::cout<<"학습 진척도 확인 기능은 아직 구현되지 않았습니다.\n";
                break;
            case 5:
                std::cout << "프로그램을 종료합니다.\n";
                running = false;
                break;
            default:
                std::cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
                break;
        }
    }
}

// 과제 관리 메뉴
void User::manageAssignments() {
    bool running = true;
    while (running) {
        int choice = 0;
        std::cout << "\n--- 과제 관리 ---\n";
        std::cout << "1. 과제 추가\n";
        std::cout << "2. 과제 목록 보기\n";
        std::cout << "3. 과제 완료 처리\n";
        std::cout << "4. 뒤로 가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addAssignmentViaConsole();
                break;
            case 2:
                listAssignments();
                break;
            case 3:
                completeAssignment();
                break;
            case 4:
                running = false;
                break;
            default:
                std::cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
                break;
        }
    }
}

// 학습 시간 관리 메뉴
void User::manageStudyTime() {
    bool running = true;
    while (running) {
        int choice = 0;
        std::cout << "\n--- 학습 시간 관리 ---\n";
        std::cout << "1. 학습 시간 기록\n";
        std::cout << "2. 학습 시간 확인\n";
        std::cout << "3. 뒤로 가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                recordStudyTime();
                break;
            case 2:
                showStudyTime();
                break;
            case 3:
                running = false;
                break;
            default:
                std::cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
                break;
        }
    }
}

// 수업 일정 관리 메뉴 
void User::manageSchedule() {
    bool running = true;
    while (running) {
        int choice = 0;
        std::cout << "\n--- 수업 일정 관리 ---\n";
        std::cout << "1. 일정 추가\n";
        std::cout << "2. 일정 보기\n";
        std::cout << "3. 일정 삭제\n";
        std::cout << "4. 뒤로 가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, start, end, day;
                std::cout << "과목명을 입력하세요: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "시작 시간을 입력하세요 (HH:MM): ";
                std::cin >> start;
                std::cout << "종료 시간을 입력하세요 (HH:MM): ";
                std::cin >> end;
                std::cout << "요일을 입력하세요 (예: 월요일): ";
                std::cin >> day;
                schedule.addSession(name, start, end, day);
                break;
            }
            case 2:
                schedule.listSessions();
                break;
            case 3: {
                std::string name;
                std::cout << "삭제할 수업의 과목명을 입력하세요: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                schedule.removeSession(name);
                break;
            }
            case 4:
                running = false;
                break;
            default:
                std::cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
                break;
        }
    }
}


// 학습 진척도 확인 메뉴 (더미 함수)
void User::showStudyTime() {
    bool running = true;
    while (running) {
        int choice = 0;
        std::cout << "\n--- 학습 진척도 확인 ---\n";
        std::cout << "1. 일간 진척도 보기\n";
        std::cout << "2. 주간 진척도 보기\n";
        std::cout << "3. 월간 진척도 보기\n";
        std::cout << "4. 뒤로 가기\n";
        std::cout << "선택: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string date;
                std::cout << "날짜를 입력하세요 (YYYY-MM-DD): ";
                std::cin >> date;
                visualization.showDailyStudyTime(date);
                break;
            }
            case 2: {
                std::string date;
                std::cout << "주간 학습 진척도를 확인할 날짜를 입력하세요 (YYYY-MM-DD): ";
                std::cin >> date;
                visualization.showWeeklyStudyTime(date);
                break;
            }
            case 3: {
                std::string month;
                std::cout << "월을 입력하세요 (YYYY-MM): ";
                std::cin >> month;
                visualization.showMonthlyStudyTime(month);
                break;
            }
            case 4:
                running = false;
                break;
            default:
                std::cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
                break;
        }
    }
}
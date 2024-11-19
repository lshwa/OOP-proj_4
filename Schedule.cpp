//Schedule.cpp
#include "Schedule.h"
#include <iostream>

// 수업 추가
void Schedule::addSession(const std::string& name, const std::string& start, 
                          const std::string& end, const std::string& day) {
    sessions.emplace_back(name, start, end, day);
    std::cout << "수업이 추가되었습니다: " << name << " (" << day << ", " << start 
              << " ~ " << end << ")\n";
}
/*
예외처리
1. 수업 중인 시간에 수업이 들어온 경우에 대한 처리
*/

// 수업 삭제
bool Schedule::removeSession(const std::string& name) {
    for (auto it = sessions.begin(); it != sessions.end(); ++it) {
        if (it->subjectName == name) {
            sessions.erase(it);
            std::cout << "수업이 삭제되었습니다: " << name << "\n";
            return true;
        }
    }
    std::cout << "삭제할 수업을 찾을 수 없습니다: " << name << "\n";
    return false;
}

// 수업 목록 보기
void Schedule::listSessions() const {
    if (sessions.empty()) {
        std::cout << "등록된 수업이 없습니다.\n";
        return;
    }

    std::cout << "\n--- 수업 목록 ---\n";
    for (const auto& session : sessions) {
        std::cout << "과목: " << session.subjectName << ", 요일: " << session.dayOfWeek
                  << ", 시간: " << session.startTime << " ~ " << session.endTime << "\n";
    }
}
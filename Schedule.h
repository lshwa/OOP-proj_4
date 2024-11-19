//Schedule.h
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>

class Schedule {
private:
    struct ClassSession {
        std::string subjectName;  // 과목명
        std::string startTime;    // 시작 시간 (HH:MM)
        std::string endTime;      // 종료 시간 (HH:MM)
        std::string dayOfWeek;    // 요일 (예: 월요일)

        // 생성자
        ClassSession(std::string name, std::string start, std::string end, std::string day)
            : subjectName(name), startTime(start), endTime(end), dayOfWeek(day) {}
    };

    std::vector<ClassSession> sessions; // 등록된 수업 목록

public:
    // 수업 추가
    void addSession(const std::string& name, const std::string& start, 
                    const std::string& end, const std::string& day);

    // 수업 삭제
    bool removeSession(const std::string& name);

    // 수업 목록 보기
    void listSessions() const;
};

#endif
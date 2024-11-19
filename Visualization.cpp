//Visulization.cpp
#include "Visualization.h"
#include <iostream>
#include <map>
#include <sstream>

// 생성자
Visualization::Visualization() {}

// 학습 데이터 추가
void Visualization::addStudyData(const std::string& date, int time) {
    studyHistory.push_back({date, time});
}

// 특정 날짜의 학습 시간 확인
void Visualization::showDailyStudyTime(const std::string& date) const {
    int totalTime = 0;
    for (const auto& record : studyHistory) {
        if (record.date == date) {
            totalTime += record.studyTime;
        }
    }
    std::cout << date << "의 학습 시간: " << totalTime << "분\n";
}

// 특정 주의 학습 시간 확인
void Visualization::showWeeklyStudyTime(const std::string& date) const {
    int weekNumber = getWeekNumber(date);
    int totalTime = 0;

    for (const auto& record : studyHistory) {
        if (getWeekNumber(record.date) == weekNumber) {
            totalTime += record.studyTime;
        }
    }
    std::cout << date << "가 포함된 주의 학습 시간: " << totalTime << "분\n";
}

// 특정 월의 학습 시간 확인
void Visualization::showMonthlyStudyTime(const std::string& month) const {
    int totalTime = 0;
    for (const auto& record : studyHistory) {
        if (getMonth(record.date) == month) {
            totalTime += record.studyTime;
        }
    }
    std::cout << month << "의 학습 시간: " << totalTime << "분\n";
}

// 주 번호 계산 (YYYY-MM-DD 형식 날짜 입력)
int Visualization::getWeekNumber(const std::string& date) const {
    int year, month, day;
    std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    // 간단히 날짜의 (일수 + 월 * 30) / 7 계산
    return (day + (month - 1) * 30) / 7;
}

// 월 추출 (YYYY-MM-DD 형식 날짜 입력)
std::string Visualization::getMonth(const std::string& date) const {
    return date.substr(0, 7); // YYYY-MM
}